#include "render.h"

render::render(const char *title, int winPos, int width, int height)
{
	int flags = 0;
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, winPos, winPos, width, height, SDL_WINDOW_OPENGL);
		screen = SDL_GetWindowSurface(window);
		screenRect = screen->clip_rect;
		renderer = SDL_CreateRenderer(window, -1, 1);
		if (window && renderer)
		{
			std::cout << "Renderer Created" << std::endl;
		}

	}
	//SDL_UpdateWindowSurface(window);
}

render::~render()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void render::rendering(std::vector<sprite*>& spr)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	for (sprite * s : spr)
	{
		s->draw(screen, screenRect);
	}
	//if (spr.size() != 0)
	//{
	//	if (spr.size() > 0)
	//	{
	//		for (int i = 0; i < spr.size(); i++)
	//		{
	//			spr.at(i).draw(screen, screenRect);
	//		}
	//	}
	//}
	SDL_RenderPresent(renderer);
}