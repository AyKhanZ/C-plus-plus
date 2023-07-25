#pragma once
#include <iostream> 
#include <Windows.h> 

using namespace std;

class interface_hangman_Class
{
public:
	void show_killer();
	void show_head();
	void show_body();
	void show_right_arm();
	void show_left_arm();
	void show_right_leg();
	void show_left_leg();
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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
};

