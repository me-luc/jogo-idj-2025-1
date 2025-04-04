/*
 * State.cpp
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#include "State.h"
#include <Sprite.h>

State::State() {
	quitRequested = false;
	string filePath = "Recursos/img/Background.png";
	bg = new Sprite(filePath);
}

State::~State() {
}

bool State::QuitRequested() {
	return this->quitRequested;
}

void State::Update(float dt) {
	this->quitRequested = SDL_QuitRequested();
}

void State::Render() {
	this->bg->Render(0,0);
}
