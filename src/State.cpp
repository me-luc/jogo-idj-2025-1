/*
 * State.cpp
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#include "State.h"
#include <Sprite.h>
#include <SpriteRenderer.h>
#include <Zombie.h>

State::State() {
	quitRequested = false;

	GameObject* bgObject = new GameObject();
	SpriteRenderer* bgSprite = new SpriteRenderer(*bgObject, "Recursos/img/Background.png");
	bgObject->AddComponent(bgSprite);
	AddObject(bgObject);

	GameObject* zombieObject = new GameObject();
	zombieObject->AddComponent(new Zombie(*zombieObject));
	zombieObject->box.x = 600;
	zombieObject->box.y = 450;
	AddObject(zombieObject);
}

State::~State() {
	objectArray.clear();
}

bool State::QuitRequested() {
	return quitRequested;
}

void State::Update(float dt) {
	quitRequested = SDL_QuitRequested();

	for(int i =  0; i < objectArray.size(); i++) {
		objectArray[i]->Update(dt);
	}

	for(int i =  0; i < objectArray.size(); i++) {
		if(objectArray[i]->IsDead()) {
			objectArray.erase(objectArray.begin() + i);
		}
	}
}

void State::Render() {
	for(int i =  0; i < objectArray.size(); i++) {
		objectArray[i]->Render();
	}
}

void State::AddObject(GameObject* go) {
	objectArray.emplace_back(go);
}
void State::LoadAssets() {

}
