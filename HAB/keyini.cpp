#include "keyini.h"

keyini::keyini()
{
	fileStream.open("Config/keyconfig.txt", fileStream.binary);
	if (fileStream.is_open())
	{
		std::cout << "File found." << std::endl;
		while(fileStream.getline)
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