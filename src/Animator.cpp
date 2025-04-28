/*
 * Animator.cpp
 *
 *  Created on: 15 de abr. de 2025
 *      Author: luc
 */

#include "Animator.h"
#include <SpriteRenderer.h>

Animator::Animator(GameObject& associated): Component(associated), frameStart(0), frameEnd(0), frameTime(0.0f), currentFrame(0), timeElapsed(0.0f) {
}

Animator::~Animator() {
	// TODO Auto-generated destructor stub
}

void Animator::Update(float dt) {
	if (frameTime != 0.0f) {
	        timeElapsed += dt;
	        if (timeElapsed > frameTime) {
	            currentFrame++;
	            timeElapsed -= frameTime;

	            if (currentFrame > frameEnd) {
	                currentFrame = frameStart;
	            }

	            SpriteRenderer* spriteRenderer = (SpriteRenderer*)associated.GetComponent("SpriteRenderer");
	            if (spriteRenderer != nullptr) {
	                spriteRenderer->SetFrame(currentFrame);
	            }
	        }
	    }
}

void Animator::Render() {
}

void Animator::SetAnimation(std::string name) {
	auto it = animations.find(name);
	    if (it != animations.end()) {
	        Animation anim = it->second;

	        frameStart = anim.frameStart;
	        frameEnd = anim.frameEnd;
	        frameTime = anim.frameTime;
	        currentFrame = frameStart;
	        timeElapsed = 0.0f;

	        SpriteRenderer* spriteRenderer = (SpriteRenderer*)associated.GetComponent("SpriteRenderer");
	        if (spriteRenderer != nullptr) {
	            spriteRenderer->SetFrame(currentFrame);
	        }
	    }
}

void Animator::AddAnimation(std::string name, Animation anim) {
    if (animations.find(name) == animations.end()) {
        animations[name] = anim;
    }
}

bool Animator::Is(std::string type) {
    return type == "Animator";  // Verifica se o tipo é "Animator"
}


