#include "SerialInput.h"

SerialInput::SerialInput(const char *portName)
{
	std::vector<serial::PortInfo> device = serial::list_ports();
	std::vector<serial::PortInfo>::iterator iteration = device.begin();
	while (iteration != device.end())
	{
		serial::PortInfo device = *iteration++;
		std::string port = device.port.c_str();
		try
		{
			thisSerial = new serial::Serial(port, CBR_9600, serial::Timeout::simpleTimeout(1000));
			if (thisSerial->isOpen())
			{
				std::cout << "Success!" << std::endl;
				connected = true;
				break;
			}
		}
		catch(std::exception &e)
		{
			this->connected = false;
			std::cout << "Nope!" << std::endl;
		}
	}

}

SerialInput::~SerialInput()
{
	delete thisSerial;
	thisSerial = nullptr;
}

std::string SerialInput::readSerialPort()
{
	std::string result = thisSerial->readline();
	return result;
}

bool SerialInput::writeSerialPort(char *buffer, unsigned int buffSize)
{
	DWORD byteSend;

	if (!WriteFile(this->handler, (void*)buffer, buffSize, &byteSend, 0))
	{
		ClearCommError(this->handler, &this->errors, &this->status);
		return false;
	}
	else { return true; }
}

bool SerialInput::isConnected()
{
	return this->connected;
}

std::tuple<float, float, float> SerialInput::serialSplit(std::string toBeSplit)
{
	//std::cout << toBeSplit << std::endl;
	if (toBeSplit.size() >= 6)
	{
		int badIdea = 0;
		std::string leftPotStr = "";
		std::string rightPotStr = "";
		std::string gyroStr = "";
		for (int i = 0; i < toBeSplit.size(); i++)
		{
			switch (badIdea)
			{
			case 0:
				if (toBeSplit.at(i) == ',')
				{
					badIdea = 1;
					break;
				}
				else
				{
					leftPotStr += toBeSplit.at(i);
					break;
				}
			case 1:
				if (toBeSplit.at(i) == ',')
				{
					badIdea = 2;
					break;
				}
				else
				{
					rightPotStr += toBeSplit.at(i);
					break;
				}
			case 2:
				if (toBeSplit.at(i) == ',')
				{
					badIdea = 0;
					break;
				}
				else
				{
					gyroStr += toBeSplit.at(i);
					break;
				}
			}
		}
		float leftPotValue = std::stof(leftPotStr);
		float rightPotValue = std::stof(rightPotStr);
		float gyroValue = std::stof(gyroStr);
		std::tuple<float, float, float> serial(leftPotValue, rightPotValue, gyroValue);
		//std::cout << "Serials: " << std::get<0>(serial) << " " << std::get<1>(serial) << " " << std::get<2>(serial) << std::endl;
		return serial;
	}
	std::tuple<float, float, float> serial(0, 0, 0);
	return serial;
}