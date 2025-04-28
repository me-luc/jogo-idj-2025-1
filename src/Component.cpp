/*
 * Component.cpp
 *
 *  Created on: 4 de abr. de 2025
 *      Author: luc
 */

#include "Component.h"
#include <GameObject.h>

Component::Component(GameObject& associatedObject) : associated(associatedObject){
}

Component::~Component() {
}

