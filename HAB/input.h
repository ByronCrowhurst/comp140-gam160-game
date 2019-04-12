#pragma once

#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"
#include "keyini.h"
#include <iostream>
#include <map>


class input
{
public:
	input();
	~input();
	int GetInput();
	void Update(int userInput);
	void ChangeKeys(std::string action, SDL_Keycode newKey);
private:
	int currentInput;
	std::map<std::string, SDL_Keycode> playerKey;
	SDL_Keycode currentKey;

protected:

};