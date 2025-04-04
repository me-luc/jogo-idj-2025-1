/*
 * Game.h
 *
 *  Created on: 31 de mar. de 2025
 *      Author: luc
 */

#ifndef GAME_H_
#define GAME_H_

#include <SDL.h>
#include <string>
#include <State.h>

class Game {
public:
	virtual ~Game();
	static Game& GetInstance();
	State& GetState();
	SDL_Renderer* GetRenderer();
	void Run();

private:
	Game(const std::string& title, int width, int height);
	SDL_Window* window;
	SDL_Renderer* renderer;
	static Game* instance;
	State* state;
};

#endif /* GAME_H_ */
