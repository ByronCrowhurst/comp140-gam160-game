#include "sprite.h"

sprite::sprite(int newX, int newY, int newW, int newH, SDL_Texture* newTexture)
{
	x = newX;
	y = newY;
	width = newW;
	height = newH;
	boundingBox.x = x;
	boundingBox.y = y;
	boundingBox.w = width;
	boundingBox.h = height;
	texture = newTexture;
}

sprite::~sprite()
{

}

int sprite::getX()
{
	return x;
}

int sprite::getY()
{
	return y;
}

int sprite::getHeight()
{
	return height;
}

int sprite::getWidth()
{
	return width;
}

SDL_Rect sprite::getRect()
{
	return boundingBox;
}

SDL_Texture* sprite::getTexture()
{
	return texture;
}

void sprite::setX(int newX)
{
	x = newX;
}

void sprite::setY(int newY)
{
	y = newY;
}

void sprite::setHeight(int newHeight)
{
	height = newHeight;
}

void sprite::setWidth(int newWidth)
{
	width = newWidth;
}

void sprite::setRect()
{
	boundingBox.x = x;
	boundingBox.y = y;
	boundingBox.w = width;
	boundingBox.h = height;
}

void sprite::setTexture(SDL_Texture* newTexture)
{
	texture = newTexture;
}