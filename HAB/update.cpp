#include "update.h"

update::update()
{
	spritesToDraw[10];
}

update::~update()
{

}

sprite* update::objectsToRender()
{
	return *spritesToDraw;
}

int update::objectSize()
{
	int sizeOfArray = sizeof(objectsToRender());
	return sizeOfArray;
}

sprite* update::addSprite(sprite* spriteToAdd)
{
	return spriteToAdd;
}