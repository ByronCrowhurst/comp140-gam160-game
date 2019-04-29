#pragma once
#ifndef SERIALINPUT_H
#define SERIALINPUT_H

#define ARDUINO_WAIT_TIME 1000
#define MAX_DATA_LENGTH 255

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <serial/serial.h>


class SerialInput
{
public:
	SerialInput(const char *portName);
	~SerialInput();

	serial::Serial* thisSerial;

	std::string readSerialPort();
	bool writeSerialPort(char *buffer, unsigned int buffSize);
	bool isConnected();
	void serialSplit(std::string toBeSplit);
private:
	HANDLE handler;
	bool connected;
	COMSTAT status;
	DWORD errors;
protected:

};
#endif