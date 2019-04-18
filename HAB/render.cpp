#include "render.h"

render::render()
{

}

render::~render()
{

}

void render::rendering(SDL_Renderer *renderer, sprite *spr[], const SDL_Rect* canvas, SDL_Surface *screen)
{
	SDL_RenderClear(renderer);
	if (sizeof(spr) > 0)
	{
		for (int i = 0; i < sizeof(spr); i++)
		{
			spr[i]->draw(screen);
			//SDL_RenderCopy(renderer, screen, canvas, canvas);
		}
	}
	SDL_RenderPresent(renderer);
}