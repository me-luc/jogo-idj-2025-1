/*
 * GameObject.cpp
 *
 *  Created on: 4 de abr. de 2025
 *      Author: luc
 */

#include "GameObject.h"
#include <vector>
#include <algorithm>

GameObject::GameObject() {
	isDead = false;

}

GameObject::~GameObject() {
	for(int i = components.size() - 1; i >= 0; i--) {
		delete components[i];
	}
}

void GameObject::Update(float dt) {
	for(int i =  0; i < components.size(); i++) {
		components[i]->Update(dt);
	}
}

void GameObject::Render() {
	for(int i =  0; i < components.size(); i++) {
		components[i]->Render();
	}
}

bool GameObject::IsDead() {
	return isDead;
}

void GameObject::RequestDelete() {
	isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
	components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
	components.erase(std::remove(components.begin(), components.end(), cpt), components.end());
}

Component* GameObject::GetComponent(std::string type) {
	for (int i = 0; i < components.size(); i++) {
		if (components[i]->Is(type)) {
			return components[i];
		}
	}
	return nullptr;
}
