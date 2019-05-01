#pragma once

#include "stdafx.h"
#include "SDL.h"
#include "sprite.h"
#include <vector>
#include <iostream>
#include <map>
#include <tuple>


class input
{
public:
	input();
	~input();
	bool GetInput(sprite *player);
	void GetSerialInputs(std::tuple<float, float, float> serial, sprite *player);
	void Update();
private:
	int currentInput;
	std::map<std::string, SDL_Keycode> playerKey;
	SDL_Keycode currentKey;
	float gyro;

protected:

};