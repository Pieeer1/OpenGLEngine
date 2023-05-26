#include "Logger.h"
#include "iostream"
#define FOREGROUND_YELLOW = 14;

void Logger::LogInformation(const char* str)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColors::BlackBack | ConsoleColors::BlueFore);
	std::cout << str << std::endl;
	ResetColor();

}
void Logger::LogWarning(const char* str)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColors::BlackBack | ConsoleColors::YellowFore);
	std::cout << str << std::endl;
	ResetColor();

}
void Logger::LogError(const char* str)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ConsoleColors::BlackBack | ConsoleColors::RedFore);
	std::cout << str << std::endl;
	ResetColor();
}