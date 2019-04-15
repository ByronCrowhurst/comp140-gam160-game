#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "SDL.h"
/*

*/

enum Actiontype {MoveUp, MoveRight, MoveDown, MoveLeft, ButtonOne, ButtonTwo};

class keyini
{
public:
	keyini();
	~keyini();
	void ReadInput();
	void CreateDefault();
	std::string keyBind;
	std::string actions;
private:
	std::fstream fileStream;
protected:

};