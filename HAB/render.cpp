#include "render.h"

render::render()
{

}

render::~render()
{

}

void render::rendering(SDL_Renderer *renderer, std::vector<sprite*> spr, const SDL_Rect* canvas, SDL_Surface *screen)
{
	SDL_RenderClear(renderer);
	if (spr.size() != 0)
	{
		if (spr.size() > 0)
		{
			for (int i = 0; i < spr.size(); i++)
			{
				spr.at(i)->draw(screen);
				//SDL_RenderCopy(renderer, screen, canvas, canvas);
			}
		}
	}
	SDL_RenderPresent(renderer);
}