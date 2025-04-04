/*
 * Game.cpp
 *
 *  Created on: 31 de mar. de 2025
 *      Author: luc
 */

#include "Game.h"

#include <SDL_image.h>
#include <SDL_mixer.h>
#include <MessageBox.h>

#include <iostream>

using std::string;

Game* Game::instance = nullptr;

Game::Game(const string& title, int width, int height) {
	if(instance != nullptr) {
		std::cout << "Game já possui instância";
		abort();
	}

	instance = this;

	int sdlInitResult = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	if(sdlInitResult != 0) {
		std::string mensagem = std::string("Erro ao iniciar SDL: ") + SDL_GetError();
		MessageBox::ShowError(mensagem, window);
	}

	int imgInitResult = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
	if(imgInitResult == 0) {
		std::string mensagem = std::string("Erro ao iniciar SDL_Image: ") + SDL_GetError();
		MessageBox::ShowError(mensagem, window);
	}

	Mix_Init(MIX_INIT_MP3);
	int mixInitResult = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	if(mixInitResult != 0) {
		std::string mensagem = std::string("Erro ao iniciar SDL_Mixer: ") + SDL_GetError();
		MessageBox::ShowError(mensagem, window);
	}
	Mix_AllocateChannels(8);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if(window == nullptr) {
		std::string mensagem = std::string("Erro ao criar SDL_Window: ") + SDL_GetError();
		MessageBox::ShowError(mensagem, window);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr) {
		std::string mensagem = std::string("Erro ao criar renderizador: ") + SDL_GetError();
		MessageBox::ShowError(mensagem, window);
	}

	state = new State();
}

Game::~Game() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	Mix_CloseAudio();
	Mix_Quit();

	IMG_Quit();

	SDL_Quit();
}

Game& Game::GetInstance() {
	if(instance == nullptr) {
		instance = new Game("Lucas Almeida - 242039390", 1200, 900);
	}
	return *instance;
}

State& Game::GetState() {
	return *state;
}

SDL_Renderer* Game::GetRenderer() {
	return renderer;
}

void Game::Run() {
	while(!state->QuitRequested()) {
		state->Update(0);
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}
