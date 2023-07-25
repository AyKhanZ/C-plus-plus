#pragma once
#include <iostream>
#include <Windows.h> 

using namespace std;

class interface_keyboard_Class
{
public:
	void show_keyboard();
private:
	enum ColorConsole {
		dark_blue = 1,
		green = 2,
		blue = 3,
		red = 4,
		purple = 5,
		yellow = 6,
		white = 7
	};
};

