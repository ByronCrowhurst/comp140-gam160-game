#pragma once

#include <vector>
#include "render.h"
#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"

class update
{
public:
	update();
	~update();
	sprite *objectsToRender();
	int objectSize();
	sprite *addSprite(sprite* spriteToAdd);
private:

protected:
	std::vector<sprite*> spriteToDraw;
};