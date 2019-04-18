#pragma once

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
	sprite *spritesToDraw[];
};