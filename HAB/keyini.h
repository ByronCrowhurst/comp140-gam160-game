
#pragma once
#include "stdafx.h"
#include "SDL.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



class keyini
{
public:
	keyini();
	~keyini();
	std::vector<std::string> keyBind;
	std::vector<std::string> actions;
private:
	std::fstream fileStream;
protected:

};