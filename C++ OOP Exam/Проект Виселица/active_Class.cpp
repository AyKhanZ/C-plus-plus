#include "active_Class.h"

void active_Class::active_key_hang() {
	//Save random word to variable
	string main_word;
	main_word = menu.show_menu_and_ret_word();
	//Get length of random wors
	int len = main_word.length();
	//Guessed word:
	vector <char> guessed_word(len);
	system("CLS");


	for (size_t i = 0; i < len; i++) {
		guessed_word[i] = '_';
		cout << guessed_word[i] << ' ';
		if (i == len - 1) cout << endl;
	}
	bool flag = false;
	int attempts = 7;


	//time
	time_t now1 = time(0);
	tm* ltm = localtime(&now1);
	int hour1 = 1 + ltm->tm_hour;
	int min1 = 1 + ltm->tm_min;
	int sec1 = 1 + ltm->tm_sec;
	//cout << hour1 << ":" << min1 << ":" << sec1;

	if (main_word == "error"){
		flag = true;
		system("CLS");
		cout << "Error";
	}
	while (!flag) {
		cout << "\nAttempts :" << attempts << '\n';
		//Show keyboard
		keyboard.show_keyboard();

		char alphabet;
		cout << "\nEnter alphabet: ";
		cin >> alphabet;
		system("CLS");
		if (main_word.find(alphabet) == string::npos) {
			attempts--;
		}
		else {
			for (size_t i = 0; i < main_word.length(); i++) {
				if (main_word[i] == alphabet) guessed_word[i] = alphabet;
			}
		}
		// Attempts
		if (attempts <= 0) {
			hangman.show_left_leg();
			//time
			time_t now2 = time(0);
			tm* ltm2 = localtime(&now2);
			int hour2 = 1 + ltm2->tm_hour;
			int min2 = 1 + ltm2->tm_min;
			int sec2 = 1 + ltm2->tm_sec;
			SetConsoleTextAttribute(h, purple);
			cout << endl << "Time: ";
			if ((hour2 - hour1) < 0) cout << (hour2 - hour1) * (-1) << ":";
			else cout << hour2 - hour1 << ":";
			if ((min2 - min1) < 0) cout << (min2 - min1) * (-1) << ":";
			else cout << min2 - min1 << ":";
			if ((sec2 - sec1) < 0) cout << (sec2 - sec1) * (-1) << endl;
			else cout << sec2 - sec1 << endl;
			cout << "Attempts: " << 7 - attempts << endl;
			cout << "Word: " << main_word;
			cout << endl << "Player's alphabet: ";
			for (size_t i = 0; i < len; i++) {
				main_word[i] = '_';
				cout << guessed_word[i] << ' ';
				if (i == len - 1) cout << endl;
			}
			SetConsoleTextAttribute(h, white);
			flag = true;
			break;
		}
		cout << endl << endl;
		int a = 0;
		if (attempts == 6) {
			hangman.show_killer();
		}
		else if (attempts == 5) {
			hangman.show_head();
		}
		else if (attempts == 4) {
			hangman.show_body();
		}
		else if (attempts == 3) {
			hangman.show_right_arm();
		}
		else if (attempts == 2) {
			hangman.show_left_arm();
		}
		else if (attempts == 1) {
			hangman.show_right_leg();
		}
		for (size_t i = 0; i < len; i++) {
			cout << guessed_word[i] << ' ';
			if (guessed_word[i] != '_') a++;
			if (a == len) {
				SetConsoleTextAttribute(h, blue);
				cout << "\n- - - - - - - - - - - - - - < GOOD JOB > - - - - - - - - - - - - - -\n";
				SetConsoleTextAttribute(h, white);


				// time
				time_t now2 = time(0);
				tm* ltm2 = localtime(&now2);
				SetConsoleTextAttribute(h, green);
				int hour2 = 1 + ltm2->tm_hour;
				int min2 = 1 + ltm2->tm_min;
				int sec2 = 1 + ltm2->tm_sec;
				/*cout << hour1 << ":" << min1 << ":" << sec1<<endl;
				cout << hour2 << ":" << min2 << ":" << sec2<<endl;*/
				cout << endl << "Time: ";
				if ((hour2 - hour1) < 0) cout << (hour2 - hour1) * (-1) << ":";
				else cout << hour2 - hour1 << ":";
				if ((min2 - min1) < 0) cout << (min2 - min1) * (-1) << ":";
				else cout << min2 - min1 << ":";
				if ((sec2 - sec1) < 0) cout << (sec2 - sec1) * (-1) << endl;
				else cout << sec2 - sec1 << endl;
				cout << "Attempts: " << 7 - attempts;
				cout << endl << "Player's alphabet: ";
				for (size_t i = 0; i < len; i++) {
					main_word[i] = '_';
					cout << guessed_word[i] << ' ';
					if (i == len - 1) cout << endl;
				}
				SetConsoleTextAttribute(h, white);


				flag = true;
				break;
			}
		}
	}

}
