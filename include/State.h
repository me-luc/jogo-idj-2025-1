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
#include <GameObject.h>
#include <memory>

class State {
public:
	State();
	virtual ~State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();
	void AddObject(GameObject* go);

private:
	Music music;
	bool quitRequested;
	std::vector <std::unique_ptr<GameObject>> objectArray;
};


#endif /* SRC_STATE_H_ */
