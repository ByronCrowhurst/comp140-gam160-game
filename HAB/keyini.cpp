#include "keyini.h"
#define ENUM_MACRO(name, s1, s2, s3, s4, s5, s6, s7)\
		/* create matching enum & strings to be mapped to key inputs */\
		enum name {s1, s2, s3, s4, s5, s6, s7};\
		const char *name##Strings[] = {#s1, #s2, #s3, #s4, #s5, #s6, #s7};\

ENUM_MACRO(ActionStates, MoveUp, MoveRight, MoveDown, MoveLeft, ActionOne, ActionTwo, ActionThree);

keyini::keyini()
{
	fileStream.open("Config/keyconfig.txt", fileStream.in);
	if (fileStream.is_open())
	{
		// Switch between keyActionSwitch in order to write actions and keys seperately.
		bool keyActionSwitch = false;

		// Stream entire file into a string to be read char by char to seperate actions and keys (to be added to a map)
		std::stringstream entireFile;
		entireFile << fileStream.rdbuf();
		std::string entireText;
		entireText = entireFile.str();
		std::string temp;
		for (int i = 0; i < entireText.size(); i++)
		{
			if (!keyActionSwitch)
			{
				if (entireText[i] != '=')
				{
					temp += entireText[i];
				}
				else
				{
					actions.push_back(temp);
					temp = "";
					keyActionSwitch = true;
				}
			}
			else if (keyActionSwitch)
			{
				if (entireText[i] != '\n')
				{
					temp += entireText[i];
				}
				else
				{
					keyBind.push_back(temp);
					temp = "";
					keyActionSwitch = false;
				}
			}
		}
	}
	else
	{
		// Creates default if there isn't one.
		std::cout << "No keyconfig found. Creating default." << std::endl;
		std::ofstream outFile("Config/keyconfig.txt");
		for (int i = 0; i < strlen(*ActionStatesStrings); i++)
		{
			outFile << ActionStatesStrings[i] << "=" << std::endl;
		}
		outFile.close();
	}
	fileStream.close();
	for (int i = 0; i < actions.size(); i++)
	{
		std::cout << actions[i] << " = " << keyBind[i] << std::endl;
	}
}

keyini::~keyini()
{

}
