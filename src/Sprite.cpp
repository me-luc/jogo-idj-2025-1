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

using std::string;

Sprite::Sprite() {
	texture = nullptr;
}

Sprite::Sprite(string file) {
	texture = nullptr;
	Open(file);
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

void Sprite::Open(string file) {
	if (texture != nullptr) {
	   SDL_DestroyTexture(texture);
	   texture = nullptr;
	}

	texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

	if(texture == nullptr) {
		string mensagem = string("Erro ao iniciar SDL_Texture: ") + SDL_GetError();
		MessageBox::ShowError(mensagem);
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

void Sprite::Render(int x, int y) {
	SDL_Rect dstRect = { x, y, GetWidth(), GetHeight()};
	SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect);
}

bool Sprite::IsOpen() {
	return texture != nullptr;
}
