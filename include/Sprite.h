/*
 * Sprite.h
 *
 *  Created on: 1 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_SPRITE_H_
#define SRC_SPRITE_H_

#include <string>
#include <SDL.h>

class Sprite {
public:
	Sprite();
	Sprite(std::string file);
	virtual ~Sprite();
	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);
	int GetWidth();
	int GetHeight();
	bool IsOpen();

private:
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
};

#endif /* SRC_SPRITE_H_ */
