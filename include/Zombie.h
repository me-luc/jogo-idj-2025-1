/*
 * Zombie.h
 *
 *  Created on: 14 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_ZOMBIE_H_
#define SRC_ZOMBIE_H_

#include "GameObject.h"

class Zombie : public Component{
public:
	Zombie(GameObject& associated);
	virtual ~Zombie();
	void Damage(int damage);
	void Update(float dt);
	void Render();
	bool Is(std::string type);

private:
	int hitPoints;
};

#endif /* SRC_ZOMBIE_H_ */
