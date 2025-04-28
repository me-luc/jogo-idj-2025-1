/*
 * GameObject.h
 *
 *  Created on: 4 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_GAMEOBJECT_H_
#define SRC_GAMEOBJECT_H_

#include <vector>
#include <string>
#include <Component.h>
#include <Rect.h>

class GameObject {
public:
	GameObject();
	virtual ~GameObject();
	void Update(float dt);
	void Render();
	bool IsDead();
	void RequestDelete();
	void AddComponent(Component* cpt);
	void RemoveComponent(Component* cpt);
	Component* GetComponent(std::string type);
	Rect box;

private:
	std::vector <Component*> components;
	bool isDead;
};

#endif /* SRC_GAMEOBJECT_H_ */
