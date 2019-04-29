//
//#pragma once
//#include "stdafx.h"
//#include "SDL.h"
//#include <map>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <vector>
//#define ENUM_MACRO(name, s1, s2, s3, s4, s5, s6, s7, s8)\
//		/* create matching enum & strings to be mapped to key inputs */\
//		enum name {s1, s2, s3, s4, s5, s6, s7, s8};\
//		const char *name##Strings[] = {#s1, #s2, #s3, #s4, #s5, #s6, #s7, #s8};\
//
//ENUM_MACRO(ActionStates, MoveUp, MoveRight, MoveDown, MoveLeft, ActionOne, ActionTwo, ActionThree, IDLE);
//
//class keyini
//{
//public:
//	ActionStates currentState;
//	keyini();
//	~keyini();
//	void GetDefaults();
//	void MapActionToKeys();
//	std::vector<std::string> keyBind;
//	std::vector<std::string> actions;
//	std::vector<std::string> defaults;
//	std::map<std::string, std::string> actionToKeys;
//private:
//	std::fstream fileStream;
//protected:
//
//};