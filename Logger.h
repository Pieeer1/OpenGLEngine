#pragma once
#include "Windows.h"
#include "ConsoleColors.h"

class Logger
{
public:
	static void LogInformation(const char* str);
	static void LogWarning(const char* str);
	static void LogError(const char* str);
private:
	static void ResetColor()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColors::BlackBack | ConsoleColors::WhiteFore);
	}
};

