#include <iostream>
#include <SDL.h>
#include <vector>
#include <tuple>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "stdafx.h"
#include "sprite.h"
#include "input.h"
#include "update.h"
#include "render.h"
#include "SerialInput.h"

char incomingData[MAX_DATA_LENGTH];

int main(int argc, char * argv[])
{
	const char *portName = "\\\\.\\COM3";
	bool running = true;
	int winPos = 100;
	int width = 600;
	int height = 600;
	const char* title = "Hot Air Balloon Racing";
	SerialInput arduino(portName);
	render renderLoop(title, winPos, width, height);
	input inputs;
	update updateLoop;
	Uint32 startingTick;
	sprite *player=new sprite(width/2, height/2, 32, 32, "Player");
	std::vector<sprite*> spritesToRender = {};
	spritesToRender.push_back(player);

	std::string inpstr = "u";
	std::vector<float> serials;
	while (running)
	{
		startingTick = SDL_GetTicks();
		if (arduino.isConnected())
		{
			arduino.thisSerial->write(inpstr);
			if (arduino.thisSerial->available() >= 0)
			{
				std::string readResult = arduino.readSerialPort();
				std::tuple<float, float, float> serials(arduino.serialSplit(readResult));
				arduino.thisSerial->flush();
				inputs.GetSerialInputs(serials, player);
			}
		}

		running = inputs.GetInput(player);
		int arraySize = updateLoop.objectSize();
		renderLoop.rendering(spritesToRender);
	}
	delete player;
	return 0;
}