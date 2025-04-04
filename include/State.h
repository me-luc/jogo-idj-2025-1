/*
 * State.h
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include <Music.h>
#include <Sprite.h>

class State {
public:
	State();
	virtual ~State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();

private:
	Sprite* bg;
	Music music;
	bool quitRequested;
};


#endif /* SRC_STATE_H_ */
