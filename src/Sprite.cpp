/*
 * Sprite.cpp
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#include "Sprite.h"
#include <SDL_image.h>
#include <Game.h>
#include <MessageBox.h>
#include <iostream>
#include <string>


Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(std::string file, int frameCountW, int frameCountH) {
	texture = nullptr;
	this->frameCountW = frameCountW;
	this->frameCountH = frameCountH;
	Open(file);
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file) {
	if (texture != nullptr) {
	   SDL_DestroyTexture(texture);
	   texture = nullptr;
	}

	texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

	if(texture == nullptr) {
		std::string mensagem = std::string("Erro ao iniciar SDL_Texture: ") + SDL_GetError();
		std::cout << "Falha ao carregar: " << file << std::endl;
	} else {
		std::cout << "Carregado: " << file << std::endl;
	}

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.h = h;
	clipRect.w = w;
	clipRect.x = x;
	clipRect.y = y;
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
}

void Sprite::Render(int x, int y, int w, int h) {
	SDL_Rect dstRect = { x, y, GetWidth(), GetHeight()};
	SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect);
}

bool Sprite::IsOpen() {
	return texture != nullptr;
}

void Sprite::SetFrame(int frame) {
	int frameWidth = width / frameCountW;
	int frameHeight = height / frameCountH;

	int row = frame / frameCountW;
	int col = frame % frameCountW;

	int x = col * frameWidth;
	int y = row * frameHeight;

	SetClip(x, y, frameWidth, frameHeight);
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH) {
	this->frameCountW = frameCountW;
	this->frameCountH = frameCountH;
}
