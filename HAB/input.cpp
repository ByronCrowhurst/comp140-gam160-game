#include "input.h"

input::input()
{
	
}

input::~input()
{

}

void input::GetInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{

		}
		else if (e.type == SDL_QUIT)
		{
			break;
		}
	}
}

void input::Update()
{

}

