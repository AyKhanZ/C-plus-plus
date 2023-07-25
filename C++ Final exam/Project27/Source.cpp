#include "Header.h"

int main() {
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	card ex_row_col;
	int choice_loc = menu_location(); // Пользователь выбрал карту 
	char arr[10][10];
	char new_arr[10][10];
	if (choice_loc == 1) {
		ex_row_col.row = 2;
		ex_row_col.column = 2;
	}
	else if (choice_loc == 2) {
		ex_row_col.row = 4;
		ex_row_col.column = 4;
	}
	else if (choice_loc == 3) {
		ex_row_col.row = 6;
		ex_row_col.column = 6;
	}
	else {
		SetConsoleTextAttribute(h, red);
		cout << "Error ! << You have to choose just option 1,2 or 3 !!!" << endl;
		SetConsoleTextAttribute(h, white);
		main();
	}
	// Generate rnd simbols 
	generate_rnd_simbols(new_arr, ex_row_col.row, ex_row_col.column);
	// Нужно показатель пользователю какую карту выбрал пользователь 
	time_t now1 = time(0);
	tm* ltm = localtime(&now1);
	int hour1 = 1 + ltm->tm_hour;
	int min1 = 1 + ltm->tm_min;
	int sec1 = 1 + ltm->tm_sec;
	if (choice_loc == 1) {
		show_loc_2_2(new_arr);
		Sleep(2000);
		system("CLS");
		for (size_t i = 0; i < ex_row_col.row; i++)
		{
			for (size_t j = 0; j < ex_row_col.column; j++)
			{
				arr[i][j] = char(254);
			}
		}
		show_loc_2_2(arr);
		cout << endl << endl;
		// choise koordinats
		ex_raund.raund_2_2 = 1;
		int counter = 0;

		while (counter < 4) {
			counter = 0;
			SetConsoleTextAttribute(h, dark_blue);
			cout << "\n---------------------- < Raund-" << ex_raund.raund_2_2 << " > ----------------------" << endl;
			SetConsoleTextAttribute(h, white);
			request_from_the_user_2_2(new_arr, arr, ex_raund.raund_2_2);
			ex_raund.raund_2_2++;
			for (size_t i = 0; i < ex_row_col.row; i++)
			{
				for (size_t j = 0; j < ex_row_col.column; j++)
				{
					if (arr[i][j] != char(254)) counter++;
				}
			}
		}
		SetConsoleTextAttribute(h, green);
		cout << "\nYOU ARE WINNER!!!" << endl;
		SetConsoleTextAttribute(h, dark_blue);
		cout << "Congratulations!\tCongratulations!\tCongratulations!" << endl;
		SetConsoleTextAttribute(h, white);
		cout << "Open cards count " << OPEN_CARD << endl;
		time_t now2 = time(0);
		tm* ltm2 = localtime(&now2);
		int hour2 = 1 + ltm2->tm_hour;
		int min2 = 1 + ltm2->tm_min;
		int sec2 = 1 + ltm2->tm_sec;
		cout << endl << "Time: ";
		if ((hour2 - hour1) < 0) cout << (hour2 - hour1) * (-1) << ":";
		else cout << hour2 - hour1 << ":";
		if ((min2 - min1) < 0) cout << (min2 - min1) * (-1) << ":";
		else cout << min2 - min1 << ":";
		if ((sec2 - sec1) < 0) cout << (sec2 - sec1) * (-1) << endl;
		else cout << sec2 - sec1 << endl;

	}
	else if (choice_loc == 2) {
		int choice_X1 = 0;
		int choice_Y1 = 0;
		int choice_X2 = 0;
		int choice_Y2 = 0;

		int balls_X = 0;
		int balls_O = 0;
		char turn = 'X'; //'O'

		int one_or_two = 0;
		cout << "One or two players ? " << endl
			<< "One - \'1\'" << endl
			<< "Two - \'2\'" << endl;
		cin >> one_or_two;
		system("CLS");
		int counter = 0;
		switch (one_or_two)
		{
		case 1:
			show_loc_4_4(new_arr);
			Sleep(2000);
			system("CLS");
			for (size_t i = 0; i < ex_row_col.row; i++)
			{
				for (size_t j = 0; j < ex_row_col.column; j++)
				{
					arr[i][j] = char(254);
				}
			}
			show_loc_4_4(arr);
			cout << endl << endl;
			// choise koordinats
			ex_raund.raund_4_4 = 1;
			while (counter < 16) {
				counter = 0;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "\n---------------------- < Raund-" << ex_raund.raund_4_4 << " > ----------------------" << endl;
				SetConsoleTextAttribute(h, white);
				request_from_the_user_4_4(new_arr, arr, ex_raund.raund_4_4);
				ex_raund.raund_4_4++;
				for (size_t i = 0; i < ex_row_col.row; i++)
				{
					for (size_t j = 0; j < ex_row_col.column; j++)
					{
						if (arr[i][j] != char(254)) counter++;
					}
				}
			}
			SetConsoleTextAttribute(h, green);
			cout << "\nYOU ARE WINNER!!!" << endl;
			SetConsoleTextAttribute(h, dark_blue);
			cout << "Congratulations!\tCongratulations!\tCongratulations!" << endl;
			SetConsoleTextAttribute(h, white);
			cout << "Open cards count " << OPEN_CARD << endl;
			break;
		case 2:
			show_loc_4_4(new_arr);
			Sleep(2000);
			system("CLS");
			for (size_t i = 0; i < ex_row_col.row; i++)
			{
				for (size_t j = 0; j < ex_row_col.column; j++)
				{
					arr[i][j] = char(254);
				}
			}
			show_loc_4_4(arr);
			cout << endl << endl;
			// choise koordinats
			ex_raund.raund_4_4 = 1;
			while (counter < 16) {
				counter = 0;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "\n----------------------- < Raund-" << ex_raund.raund_4_4 << " > -----------------------" << endl;
				cout << "\n-------------------- < Turn\'s " << turn << " > --------------------" << endl;
				SetConsoleTextAttribute(h, white);
		
				card_thirst_4_4(choice_X1, choice_Y1, new_arr, arr);
				card_second_4_4(choice_X2, choice_Y2, new_arr, arr, ex_raund.raund_4_4);

				if (arr[choice_X1 - 1][choice_Y1 - 1] != arr[choice_X2 - 1][choice_Y2 - 1]) { // fall
					arr[choice_X1 - 1][choice_Y1 - 1] = char(254);
					arr[choice_X2 - 1][choice_Y2 - 1] = char(254);
					Beep(10000, 1000);
					Sleep(1000);
					system("cls");
					show_loc_4_4(arr);
					if (turn == '0') turn = 'X';
					else turn = '0';
				}
				else {
					Beep(1000, 1000);
					if (turn == 'X') balls_X++;
					else balls_O++;
				}

				ex_raund.raund_4_4++;

				for (size_t i = 0; i < ex_row_col.row; i++)
				{
					for (size_t j = 0; j < ex_row_col.column; j++)
					{
						if (arr[i][j] != char(254)) {
							counter++;
						}
					}
				}
			}

			SetConsoleTextAttribute(h, green);
			if (balls_X > balls_O) {
				cout << "\nPlayer X is WINNER!!!" << endl;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "Congratulations!\tCongratulations!\tCongratulations!" << endl;
			}
			else if (balls_O > balls_X) {
				cout << "\nPlayer 0 is WINNER!!!" << endl;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "Congratulations!\tCongratulations!\tCongratulations!" << endl;
			}
			else {
				SetConsoleTextAttribute(h, purple);
				cout << "\nNobody win" << endl;
			}
			cout << "balls X = " << balls_X << endl;
			cout << "balls 0 = " << balls_O << endl;
			SetConsoleTextAttribute(h, white);
			cout << "Open cards count " << (balls_X + balls_O)*2 << endl;
			break;
		default:
			cout << "Error ! You should choose just 1 or 2 optin !!!" << endl;
			break;
		}
		time_t now2 = time(0);
		tm* ltm2 = localtime(&now2);
		int hour2 = 1 + ltm2->tm_hour;
		int min2 = 1 + ltm2->tm_min;
		int sec2 = 1 + ltm2->tm_sec;
		cout << endl << "Time: ";
		if ((hour2 - hour1) < 0) cout << (hour2 - hour1) * (-1) << ":";
		else cout << hour2 - hour1 << ":";
		if ((min2 - min1) < 0) cout << (min2 - min1) * (-1) << ":";
		else cout << min2 - min1 << ":";
		if ((sec2 - sec1) < 0) cout << (sec2 - sec1) * (-1) << endl;
		else cout << sec2 - sec1 << endl;

	}
	else if (choice_loc == 3) {
		int choice_X1 = 0;
		int choice_Y1 = 0;
		int choice_X2 = 0;
		int choice_Y2 = 0;

		int balls_X = 0;
		int balls_O = 0;
		char turn = 'X'; //'O'

		int one_or_two = 0;
		cout << "One or two players ? " << endl
			<< "One - \'1\'" << endl
			<< "Two - \'2\'" << endl;
		cin >> one_or_two;
		system("CLS");
		int counter = 0;

		switch (one_or_two) {
		case 1:
			show_loc_6_6(new_arr);
			Sleep(2000);
			system("CLS");
			for (size_t i = 0; i < ex_row_col.row; i++)
			{
				for (size_t j = 0; j < ex_row_col.column; j++)
				{
					arr[i][j] = char(254);
				}
			}
			show_loc_6_6(arr);
			cout << endl << endl;
			// choise koordinats
			ex_raund.raund_6_6 = 1;

			while (counter < 36) {
				counter = 0;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "\n---------------------- < Raund-" << ex_raund.raund_6_6 << " > ----------------------" << endl;
				SetConsoleTextAttribute(h, white);
				request_from_the_user_6_6(new_arr, arr, ex_raund.raund_6_6);
				ex_raund.raund_6_6++;
				for (size_t i = 0; i < ex_row_col.row; i++)
				{
					for (size_t j = 0; j < ex_row_col.column; j++)
					{
						if (arr[i][j] != char(254)) counter++;
					}
				}
			}
			SetConsoleTextAttribute(h, green);
			cout << "\nYOU ARE WINNER!!!" << endl;
			SetConsoleTextAttribute(h, dark_blue);
			cout << "Congratulations!\tCongratulations!\tCongratulations!" << endl;
			SetConsoleTextAttribute(h, white);
			cout << "Open cards count " << OPEN_CARD << endl;
			break;

		case 2:
			show_loc_6_6(new_arr);
			Sleep(2000);
			system("CLS");
			for (size_t i = 0; i < ex_row_col.row; i++)
			{
				for (size_t j = 0; j < ex_row_col.column; j++)
				{
					arr[i][j] = char(254);
				}
			}
			show_loc_6_6(arr);
			cout << endl << endl;
			// choise koordinats
			ex_raund.raund_6_6 = 1;
			while (counter < 36) {
				counter = 0;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "\n----------------------- < Raund-" << ex_raund.raund_6_6 << " > -----------------------" << endl;
				cout << "\n-------------------- < Turn\'s " << turn << " > --------------------" << endl;
				SetConsoleTextAttribute(h, white);

				card_thirst_6_6(choice_X1, choice_Y1, new_arr, arr);
				card_second_6_6(choice_X2, choice_Y2, new_arr, arr, ex_raund.raund_6_6);

				if (arr[choice_X1 - 1][choice_Y1 - 1] != arr[choice_X2 - 1][choice_Y2 - 1]) { // fall
					arr[choice_X1 - 1][choice_Y1 - 1] = char(254);
					arr[choice_X2 - 1][choice_Y2 - 1] = char(254);
					Beep(10000, 1000);
					Sleep(1000);
					system("cls");
					show_loc_6_6(arr);
					if (turn == '0') turn = 'X';
					else turn = '0';
				}
				else {
					Beep(1000, 1000);
					if (turn == 'X') balls_X++;
					else balls_O++;
				}
				ex_raund.raund_6_6++;

				for (size_t i = 0; i < ex_row_col.row; i++)
				{
					for (size_t j = 0; j < ex_row_col.column; j++)
					{
						if (arr[i][j] != char(254)) {
							counter++;
						}
					}
				}
			}

			SetConsoleTextAttribute(h, green);
			if (balls_X > balls_O) {
				cout << "\nPlayer X is WINNER!!!" << endl;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "Congratulations!\tCongratulations!\tCongratulations!" << endl;
			}
			else if (balls_O > balls_X) {
				cout << "\nPlayer 0 is WINNER!!!" << endl;
				SetConsoleTextAttribute(h, dark_blue);
				cout << "Congratulations!\tCongratulations!\tCongratulations!" << endl;
			}
			else {
				SetConsoleTextAttribute(h, purple);
				cout << "\nNobody win" << endl;
			}
			cout << "balls X = " << balls_X << endl;
			cout << "balls 0 = " << balls_O << endl;
			SetConsoleTextAttribute(h, white);
			cout << "Open cards count " << (balls_X + balls_O) * 2 << endl;
			break;
		default:
			cout << "Error ! You should choose just 1 or 2 optin !!!" << endl;
			break;
		}
		time_t now2 = time(0);
		tm* ltm2 = localtime(&now2);
		int hour2 = 1 + ltm2->tm_hour;
		int min2 = 1 + ltm2->tm_min;
		int sec2 = 1 + ltm2->tm_sec;
		cout << endl << "Time: ";
		if ((hour2 - hour1) < 0) cout << (hour2 - hour1) * (-1) << ":";
		else cout << hour2 - hour1 << ":";
		if ((min2 - min1) < 0) cout << (min2 - min1)*(-1) << ":";
		else cout << min2 - min1 << ":";
		if ((sec2 - sec1) < 0) cout << (sec2 - sec1)*(-1) << endl;
		else cout << sec2 - sec1 << endl;
		
	}
	return 0;
}

