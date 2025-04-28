/*
 * Animation.cpp
 *
 *  Created on: 14 de abr. de 2025
 *      Author: luc
 */

#include "Animation.h"
#include "GameObject.h"

Animation::Animation(int frameStart, int frameEnd, int frameTime) {
	this->frameStart = frameStart;
	this->frameEnd = frameEnd;
	this->frameTime = frameTime;
}

Animation::~Animation() {
}

