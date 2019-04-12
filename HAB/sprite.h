#pragma once

#include "stdafx.h"
#include "SDL.h"

class sprite
{
public:
	sprite(int newX, int newY, int newW, int newH, SDL_Texture* newTexture);
	~sprite();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	SDL_Rect getRect();
	SDL_Texture* getTexture();
	void setX(int newX);
	void setY(int newY);
	void setWidth(int newW);
	void setHeight(int newH);
	void setRect();
	void setTexture(SDL_Texture* newTexure);
private:

protected:
	int x;
	int y;
	int width;
	int height;
	SDL_Rect boundingBox;
	SDL_Texture* texture;
};