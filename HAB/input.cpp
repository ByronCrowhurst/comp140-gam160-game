#include "input.h"

input::input()
{
	gyro = 0.5;
}

input::~input()
{

}

bool input::GetInput(sprite *player)
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			return false;
			break;
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_w:
				player->setY(-3);
				return true;
				break;
			case SDLK_a:
				player->setX(-3);
				return true;
				break;
			case SDLK_s:
				player->setY(3);
				return true;
				break;
			case SDLK_d:
				player->setX(3);
				return true;
				break;
			default:
				return true;
				break;
			}
		}
		return true;
	}
	return true;
}


void input::Update()
{

}

void input::GetSerialInputs(std::tuple<float, float, float> serials, sprite * player)
{
	// left right gyro
	player->setY(1);
	player->setY(-(std::floor(std::get<0>(serials)) + std::floor(std::get<1>(serials))));
	//std::cout << "Floored Values: " << std::floor(std::get<0>(serials)) + std::floor(std::get<1>(serials)) << " " << std::get<2>(serials)<<std::endl;
	if (std::get<2>(serials) + gyro > 0)
	{
		player->setX(5);
	}
	else
	{
		player->setX(-5);
	}
}