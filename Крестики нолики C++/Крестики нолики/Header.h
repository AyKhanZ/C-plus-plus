#pragma once
#include <iostream>
#define LEN 9

using namespace std;

char winner = ' ';


void ShowTable(char arr[LEN]);

void UpdateCell(char arr[LEN], char turn);

bool CheckWinner(char arr[LEN]);

char ChangeTurn(char turn);




void ShowTable(char arr[LEN]) {
	system("CLS");

	cout << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << endl
		<< char(186) << ' ' << arr[0] << ' ' << char(186) << ' ' << arr[1] << ' ' << char(186) << ' ' << arr[2] << ' ' << char(186) << endl
		<< char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << endl
		<< char(186) << ' ' << arr[3] << ' ' << char(186) << ' ' << arr[4] << ' ' << char(186) << ' ' << arr[5] << ' ' << char(186) << endl
		<< char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << endl
		<< char(186) << ' ' << arr[6] << ' ' << char(186) << ' ' << arr[7] << ' ' << char(186) << ' ' << arr[8] << ' ' << char(186) << endl
		<< char(200) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(188) << endl;
}



void UpdateCell(char arr[LEN], char turn) {
	int input;
	cin >> input;

	switch (input)
	{
	case 1:
		if (arr[input - 1] == '1') arr[0] = turn;
		else UpdateCell(arr, turn);
		break;
	case 2:
		if (arr[input - 1] == '2') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	case 3:
		if (arr[input - 1] == '3') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	case 4:
		if (arr[input - 1] == '4') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	case 5:
		if (arr[input - 1] == '5') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	case 6:
		if (arr[input - 1] == '6') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	case 7:
		if (arr[input - 1] == '7') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	case 8:
		if (arr[input - 1] == '8') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	case 9:
		if (arr[input - 1] == '9') arr[input - 1] = turn;
		else UpdateCell(arr, turn);
		break;
	default:
		UpdateCell(arr, turn);
		break;
	}
}


bool CheckWinner(char arr[LEN]) {
	if (arr[0] != '1') {
		if (arr[0] == arr[1] && arr[1] == arr[2]) { winner = arr[0]; return true; }
		else if (arr[0] == arr[3] && arr[3] == arr[6]) { winner = arr[0]; return true; }
		else if (arr[0] == arr[4] && arr[4] == arr[8]) { winner = arr[0]; return true; }
	}
	if (arr[1] != '2') {
		if (arr[1] == arr[4] && arr[4] == arr[7]) { winner = arr[1]; return true; }
	}
	if (arr[2] != '3') {
		if (arr[2] == arr[5] && arr[5] == arr[8]) { winner = arr[2]; return true; }
		else if (arr[2] == arr[4] && arr[4] == arr[6]) { winner = arr[2]; return true; }
	}
	if (arr[3] != '4') {
		if (arr[3] == arr[4] && arr[4] == arr[5]) { winner = arr[3]; return true; }
	}
	if (arr[6] != '7') {
		if (arr[6] == arr[7] && arr[7] == arr[8]) { winner = arr[6]; return true; }
	}
	return false;
}


char ChangeTurn(char turn) {
	if (turn == 'X') return 'O';
	else return 'X';
}