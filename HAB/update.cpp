#include "update.h"

update::update()
{
	
}

update::~update()
{

}

sprite* update::objectsToRender()
{
	return NULL;
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