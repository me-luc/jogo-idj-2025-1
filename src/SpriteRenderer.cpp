/*
 * SpriteRenderer.cpp
 *
 *  Created on: 14 de abr. de 2025
 *      Author: luc
 */

#include "SpriteRenderer.h"
#include <iostream>

SpriteRenderer::SpriteRenderer(GameObject& associated): Component(associated), sprite() {}

SpriteRenderer::SpriteRenderer(GameObject& associated, std::string file, int frameCountW, int frameCountH)
    : Component(associated), sprite(file, frameCountW, frameCountH) {
    
    associated.box.w = sprite.GetWidth();
    associated.box.h = sprite.GetHeight();

    sprite.SetFrame(0);
}

SpriteRenderer::~SpriteRenderer() {}


void SpriteRenderer::SetFrame(int frame) {
	sprite.SetFrame(frame);
}

void SpriteRenderer::Update(float dt) {
}

void SpriteRenderer::Render() {
	sprite.Render(associated.box.x, associated.box.y, associated.box.w, associated.box.h);
}

bool SpriteRenderer::Is(std::string type) {
	if (type == "SpriteRenderer") {
		return true;
	}
	return false;
}
