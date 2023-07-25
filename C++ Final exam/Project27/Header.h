#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <Windows.h> 

using namespace std;

int OPEN_CARD = 0;

enum ColorConsole {
	dark_blue = 1,
	green = 2,
	blue = 3,
	red = 4,
	purple = 5,
	yellow = 6,
	white = 7
};
struct card {
	int row = 0;
	int column = 0;
};
struct raund {
	int raund_2_2 = 0;
	int raund_4_4 = 0;
	int raund_4_6 = 0;
	int raund_6_6 = 0;
}ex_raund;


// * * * :
int menu_location();
void personality(int how_many_players);
void generate_rnd_simbols(char new_arr[10][10], int row, int columns);


// ---------------------------------------------------------2x2---------------------------------------------------------
void show_loc_2_2(char arr[10][10]);
void request_from_the_user_2_2(char new_arr[10][10], char arr[10][10], int& raund);
void card_thirst_2_2(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10]);
void card_second_2_2(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10], int& raund);
// ---------------------------------------------------------4x4---------------------------------------------------------
void show_loc_4_4(char arr[10][10]);
void request_from_the_user_4_4(char new_arr[10][10], char arr[10][10], int& raund);
void card_thirst_4_4(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10]);
void card_second_4_4(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10], int& raund);
// ---------------------------------------------------------6x6---------------------------------------------------------
void show_loc_6_6(char arr[10][10]);
void request_from_the_user_6_6(char new_arr[10][10], char arr[10][10], int& raund);
void card_thirst_6_6(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10]);
void card_second_6_6(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10], int& raund);


// * * * :
int menu_location() {
	cout << "Choose location :" << endl
		<< "1) Scheme 2x2   " << "- \'1\' " << endl
		<< "2) Scheme 4x4   " << "- \'2\' " << endl
		<< "3) Scheme 6x6   " << "- \'3\' " << endl
		<< "--->>>\t";
	int choice_scheme = 0;
	cin >> choice_scheme;
	system("cls");////////////////////////////////////////////////////////////////////////////
	return choice_scheme;
}
// * * * :
void generate_rnd_simbols(char new_arr[10][10], int row, int columns) { // 2 2 // 4 4 // 6 6 
	char arr_simbols_1[2] = { '@','#' };
	char arr_simbols_2[8] = { '@','#','-','*','$','+','=','>' };
	char arr_simbols_3[12] = { '@','#','-','*','$','+','=','>','/','\\' ,'|','(' };
	char arr_simbols_4[18] = { '@','#','-','*','$','+','=','>','/','\\' ,'|','(','^',':','[','{','!','?' };
	int answer = 0;
	if (row == 2 && columns == 2) { answer = 1; }
	if (row == 4 && columns == 4) { answer = 2; }
	if (row == 6 && columns == 6) { answer = 3; }

	int k = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (k == 1 + (columns * row / 2 - 1)) k = 0;
			if (answer == 1) {
				new_arr[i][j] = arr_simbols_1[k];
				k++;
			}
			else if (answer == 2) {
				new_arr[i][j] = arr_simbols_2[k];
				k++;
			}
			else if (answer == 3) {
				new_arr[i][j] = arr_simbols_4[k];
				k++;
			}

		}
	}
}


