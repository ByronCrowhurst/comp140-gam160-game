#include "stdafx.h"
#include <iostream>
#include <SDL.h>
#include "sprite.h"
#include "input.h"
#include "update.h"
#include "render.h"

int main(int argc, char * argv[])
{
	int winPos = 100;
	int width = 600;
	int height = 600;
	const char* title = "Hot Air Balloon Racing";
	SDL_Window *window;
	window = SDL_CreateWindow(title, winPos, winPos, width, height, SDL_WINDOW_OPENGL);
	render renderLoop;
	input inputs;
	//update updateLoop;
	SDL_Rect canvas;
	SDL_Texture* recture = NULL;
	sprite bullet(0, 0, 32, 32, recture);
	SDL_Init(SDL_INIT_VIDEO);
	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, 32, 32);
	while (true)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				break;
			}
		}
		std::cout << "Rendering" << std::endl;
		inputs.Update(inputs.GetInput());
		//sprite* spritesToRender[] = input.ReturnObjectToRender();
		//renderLoop.rendering(renderer, bullet, &canvas);
	}
	return 0;
}