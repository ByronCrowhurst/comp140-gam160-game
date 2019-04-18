#include "sprite.h"

sprite::sprite()
{

}

sprite::sprite(int newX, int newY, int newW, int newH)
{
	x = newX;
	y = newY;
	width = newW;
	height = newH;
	//boundingBox.w = width;
	//boundingBox.h = height;
	texture = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

	SDL_FillRect(texture, NULL, (0, 254, 254));
	boundingBox = texture->clip_rect;
	boundingBox.x = x;
	boundingBox.y = y;

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

SDL_Surface sprite::getTexture()
{
	return* texture;
}

void sprite::draw(SDL_Surface *destination)
{
	SDL_BlitSurface(texture, NULL, destination, &boundingBox);
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

void sprite::setTexture(SDL_Surface *newTexture)
{
	texture = newTexture;
}

void sprite::setSprite(int xIndex, int yIndex)
{
	// texture = 
}