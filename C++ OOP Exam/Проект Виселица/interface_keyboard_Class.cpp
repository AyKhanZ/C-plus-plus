#include "interface_keyboard_Class.h"

enum ColorConsole {
	dark_blue = 1,
	green = 2,
	blue = 3,
	red = 4,
	purple = 5,
	yellow = 6,
	white = 7
}; 

void interface_keyboard_Class:: show_keyboard() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, dark_blue);
	for (size_t i = 0; i < 29; i++) {
		if (i == 28) cout << endl;
		else if (i == 0)cout << "  ";
		else cout << char(196);
	}
	cout << " | A | B | C | D | E | F | G |" << endl;
	cout << " | H | I | J | K | L | M | N |" << endl;
	cout << " | O | P | Q | R | S | T | U |" << endl;
	cout << " |   | V | W | X | Y | Z |   |";
	for (size_t i = 0; i < 29; i++) {
		if (i == 28) cout << endl;
		else if (i == 0) cout << endl << "  ";
		else cout << char(196);
	}
	SetConsoleTextAttribute(h, white);
}
