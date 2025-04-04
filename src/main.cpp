/*
 * main.cpp
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#include "main.h"
#include <Game.h>
#include <iostream>

int main(int argc, char* argv[]) {
	Game& game = Game::GetInstance();
	game.Run();
	return 0;
}

main ::~main() {
	// TODO Auto-generated destructor stub
}

