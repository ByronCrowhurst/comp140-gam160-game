#pragma once

#include "stdafx.h"
#include "SDL.h"

class sprite
{
public:
	sprite();
	sprite(int newX, int newY, int newW, int newH);
	~sprite();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	SDL_Rect getRect();
	SDL_Surface getTexture();
	void draw(SDL_Surface *destination);
	void setX(int newX);
	void setY(int newY);
	void setWidth(int newW);
	void setHeight(int newH);
	void setRect();
	void setTexture(SDL_Surface *newTexure);
	void setSprite(int xIndex, int yIndex);
private:

protected:
	int x;
	int y;
	int width;
	int height;
	SDL_Rect boundingBox;
	SDL_Surface *texture;
};