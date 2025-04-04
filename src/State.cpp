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
	delete bg;
}

bool State::QuitRequested() {
	return quitRequested;
}

void State::Update(float dt) {
	quitRequested = SDL_QuitRequested();
}

void State::Render() {
	bg->Render(0,0);
}

void State::LoadAssets() {

}
