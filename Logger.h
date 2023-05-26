#pragma once
#include "Windows.h"
#include "ConsoleColors.h"
#include <string>
class Logger
{
public:
	static void LogInformation(const char* str);
	static void LogWarning(const char* str);
	static void LogError(const char* str);	
	static void LogInformation(std::string str);
	static void LogWarning(std::string str);
	static void LogError(std::string str);
private:
	static void ResetColor()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColors::BlackBack | ConsoleColors::WhiteFore);
	}
};

