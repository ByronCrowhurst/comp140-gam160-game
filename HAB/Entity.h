#pragma once
#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"
#include <sstream>


class Entity
{
public:
	Entity();
	~Entity();
private:

protected:
	sprite sprSheet;
	int spriteIndex;
};