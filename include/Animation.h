/*
 * Animation.h
 *
 *  Created on: 14 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_ANIMATION_H_
#define SRC_ANIMATION_H_

class Animation {
public:
	Animation() : frameStart(0), frameEnd(0), frameTime(0) {}
	Animation(int frameStart, int frameEnd, int frameTime);
	virtual ~Animation();
	int frameStart;
	int frameEnd;
	int frameTime;
};

#endif /* SRC_ANIMATION_H_ */
