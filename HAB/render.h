#pragma once

#include <vector>
#include <iostream>
#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"

class render
{
public:
	render(const char *title, int winPos, int width, int height);
	~render();
	void rendering(std::vector<sprite*>& spr);
private:
	SDL_Window *window;
	SDL_Surface *screen;
	SDL_Renderer* renderer;
	SDL_Rect screenRect;
	bool fullScreen;
protected:

};