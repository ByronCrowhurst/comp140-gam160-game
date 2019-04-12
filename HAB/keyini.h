#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "SDL.h"
/*

*/
class keyini
{
public:
	keyini();
	~keyini();
	void ReadInput();
	void CreateDefault();
private:
	std::fstream fileStream;
protected:

};