/*
 * Component.h
 *
 *  Created on: 4 de abr. de 2025
 *      Author: luc
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

class GameObject;

class Component {
public:

	Component(GameObject& associatedObject);
	virtual ~Component();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
	virtual bool Is(std::string type) = 0;

protected:
	GameObject& associated;
};

#endif /* COMPONENT_H_ */
