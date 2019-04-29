#pragma once

#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"
#include <iostream>
#include <map>


class input
{
public:
	input();
	~input();
	void GetInput();
	void Update();
private:
	int currentInput;
	std::map<std::string, SDL_Keycode> playerKey;
	SDL_Keycode currentKey;

protected:

};