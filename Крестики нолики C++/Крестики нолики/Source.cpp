#include "Header.h"

int main() {

	char moves[LEN] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	int steps = 0;
	char turn = 'X'; //'O'
	bool hasWinner = false;

	ShowTable(moves);
	while (steps++ < 9 && !hasWinner)
	{

		UpdateCell(moves, turn);

		hasWinner = CheckWinner(moves);

		turn = ChangeTurn(turn);
		ShowTable(moves);
	}

	switch (winner)
	{
	case 'X':
		cout << "The winner is X!\n";
		break;
	case 'O':
		cout << "The winner is O!\n";
		break;
	default:
		cout << "Game is draw!\n";
		break;
	}


	return 0;
}