// * * * 2x2 :
void show_loc_2_2(char arr[10][10]) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < 2; i++)
	{
		SetConsoleTextAttribute(h, yellow);
		if (i == 0) {
			cout << "          ^                     " << endl;
			cout << "          |           1    2    " << endl <<
				"------------------------------------------------------------>(X)" << endl <<
				"1         |           ";
		}
		SetConsoleTextAttribute(h, white);
		SetConsoleTextAttribute(h, blue);
		for (size_t j = 0; j < 2; j++) {
			if (arr[i][j] != char(254)) {
				SetConsoleTextAttribute(h, purple);
				cout << arr[i][j] << "    ";
				SetConsoleTextAttribute(h, blue);
			}
			else cout << arr[i][j] << "    ";
		}
		SetConsoleTextAttribute(h, yellow);
		if (i == 0) cout << endl << endl << "2         |           ";
		if (i == 1) cout << endl << endl << "         (Y)          ";
		SetConsoleTextAttribute(h, white);
		if (i == 1) cout << endl;
	}
}
// * * * 2x2 :
void request_from_the_user_2_2(char new_arr[10][10], char arr[10][10], int& raund) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice_X1 = 0;
	int choice_Y1 = 0;
	int choice_X2 = 0;
	int choice_Y2 = 0;

	card_thirst_2_2(choice_X1, choice_Y1, new_arr, arr);
	OPEN_CARD++;
	card_second_2_2(choice_X2, choice_Y2, new_arr, arr, raund);
	OPEN_CARD++;

	if (arr[choice_X1 - 1][choice_Y1 - 1] != arr[choice_X2 - 1][choice_Y2 - 1]) {
		arr[choice_X1 - 1][choice_Y1 - 1] = char(254);
		arr[choice_X2 - 1][choice_Y2 - 1] = char(254);
		Beep(10000, 1000);
		Sleep(1000);
		system("cls");
		show_loc_2_2(arr);
	}
	else if (arr[choice_X1 - 1][choice_Y1 - 1] == arr[choice_X2 - 1][choice_Y2 - 1]) {
		Beep(1000, 1000);
	}
}
// * * * 2x2 :
void card_thirst_2_2(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10]) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Open first card " << endl
		<< "Choose coordinates x and y:";
	cin >> choice_y >> choice_x;
	system("cls");
	if ((choice_x == 1 || choice_x == 2) && (choice_y == 1 || choice_y == 2)) {
		if (arr[choice_x - 1][choice_y - 1] == char(254)) {
			if (choice_x == 1 && choice_y == 1) {
				arr[0][0] = new_arr[0][0];
				show_loc_2_2(arr);
			}
			else if (choice_x == 1 && choice_y == 2) {
				arr[0][1] = new_arr[0][1];
				show_loc_2_2(arr);
			}
			else if (choice_x == 2 && choice_y == 2) {
				arr[1][1] = new_arr[1][1];
				show_loc_2_2(arr);
			}
			else if (choice_x == 2 && choice_y == 1) {
				arr[1][0] = new_arr[1][0];
				show_loc_2_2(arr);
			}
		}
		else {
			SetConsoleTextAttribute(h, red);
			cout << "Error! This card already open !!!" << endl;
			SetConsoleTextAttribute(h, white);
			//Рекусивно вызываю функцию
			card_thirst_2_2(choice_y, choice_x, new_arr, arr);
		}
	}
	else {
		SetConsoleTextAttribute(h, red);
		cout << "Error ! << You should choose just option 1 or 2" << endl;
		SetConsoleTextAttribute(h, white);
		//Рекусивно вызываю функцию
		card_thirst_2_2(choice_x, choice_y, new_arr, arr);
	}
}
// * * * 2x2 :
void card_second_2_2(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10], int& raund) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, dark_blue);
	cout << "\n---------------------- < Raund-" << raund << " > ----------------------" << endl;
	SetConsoleTextAttribute(h, white);
	cout << "Open second card " << endl
		<< "Choose coordinates x and y:";
	cin >> choice_y >> choice_x;
	system("cls");
	if (arr[choice_x - 1][choice_y - 1] == char(254)) {
		if (choice_x == 1 && choice_y == 1) {
			arr[0][0] = new_arr[0][0];
			show_loc_2_2(arr);
		}
		else if (choice_x == 1 && choice_y == 2) {
			arr[0][1] = new_arr[0][1];
			show_loc_2_2(arr);
		}
		else if (choice_x == 2 && choice_y == 2) {
			arr[1][1] = new_arr[1][1];
			show_loc_2_2(arr);
		}
		else if (choice_x == 2 && choice_y == 1) {
			arr[1][0] = new_arr[1][0];
			show_loc_2_2(arr);
		}
		else {
			SetConsoleTextAttribute(h, red);
			cout << "Error ! << You should choose just option 1 or 2" << endl;
			SetConsoleTextAttribute(h, white);
			//Рекусивно вызываю функцию
			card_second_2_2(choice_x, choice_y, new_arr, arr, raund);
		}
	}
	else {
		SetConsoleTextAttribute(h, red);
		cout << "Error! This card already open !!!" << endl;
		SetConsoleTextAttribute(h, white);
		//Рекусивно вызываю функцию
		card_second_2_2(choice_x, choice_y, new_arr, arr, raund);
	}
}
//-------------------------------------------------------------------------------------------------------------
// * * * 4x4 :
void show_loc_4_4(char arr[10][10]) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < 4; i++)
	{
		SetConsoleTextAttribute(h, yellow);
		if (i == 0) {
			cout << "          ^                     " << endl;
			cout << "          |           1    2    3    4    " << endl <<
				"------------------------------------------------------------>(X)" << endl <<
				"1         |           ";
		}
		SetConsoleTextAttribute(h, white);
		SetConsoleTextAttribute(h, blue);
		for (size_t j = 0; j < 4; j++) {
			if (arr[i][j] != char(254)) {
				SetConsoleTextAttribute(h, purple);
				cout << arr[i][j] << "    ";
				SetConsoleTextAttribute(h, blue);
			}
			else cout << arr[i][j] << "    ";
		}
		SetConsoleTextAttribute(h, yellow);
		if (i == 0) cout << endl << endl << "2         |           ";
		if (i == 1) cout << endl << endl << "3         |           ";
		if (i == 2) cout << endl << endl << "4         |           ";
		if (i == 3) cout << endl << endl << "         (Y)          ";
		SetConsoleTextAttribute(h, white);
		if (i == 3) cout << endl;
	}
}
// * * * 4x4 :
void request_from_the_user_4_4(char new_arr[10][10], char arr[10][10], int& raund) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice_X1 = 0;
	int choice_Y1 = 0;
	int choice_X2 = 0;
	int choice_Y2 = 0;

	card_thirst_4_4(choice_X1, choice_Y1, new_arr, arr);
	OPEN_CARD++;
	card_second_4_4(choice_X2, choice_Y2, new_arr, arr, raund);
	OPEN_CARD++;

	if (arr[choice_X1 - 1][choice_Y1 - 1] != arr[choice_X2 - 1][choice_Y2 - 1]) {
		arr[choice_X1 - 1][choice_Y1 - 1] = char(254);
		arr[choice_X2 - 1][choice_Y2 - 1] = char(254);
		Beep(10000, 1000);
		Sleep(1000);
		system("cls");
		show_loc_4_4(arr);
	}
	else if (arr[choice_X1 - 1][choice_Y1 - 1] == arr[choice_X2 - 1][choice_Y2 - 1]) {
		Beep(1000, 1000);
	}
}
// * * * 4x4 :
void card_thirst_4_4(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10]) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Open first card " << endl
		<< "Choose coordinates x and y:";
	cin >> choice_y >> choice_x;
	if ((choice_x == 1 || choice_x == 2 || choice_x == 3 || choice_x == 4) && (choice_y == 1 || choice_y == 2 || choice_y == 3 || choice_y == 4)) {
		if (arr[choice_x - 1][choice_y - 1] == char(254)) {

			if (choice_x == 1 && choice_y == 1) {
				system("cls");
				arr[0][0] = new_arr[0][0];
				show_loc_4_4(arr);
			}
			else if (choice_x == 1 && choice_y == 2) {
				system("cls");
				arr[0][1] = new_arr[0][1];
				show_loc_4_4(arr);
			}
			else if (choice_x == 1 && choice_y == 3) {
				system("cls");
				arr[0][2] = new_arr[0][2];
				show_loc_4_4(arr);
			}
			else if (choice_x == 1 && choice_y == 4) {
				system("cls");
				arr[0][3] = new_arr[0][3];
				show_loc_4_4(arr);
			}
			//----------------------------------------
			else if (choice_x == 2 && choice_y == 1) {
				system("cls");
				arr[1][0] = new_arr[1][0];
				show_loc_4_4(arr);
			}
			else if (choice_x == 2 && choice_y == 2) {
				system("cls");
				arr[1][1] = new_arr[1][1];
				show_loc_4_4(arr);
			}
			else if (choice_x == 2 && choice_y == 3) {
				system("cls");
				arr[1][2] = new_arr[1][2];
				show_loc_4_4(arr);
			}
			else if (choice_x == 2 && choice_y == 4) {
				system("cls");
				arr[1][3] = new_arr[1][3];
				show_loc_4_4(arr);
			}
			//----------------------------------------
			else if (choice_x == 3 && choice_y == 1) {
				system("cls");
				arr[2][0] = new_arr[2][0];
				show_loc_4_4(arr);
			}
			else if (choice_x == 3 && choice_y == 2) {
				system("cls");
				arr[2][1] = new_arr[2][1];
				show_loc_4_4(arr);
			}
			else if (choice_x == 3 && choice_y == 3) {
				system("cls");
				arr[2][2] = new_arr[2][2];
				show_loc_4_4(arr);
			}
			else if (choice_x == 3 && choice_y == 4) {
				system("cls");
				arr[2][3] = new_arr[2][3];
				show_loc_4_4(arr);
			}
			//----------------------------------------
			else if (choice_x == 4 && choice_y == 1) {
				system("cls");
				arr[3][0] = new_arr[3][0];
				show_loc_4_4(arr);
			}
			else if (choice_x == 4 && choice_y == 2) {
				system("cls");
				arr[3][1] = new_arr[3][1];
				show_loc_4_4(arr);
			}
			else if (choice_x == 4 && choice_y == 3) {
				system("cls");
				arr[3][2] = new_arr[3][2];
				show_loc_4_4(arr);
			}
			else if (choice_x == 4 && choice_y == 4) {
				system("cls");
				arr[3][3] = new_arr[3][3];
				show_loc_4_4(arr);
			}
		}
		else {
			SetConsoleTextAttribute(h, red);
			cout << "Error! This card already open !!!" << endl;
			SetConsoleTextAttribute(h, white);
			//Рекусивно вызываю функцию
			card_thirst_4_4(choice_y, choice_x, new_arr, arr);
		}
	}
	else {
		SetConsoleTextAttribute(h, red);
		cout << "Error ! << You should choose just option 1,2,3 or 4" << endl;
		SetConsoleTextAttribute(h, white);
		//Рекусивно вызываю функцию
		card_thirst_4_4(choice_x, choice_y, new_arr, arr);
	}
}
// * * * 4x4 :
void card_second_4_4(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10], int& raund) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, dark_blue);
	cout << "\n---------------------- < Raund-" << raund << " > ----------------------" << endl;
	SetConsoleTextAttribute(h, white);
	cout << "Open second card " << endl
		<< "Choose coordinates x and y:";
	cin >> choice_y >> choice_x;
	//system("cls");
	if (arr[choice_x - 1][choice_y - 1] == char(254)) {
		if (choice_x == 1 && choice_y == 1) {
			system("cls");
			arr[0][0] = new_arr[0][0];
			show_loc_4_4(arr);
		}
		else if (choice_x == 1 && choice_y == 2) {
			system("cls");
			arr[0][1] = new_arr[0][1];
			show_loc_4_4(arr);
		}
		else if (choice_x == 1 && choice_y == 3) {
			system("cls");
			arr[0][2] = new_arr[0][2];
			show_loc_4_4(arr);
		}
		else if (choice_x == 1 && choice_y == 4) {
			system("cls");
			arr[0][3] = new_arr[0][3];
			show_loc_4_4(arr);
		}
		//----------------------------------------
		else if (choice_x == 2 && choice_y == 1) {
			system("cls");
			arr[1][0] = new_arr[1][0];
			show_loc_4_4(arr);
		}
		else if (choice_x == 2 && choice_y == 2) {
			system("cls");
			arr[1][1] = new_arr[1][1];
			show_loc_4_4(arr);
		}
		else if (choice_x == 2 && choice_y == 3) {
			system("cls");
			arr[1][2] = new_arr[1][2];
			show_loc_4_4(arr);
		}
		else if (choice_x == 2 && choice_y == 4) {
			system("cls");
			arr[1][3] = new_arr[1][3];
			show_loc_4_4(arr);
		}
		//----------------------------------------
		else if (choice_x == 3 && choice_y == 1) {
			system("cls");
			arr[2][0] = new_arr[2][0];
			show_loc_4_4(arr);
		}
		else if (choice_x == 3 && choice_y == 2) {
			system("cls");
			arr[2][1] = new_arr[2][1];
			show_loc_4_4(arr);
		}
		else if (choice_x == 3 && choice_y == 3) {
			system("cls");
			arr[2][2] = new_arr[2][2];
			show_loc_4_4(arr);
		}
		else if (choice_x == 3 && choice_y == 4) {
			system("cls");
			arr[2][3] = new_arr[2][3];
			show_loc_4_4(arr);
		}
		//----------------------------------------
		else if (choice_x == 4 && choice_y == 1) {
			system("cls");
			arr[3][0] = new_arr[3][0];
			show_loc_4_4(arr);
		}
		else if (choice_x == 4 && choice_y == 2) {
			system("cls");
			arr[3][1] = new_arr[3][1];
			show_loc_4_4(arr);
		}
		else if (choice_x == 4 && choice_y == 3) {
			system("cls");
			arr[3][2] = new_arr[3][2];
			show_loc_4_4(arr);
		}
		else if (choice_x == 4 && choice_y == 4) {
			system("cls");
			arr[3][3] = new_arr[3][3];
			show_loc_4_4(arr);
		}
		else {
			SetConsoleTextAttribute(h, red);
			cout << "Error ! << You should choose just option 1 ,2 ,3 or 4" << endl;
			SetConsoleTextAttribute(h, white);
			//Рекусивно вызываю функцию
			card_second_4_4(choice_x, choice_y, new_arr, arr, raund);
		}
	}
	else {
		SetConsoleTextAttribute(h, red);
		cout << "Error! This card already open !!!" << endl;
		SetConsoleTextAttribute(h, white);
		//Рекусивно вызываю функцию
		card_second_4_4(choice_x, choice_y, new_arr, arr, raund);
	}
}
//----------------------------------------------------------------------------------------------------------------------------------
// * * * 6x6 :
void show_loc_6_6(char arr[10][10]) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < 6; i++)
	{
		SetConsoleTextAttribute(h, yellow);
		if (i == 0) {
			cout << "          ^                     " << endl;
			cout << "          |           1    2    3    4    5    6    " << endl <<
				"------------------------------------------------------------>(X)" << endl <<
				"1         |           ";
		}
		SetConsoleTextAttribute(h, white);
		SetConsoleTextAttribute(h, blue);
		for (size_t j = 0; j < 6; j++) {
			if (arr[i][j] != char(254)) {
				SetConsoleTextAttribute(h, purple);
				cout << arr[i][j] << "    ";
				SetConsoleTextAttribute(h, blue);
			}
			else cout << arr[i][j] << "    ";
		}
		SetConsoleTextAttribute(h, yellow);
		if (i == 0) cout << endl << endl << "2         |           ";
		if (i == 1) cout << endl << endl << "3         |           ";
		if (i == 2) cout << endl << endl << "4         |           ";
		if (i == 3) cout << endl << endl << "5         |           ";
		if (i == 4) cout << endl << endl << "6         |           ";
		if (i == 5) cout << endl << endl << "         (Y)          ";
		SetConsoleTextAttribute(h, white);
		if (i == 5) cout << endl;
	}
}
// * * * 6x6 :
void request_from_the_user_6_6(char new_arr[10][10], char arr[10][10], int& raund) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice_X1 = 0;
	int choice_Y1 = 0;
	int choice_X2 = 0;
	int choice_Y2 = 0;

	card_thirst_6_6(choice_X1, choice_Y1, new_arr, arr);
	OPEN_CARD++;
	card_second_6_6(choice_X2, choice_Y2, new_arr, arr, raund);
	OPEN_CARD++;

	if (arr[choice_X1 - 1][choice_Y1 - 1] != arr[choice_X2 - 1][choice_Y2 - 1]) {
		arr[choice_X1 - 1][choice_Y1 - 1] = char(254);
		arr[choice_X2 - 1][choice_Y2 - 1] = char(254);
		Beep(10000, 1000);
		Sleep(1000);
		system("cls");
		show_loc_6_6(arr);
	}
	else if (arr[choice_X1 - 1][choice_Y1 - 1] == arr[choice_X2 - 1][choice_Y2 - 1]) {
		Beep(1000, 1000);
	}
}
// * * * 6x6 :
void card_thirst_6_6(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10]) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Open first card " << endl
		<< "Choose coordinates x and y:";
	cin >> choice_y >> choice_x;
	//system("cls");
	if ((choice_x == 1 || choice_x == 2 || choice_x == 3 || choice_x == 4 || choice_x == 5 || choice_x == 6) && (choice_y == 1 || choice_y == 2 || choice_y == 3 || choice_y == 4 || choice_y == 5 || choice_y == 6)) {
		if (arr[choice_x - 1][choice_y - 1] == char(254)) {
			//-----------------level1-----------------------
			if (choice_x == 1 && choice_y == 1) {
				system("cls");
				arr[0][0] = new_arr[0][0];
				show_loc_6_6(arr);
			}
			else if (choice_x == 1 && choice_y == 2) {
				system("cls");
				arr[0][1] = new_arr[0][1];
				show_loc_6_6(arr);
			}
			else if (choice_x == 1 && choice_y == 3) {
				system("cls");
				arr[0][2] = new_arr[0][2];
				show_loc_6_6(arr);
			}
			else if (choice_x == 1 && choice_y == 4) {
				system("cls");
				arr[0][3] = new_arr[0][3];
				show_loc_6_6(arr);
			}
			else if (choice_x == 1 && choice_y == 5) {
				system("cls");
				arr[0][4] = new_arr[0][4];
				show_loc_6_6(arr);
			}
			else if (choice_x == 1 && choice_y == 6) {
				system("cls");
				arr[0][5] = new_arr[0][5];
				show_loc_6_6(arr);
			}
			//-----------------level2-----------------------
			else if (choice_x == 2 && choice_y == 1) {
				system("cls");
				arr[1][0] = new_arr[1][0];
				show_loc_6_6(arr);
			}
			else if (choice_x == 2 && choice_y == 2) {
				system("cls");
				arr[1][1] = new_arr[1][1];
				show_loc_6_6(arr);
			}
			else if (choice_x == 2 && choice_y == 3) {
				system("cls");
				arr[1][2] = new_arr[1][2];
				show_loc_6_6(arr);
			}
			else if (choice_x == 2 && choice_y == 4) {
				system("cls");
				arr[1][3] = new_arr[1][3];
				show_loc_6_6(arr);
			}
			else if (choice_x == 2 && choice_y == 5) {
				system("cls");
				arr[1][4] = new_arr[1][4];
				show_loc_6_6(arr);
			}
			else if (choice_x == 2 && choice_y == 6) {
				system("cls");
				arr[1][5] = new_arr[1][5];
				show_loc_6_6(arr);
			}
			//-----------------level3-----------------------
			else if (choice_x == 3 && choice_y == 1) {
				system("cls");
				arr[2][0] = new_arr[2][0];
				show_loc_6_6(arr);
			}
			else if (choice_x == 3 && choice_y == 2) {
				system("cls");
				arr[2][1] = new_arr[2][1];
				show_loc_6_6(arr);
			}
			else if (choice_x == 3 && choice_y == 3) {
				system("cls");
				arr[2][2] = new_arr[2][2];
				show_loc_6_6(arr);
			}
			else if (choice_x == 3 && choice_y == 4) {
				system("cls");
				arr[2][3] = new_arr[2][3];
				show_loc_6_6(arr);
			}
			else if (choice_x == 3 && choice_y == 5) {
				system("cls");
				arr[2][4] = new_arr[2][4];
				show_loc_6_6(arr);
			}
			else if (choice_x == 3 && choice_y == 6) {
				system("cls");
				arr[2][5] = new_arr[2][5];
				show_loc_6_6(arr);
			}
			//-----------------level4-----------------------
			else if (choice_x == 4 && choice_y == 1) {
				system("cls");
				arr[3][0] = new_arr[3][0];
				show_loc_6_6(arr);
			}
			else if (choice_x == 4 && choice_y == 2) {
				system("cls");
				arr[3][1] = new_arr[3][1];
				show_loc_6_6(arr);
			}
			else if (choice_x == 4 && choice_y == 3) {
				system("cls");
				arr[3][2] = new_arr[3][2];
				show_loc_6_6(arr);
			}
			else if (choice_x == 4 && choice_y == 4) {
				system("cls");
				arr[3][3] = new_arr[3][3];
				show_loc_6_6(arr);
			}
			else if (choice_x == 4 && choice_y == 5) {
				system("cls");
				arr[3][4] = new_arr[3][4];
				show_loc_6_6(arr);
			}
			else if (choice_x == 4 && choice_y == 6) {
				system("cls");
				arr[3][5] = new_arr[3][5];
				show_loc_6_6(arr);
			}
			//-----------------level5-----------------------
			else if (choice_x == 5 && choice_y == 1) {
				system("cls");
				arr[4][0] = new_arr[4][0];
				show_loc_6_6(arr);
			}
			else if (choice_x == 5 && choice_y == 2) {
				system("cls");
				arr[4][1] = new_arr[4][1];
				show_loc_6_6(arr);
			}
			else if (choice_x == 5 && choice_y == 3) {
				system("cls");
				arr[4][2] = new_arr[4][2];
				show_loc_6_6(arr);
			}
			else if (choice_x == 5 && choice_y == 4) {
				system("cls");
				arr[4][3] = new_arr[4][3];
				show_loc_6_6(arr);
			}
			else if (choice_x == 5 && choice_y == 5) {
				system("cls");
				arr[4][4] = new_arr[4][4];
				show_loc_6_6(arr);
			}
			else if (choice_x == 5 && choice_y == 6) {
				system("cls");
				arr[4][5] = new_arr[4][5];
				show_loc_6_6(arr);
			}
			//-----------------level6-----------------------
			else if (choice_x == 6 && choice_y == 1) {
				system("cls");
				arr[5][0] = new_arr[5][0];
				show_loc_6_6(arr);
			}
			else if (choice_x == 6 && choice_y == 2) {
				system("cls");
				arr[5][1] = new_arr[5][1];
				show_loc_6_6(arr);
			}
			else if (choice_x == 6 && choice_y == 3) {
				system("cls");
				arr[5][2] = new_arr[5][2];
				show_loc_6_6(arr);
			}
			else if (choice_x == 6 && choice_y == 4) {
				system("cls");
				arr[5][3] = new_arr[5][3];
				show_loc_6_6(arr);
			}
			else if (choice_x == 6 && choice_y == 5) {
				system("cls");
				arr[5][4] = new_arr[5][4];
				show_loc_6_6(arr);
			}
			else if (choice_x == 6 && choice_y == 6) {
				system("cls");
				arr[5][5] = new_arr[5][5];
				show_loc_6_6(arr);
			}
		}
		else {
			SetConsoleTextAttribute(h, red);
			cout << "Error! This card already open !!!" << endl;
			SetConsoleTextAttribute(h, white);
			//Рекусивно вызываю функцию
			card_thirst_6_6(choice_y, choice_x, new_arr, arr);
		}
	}
	else {
		SetConsoleTextAttribute(h, red);
		cout << "Error ! << You should choose just option 1,2,3,4,5 or 6" << endl;
		SetConsoleTextAttribute(h, white);
		//Рекусивно вызываю функцию
		card_thirst_6_6(choice_x, choice_y, new_arr, arr);
	}
}
// * * * 6x6 :
void card_second_6_6(int& choice_x, int& choice_y, char new_arr[10][10], char arr[10][10], int& raund) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, dark_blue);
	cout << "\n---------------------- < Raund-" << raund << " > ----------------------" << endl;
	SetConsoleTextAttribute(h, white);
	cout << "Open second card " << endl
		<< "Choose coordinates x and y:";
	cin >> choice_y >> choice_x;
	//system("cls");
	if (arr[choice_x - 1][choice_y - 1] == char(254)) {
		//-----------------level1-----------------------
		if (choice_x == 1 && choice_y == 1) {
			system("cls");
			arr[0][0] = new_arr[0][0];
			show_loc_6_6(arr);
		}
		else if (choice_x == 1 && choice_y == 2) {
			system("cls");
			arr[0][1] = new_arr[0][1];
			show_loc_6_6(arr);
		}
		else if (choice_x == 1 && choice_y == 3) {
			system("cls");
			arr[0][2] = new_arr[0][2];
			show_loc_6_6(arr);
		}
		else if (choice_x == 1 && choice_y == 4) {
			system("cls");
			arr[0][3] = new_arr[0][3];
			show_loc_6_6(arr);
		}
		else if (choice_x == 1 && choice_y == 5) {
			system("cls");
			arr[0][4] = new_arr[0][4];
			show_loc_6_6(arr);
		}
		else if (choice_x == 1 && choice_y == 6) {
			system("cls");
			arr[0][5] = new_arr[0][5];
			show_loc_6_6(arr);
		}
		//-----------------level2-----------------------
		else if (choice_x == 2 && choice_y == 1) {
			system("cls");
			arr[1][0] = new_arr[1][0];
			show_loc_6_6(arr);
		}
		else if (choice_x == 2 && choice_y == 2) {
			system("cls");
			arr[1][1] = new_arr[1][1];
			show_loc_6_6(arr);
		}
		else if (choice_x == 2 && choice_y == 3) {
			system("cls");
			arr[1][2] = new_arr[1][2];
			show_loc_6_6(arr);
		}
		else if (choice_x == 2 && choice_y == 4) {
			system("cls");
			arr[1][3] = new_arr[1][3];
			show_loc_6_6(arr);
		}
		else if (choice_x == 2 && choice_y == 5) {
			system("cls");
			arr[1][4] = new_arr[1][4];
			show_loc_6_6(arr);
		}
		else if (choice_x == 2 && choice_y == 6) {
			system("cls");
			arr[1][5] = new_arr[1][5];
			show_loc_6_6(arr);
		}
		//------------------level3---------------------
		else if (choice_x == 3 && choice_y == 1) {
			system("cls");
			arr[2][0] = new_arr[2][0];
			show_loc_6_6(arr);
		}
		else if (choice_x == 3 && choice_y == 2) {
			system("cls");
			arr[2][1] = new_arr[2][1];
			show_loc_6_6(arr);
		}
		else if (choice_x == 3 && choice_y == 3) {
			system("cls");
			arr[2][2] = new_arr[2][2];
			show_loc_6_6(arr);
		}
		else if (choice_x == 3 && choice_y == 4) {
			system("cls");
			arr[2][3] = new_arr[2][3];
			show_loc_6_6(arr);
		}
		else if (choice_x == 3 && choice_y == 5) {
			system("cls");
			arr[2][4] = new_arr[2][4];
			show_loc_6_6(arr);
		}
		else if (choice_x == 3 && choice_y == 6) {
			system("cls");
			arr[2][5] = new_arr[2][5];
			show_loc_6_6(arr);
		}
		//-----------------level4-----------------------
		else if (choice_x == 4 && choice_y == 1) {
			system("cls");
			arr[3][0] = new_arr[3][0];
			show_loc_6_6(arr);
		}
		else if (choice_x == 4 && choice_y == 2) {
			system("cls");
			arr[3][1] = new_arr[3][1];
			show_loc_6_6(arr);
		}
		else if (choice_x == 4 && choice_y == 3) {
			system("cls");
			arr[3][2] = new_arr[3][2];
			show_loc_6_6(arr);
		}
		else if (choice_x == 4 && choice_y == 4) {
			system("cls");
			arr[3][3] = new_arr[3][3];
			show_loc_6_6(arr);
		}
		else if (choice_x == 4 && choice_y == 5) {
			system("cls");
			arr[3][4] = new_arr[3][4];
			show_loc_6_6(arr);
		}
		else if (choice_x == 4 && choice_y == 6) {
			system("cls");
			arr[3][5] = new_arr[3][5];
			show_loc_6_6(arr);
		}
		//-----------------level5-----------------------
		else if (choice_x == 5 && choice_y == 1) {
			system("cls");
			arr[4][0] = new_arr[4][0];
			show_loc_6_6(arr);
		}
		else if (choice_x == 5 && choice_y == 2) {
			system("cls");
			arr[4][1] = new_arr[4][1];
			show_loc_6_6(arr);
		}
		else if (choice_x == 5 && choice_y == 3) {
			system("cls");
			arr[4][2] = new_arr[4][2];
			show_loc_6_6(arr);
		}
		else if (choice_x == 5 && choice_y == 4) {
			system("cls");
			arr[4][3] = new_arr[4][3];
			show_loc_6_6(arr);
		}
		else if (choice_x == 5 && choice_y == 5) {
			system("cls");
			arr[4][4] = new_arr[4][4];
			show_loc_6_6(arr);
		}
		else if (choice_x == 5 && choice_y == 6) {
			system("cls");
			arr[4][5] = new_arr[4][5];
			show_loc_6_6(arr);
		}
		//-----------------level 6-----------------------
		else if (choice_x == 6 && choice_y == 1) {
			system("cls");
			arr[5][0] = new_arr[5][0];
			show_loc_6_6(arr);
		}
		else if (choice_x == 6 && choice_y == 2) {
			system("cls");
			arr[5][1] = new_arr[5][1];
			show_loc_6_6(arr);
		}
		else if (choice_x == 6 && choice_y == 3) {
			system("cls");
			arr[5][2] = new_arr[5][2];
			show_loc_6_6(arr);
		}
		else if (choice_x == 6 && choice_y == 4) {
			system("cls");
			arr[5][3] = new_arr[5][3];
			show_loc_6_6(arr);
		}
		else if (choice_x == 6 && choice_y == 5) {
			system("cls");
			arr[5][4] = new_arr[5][4];
			show_loc_6_6(arr);
		}
		else if (choice_x == 6 && choice_y == 6) {
			system("cls");
			arr[5][5] = new_arr[5][5];
			show_loc_6_6(arr);
		}
		else {
			SetConsoleTextAttribute(h, red);
			cout << "Error ! << You should choose just option 1 ,2 ,3 ,4 ,5 or 6" << endl;
			SetConsoleTextAttribute(h, white);
			//Рекусивно вызываю функцию
			card_second_6_6(choice_x, choice_y, new_arr, arr, raund);
		}
	}
	else {
		SetConsoleTextAttribute(h, red);
		cout << "Error! This card already open !!!" << endl;
		SetConsoleTextAttribute(h, white);
		//Рекусивно вызываю функцию
		card_second_6_6(choice_x, choice_y, new_arr, arr, raund);
	}
}

	
