#pragma once

#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"

class render
{
public:
	render();
	~render();
	void rendering(SDL_Renderer *renderer, sprite *spr[], const SDL_Rect* canvas, SDL_Surface *screen);
private:

protected:

};