#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "interface_hangman_Class.h"
#include "interface_keyboard_Class.h"
#include "menu_Class.h"
#include <ctime>
#include <time.h>
#include <Windows.h>

class active_Class
{
public:
	void active_key_hang();

private:
	interface_keyboard_Class keyboard;
	interface_hangman_Class hangman;
	menu_Class menu;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
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

