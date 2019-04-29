//#include "keyini.h"
//
//keyini::keyini()
//{
//
//	fileStream.open("Config/keyconfig.txt", fileStream.in);
//	if (fileStream.is_open())
//	{
//		MapActionToKeys();
//	}
//	else
//	{
//		// Creates default if there isn't one.
//		std::cout << "No keyconfig found. Creating default." << std::endl;
//		GetDefaults();
//		std::ofstream outFile("Config/keyconfig.txt");
//		for (int i = 0; i < strlen(*ActionStatesStrings); i++)
//		{
//			outFile << ActionStatesStrings[i] << "=" << defaults[i] << std::endl;
//		}
//		outFile.close();
//		MapActionToKeys();
//	}
//	fileStream.close();
//	for (int i = 0; i < actions.size(); i++)
//	{
//		std::cout << actions[i] << " = " << keyBind[i] << std::endl;
//	}
//}
//
//keyini::~keyini()
//{
//
//}
//
//void keyini::GetDefaults()
//{
//	defaults.push_back(SDL_GetKeyName(SDLK_w));
//	defaults.push_back(SDL_GetKeyName(SDLK_d));
//	defaults.push_back(SDL_GetKeyName(SDLK_s));
//	defaults.push_back(SDL_GetKeyName(SDLK_a));
//	defaults.push_back(SDL_GetKeyName(SDLK_q));
//	defaults.push_back(SDL_GetKeyName(SDLK_e));
//	defaults.push_back(SDL_GetKeyName(SDLK_SPACE));
//}
//void keyini::MapActionToKeys()
//{
//	// Switch between keyActionSwitch in order to write actions and keys seperately.
//	bool keyActionSwitch = false;
//
//	// Stream entire file into a string to be read char by char to seperate actions and keys (to be added to a map)
//	std::stringstream entireFile;
//	entireFile << fileStream.rdbuf();
//	std::string entireText;
//	entireText = entireFile.str();
//	std::string temp;
//	for (int i = 0; i < entireText.size(); i++)
//	{
//		if (!keyActionSwitch)
//		{
//			if (entireText[i] != '=')
//			{
//				temp += entireText[i];
//			}
//			else
//			{
//				actions.push_back(temp);
//				temp = "";
//				keyActionSwitch = true;
//			}
//		}
//		else if (keyActionSwitch)
//		{
//			if (entireText[i] != '\n')
//			{
//				temp += entireText[i];
//			}
//			else
//			{
//				keyBind.push_back(temp);
//				temp = "";
//				keyActionSwitch = false;
//			}
//		}
//	}
//	for (int i = 0; i < keyBind.size(); i++)
//	{
//		//actionToKeys.insert(actions[i], keyBind[i]);
//	}
//}
