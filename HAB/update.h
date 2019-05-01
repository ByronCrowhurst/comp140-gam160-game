#pragma once

#include <vector>
#include <tuple>
#include "render.h"
#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"

class update
{
public:
	update();
	~update();
	void updates();
	sprite *objectsToRender();
	int objectSize();
	sprite *addSprite(sprite* spriteToAdd);
private:

protected:
	std::vector<sprite*> spriteToDraw;
};