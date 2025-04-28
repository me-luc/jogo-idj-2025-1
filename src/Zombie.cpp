/*
 * Zombie.cpp
 *
 *  Created on: 14 de abr. de 2025
 *      Author: luc
 */

#include "Zombie.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include <Animator.h>

Zombie::Zombie(GameObject& associated) : Component(associated) {
	hitPoints = 100;
	Animator* animator = new Animator(associated);
	SpriteRenderer* sprite = new SpriteRenderer(associated, "Recursos/img/Enemy.png", 3, 2);
	sprite->SetFrame(1);
	associated.AddComponent(sprite);
	associated.AddComponent(animator);

	Animation walking(0, 3, 10);
	Animation dead(5, 5, 0);

	animator->AddAnimation("walking", walking);
	animator->AddAnimation("dead", dead);

	animator->SetAnimation("walking");
}

Zombie::~Zombie() {
	// TODO Auto-generated destructor stub
}

void Zombie::Damage(int damage) {
	hitPoints -= damage;
	if (hitPoints < 0) {
		SpriteRenderer* sprite = dynamic_cast<SpriteRenderer*>(associated.GetComponent("SpriteRenderer"));
		if (sprite != nullptr) {
			sprite->SetFrame(5);
		}
	}
}

void Zombie::Update(float dt) {
	Damage(1);
}

void Zombie::Render() {
	// Render logic here if needed
}

bool Zombie::Is(std::string type) {
	if (type == "Zombie") {
		return true;
	}
	return false;
}
