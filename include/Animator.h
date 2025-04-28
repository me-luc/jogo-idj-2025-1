/*
 * Animator.h
 *
 *  Created on: 15 de abr. de 2025
 *      Author: luc
 */

#ifndef ANIMATOR_H_
#define ANIMATOR_H_

#include "GameObject.h"
#include "Animation.h"
#include <unordered_map>

class Animator : public Component {
public:
	Animator(GameObject& associated);
	virtual ~Animator();
	void Update(float dt);
	void Render();
	bool Is(std::string type);
	void SetAnimation(std::string name);
	void AddAnimation(std::string name, Animation anim);

private:
	std::unordered_map<std::string, Animation> animations;
	int frameStart;
	int frameEnd;
	float frameTime;
	int currentFrame;
	float timeElapsed;
};

#endif /* ANIMATOR_H_ */
