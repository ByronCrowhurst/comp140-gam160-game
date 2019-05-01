#include "sprite.h"

//sprite::sprite()
//{
//
//}

sprite::sprite(int newX, int newY, int newW, int newH, std::string newName)
{
	x = newX;
	y = newY;
	width = newW;
	height = newH;
	boundingBox.x = x;
	boundingBox.y = y;
	boundingBox.w = width;
	boundingBox.h = height;
	texture = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

	SDL_FillRect(texture, &boundingBox, (0, 254, 254));
	//boundingBox = texture.clip_rect;
	name = newName;
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

void sprite::draw(SDL_Surface *destination, SDL_Rect destRect)
{
	int blit = SDL_BlitSurface(texture, NULL, destination, &boundingBox);
	//std::cout << blit << std::endl;
}

void sprite::setX(int newX)
{
	if (x + newX < 0)
	{
		x = 0;
		std::cout << x << "\n";
	}
	else if (x + newX > 600 - boundingBox.w)
	{
		x = 600 - boundingBox.w;
		std::cout << x << "\n";
	}
	else
	{
		x += newX;
		std::cout << x << "\n";
	}
	// x = newX > screensize 
	boundingBox.x = x;
}

void sprite::setY(int newY)
{
	if (y + newY < 0)
	{
		y = 0;
	}
	else if (y + newY > 600 - boundingBox.h)
	{
		y = 600 - boundingBox.h;
	}
	else
	{
		y += newY;
	}
	boundingBox.y = y;
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

std::string sprite::getName()
{
	return name;
}