#include <iostream>
#include <SDL.h>
#include <vector>
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
	SDL_Window *window;
	window = SDL_CreateWindow(title, winPos, winPos, width, height, SDL_WINDOW_OPENGL);
	render renderLoop;
	input inputs;
	update updateLoop;
	SDL_Rect canvas;
	SDL_Surface *screen = SDL_GetWindowSurface(window);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_UpdateWindowSurface(window);
	Uint32 startingTick;
	sprite boii(width/2, height/2, 32, 32);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);
	std::vector<sprite*> spritesToRender = {};
	spritesToRender.push_back(&boii);
	std::string inpstr = "u";
	// SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, 32, 32);
	while (running)
	{
		startingTick = SDL_GetTicks();
		if (arduino.isConnected())
		{
			arduino.thisSerial->write(inpstr);
			if (arduino.thisSerial->available() >= 0)
			{
				std::string readResult = arduino.readSerialPort();
				std::cout << readResult << std::endl;
				arduino.serialSplit(readResult);
				arduino.thisSerial->flush();
			}
		}
		//puts(incomingData);
		Sleep(10);
		//inputs.GetInput();
		int arraySize = updateLoop.objectSize();
		//sprite *spritesToRender = new sprite[updateLoop.objectSize()];
		//spritesToRender = updateLoop.objectsToRender();
		renderLoop.rendering(renderer, spritesToRender, &canvas, screen);
		
	}
	return 0;
}