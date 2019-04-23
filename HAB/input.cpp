#include "input.h"

input::input()
{
	keyini keys;
	enum inputs {};
	//std::cout << "Action: " << keys.actions << "\n" << "Key Binding: " << keys.keyBind << std::endl;
}

input::~input()
{

}

int input::GetInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDLK_w:
			return 0;
		case SDLK_d:
			return 1;
		case SDLK_s:
			return 2;
		case SDLK_a:
			return 3;
		case SDL_BUTTON_LEFT:
			return 4;
		case SDL_BUTTON_RIGHT:
			return 5;
		}
		return 6;
	}
}

void input::Update(int userInput)
{
	//SDL_Event e;
	//while (SDL_PollEvent(&e))
	//{
	//	for (int i; i <= playerKey.size()-1; i++)
	//	{
	//		switch (e.type)
	//		{
	//			currentKey = playerKey[i];
	//		case currentKey:
	//		}
	//	}
	//}
}

void input::ChangeKeys(std::string action, SDL_Keycode newKey)
{

}