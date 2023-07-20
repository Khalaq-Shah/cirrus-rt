#pragma once
#include <iostream>
#include <color_console.h>

class CirrusValidation
{
public:
	// Prints informational messages
	static void logi(const char* msg) 
	{
		std::cout << "[CirrusValidation] " << msg << std::endl;
	}
	// Prints success messages
	static void logs(const char* msg)
	{
		std::cout << dye::green("[CirrusValidation] ") << dye::yellow(msg) << std::endl;
	}
	// Prints warning messages
	static void logw(const char* msg) 
	{
		std::cout << dye::yellow("[CirrusValidation] ") << dye::yellow(msg) << std::endl;
	}
	// Prints error/failure messages
	static void loge(const char* msg) 
	{
		std::cout << dye::red("[CirrusValidation] ") << dye::red(msg) << std::endl;
	}
};