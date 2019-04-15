#include "keyini.h"

keyini::keyini()
{
	fileStream.open("Config/keyconfig.txt", fileStream.in);
	if (fileStream.is_open())
	{
		bool keyActionSwitch = false;
		std::stringstream entireFile;
		entireFile << fileStream.rdbuf();
		std::string entireText;
		entireText = entireFile.str();
		for (int i = 0; i < entireText.size(); i++)
		{
			if (!keyActionSwitch)
			{
				if (entireText[i] != '=')
				{
					keyBind += entireText[i];
				}
				else
				{
					keyActionSwitch = true;
				}
			}
			else if (keyActionSwitch)
			{
				if (entireText[i] != '\n')
				{
					actions += entireText[i];
				}
				else
				{
					keyActionSwitch = false;
				}
			}
		}
		
	}
	else
	{
		std::cout << "No keyconfig found. Creating default." << std::endl;
		std::ofstream outFile("Config/keyconfig.txt");
		outFile.close();
	}
	fileStream.close();
}

keyini::~keyini()
{

}

void keyini::ReadInput()
{
	const char * byteSize;
	fileStream.open("keyconfig.bin");
	if (fileStream.good())
	{
		
	}
	else
	{

	}
}

void keyini::CreateDefault()
{

}