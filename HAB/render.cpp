#include "render.h"

render::render()
{

}

render::~render()
{

}

void render::rendering(SDL_Renderer *renderer, sprite* spr[], const SDL_Rect* canvas, int size)
{
	SDL_RenderClear(renderer);
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			SDL_RenderCopy(renderer, spr[i]->getTexture(), canvas, canvas);
		}
	}
	SDL_RenderPresent(renderer);
}