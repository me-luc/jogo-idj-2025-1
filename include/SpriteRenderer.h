/*
 * SpriteRenderer.h
 *
 *  Created on: 14 de abr. de 2025
 *      Author: luc
 */

#ifndef SRC_SPRITERENDERER_H_
#define SRC_SPRITERENDERER_H_

#include <GameObject.h>
#include <Component.h>
#include <Sprite.h>
#include <string>

class SpriteRenderer : public Component  {
public:
	SpriteRenderer(GameObject& associated);
	SpriteRenderer(GameObject& associated, std::string file, int frameCountW = 1, int frameCountH = 1);
	virtual ~SpriteRenderer();
	void Open(std::string file);
	void SetFrame(int frameW, int frameH);
	void Update(float dt);
	void Render();
	bool Is(std::string type);
	void SetFrame(int frame);

private:
	Sprite sprite;
};

#endif /* SRC_SPRITERENDERER_H_ */
