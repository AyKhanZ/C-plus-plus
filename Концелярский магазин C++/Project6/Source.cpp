#include <iostream>

using namespace std;

void main() {
	int pen_pieces, pencil_pieces, ruler_pieces, paper_pieces, notebook_pieces, stapler_pieces, scissors_pieces;
	pen_pieces = 9, pencil_pieces = 9, ruler_pieces = 8, paper_pieces = 8, notebook_pieces = 5, stapler_pieces = 3, scissors_pieces = 6;
	double revenue = 0;
	do
	{
		int custumer_choise = 0;
		double count_money = 0;
		int choise_to_exit = 0;

		// -------------------------------------------------- Главное меню -------------------------------------
		cout << char(201);
		for (size_t i = 0; i < 36; i++)
		{
			if (i == 30) cout << char(203);
			else cout << char(205);
		}
		cout << char(187) << endl;
		cout << char(186) << "1. Customer Service Server    " << char(186) << "  1  " << char(186) << endl
			<< char(186) << "2. Total store revenue        " << char(186) << "  2  " << char(186) << endl
			<< char(186) << "3. Exit                       " << char(186) << "  3  " << char(186) << endl;
		cout << char(200);
		for (size_t i = 0; i < 36; i++)
		{
			if (i == 30) cout << char(202);
			else cout << char(205);
		}
		cout << char(188) << endl;




		cout << endl << "Choise option --->>> ";
		cin >> custumer_choise;

		enum start { CSS = 1, TSR, exit };
		if (custumer_choise == CSS) {
			//------------------------------------------------- товары -------------------------------------------------------------
			do {
				enum good {
					pen = 1,
					pencil,
					ruler,
					paper,
					notebook,
					stapler,
					scissors
				};
				cout << char(201);
				for (size_t i = 0; i < 36; i++)
				{
					if (i == 12 || i == 24) cout << char(203);
					else cout << char(205);
				}
				cout << char(187) << endl;

				cout << char(186) << "1. pen      " << char(186) << "  0.5$ USD " << char(186) << "  " << pen_pieces << " picies " << char(186) << endl
					<< char(186) << "2. pencil   " << char(186) << "  0.2$ USD " << char(186) << "  " << pencil_pieces << " picies " << char(186) << endl
					<< char(186) << "3. ruler    " << char(186) << "  0.5$ USD " << char(186) << "  " << ruler_pieces << " picies " << char(186) << endl
					<< char(186) << "4. paper    " << char(186) << "   1$  USD " << char(186) << "  " << paper_pieces << " picies " << char(186) << endl
					<< char(186) << "5. notebook " << char(186) << "   3$  USD " << char(186) << "  " << notebook_pieces << " picies " << char(186) << endl
					<< char(186) << "6. stapler  " << char(186) << "   4$  USD " << char(186) << "  " << stapler_pieces << " picies " << char(186) << endl
					<< char(186) << "7. scissors " << char(186) << "   2$  USD " << char(186) << "  " << scissors_pieces << " picies " << char(186) << endl;

				cout << char(200);
				for (size_t i = 0; i < 36; i++)
				{
					if (i == 12 || i == 24) cout << char(202);
					else cout << char(205);
				}
				cout << char(188) << endl;

				cout << endl << "Which product do you want ???" << endl << "Enter code --->>> ";
				int object_choise = 0;
				cin >> object_choise;
				cout << endl << "How many pieces do you want ???" << endl << "Enter quantity --->>> ";
				int how_many = 0;
				cin >> how_many;
				switch (object_choise) {
				case pen:
					count_money += (0.5) * how_many;
					pen_pieces -= 1 * how_many;
					if (pen_pieces < 0) {
						cout << "\nWE HAVE NO PRODUCTS!!! \n";
						pen_pieces += 1 * how_many;
						break;
					}
					else {
						cout << "\nit costs " << count_money << " $ USD " << endl << "picies --->>" << pen_pieces << endl;
					}
					break;
				case pencil:
					count_money += (0.2) * how_many;
					pencil_pieces -= 1 * how_many;
					if (pencil_pieces < 0) {
						cout << "\nWE HAVE NO PRODUCTS!!! \n";
						pencil_pieces += 1 * how_many;
						break;
					}
					else {
						cout << "\nit costs " << count_money << " $ USD " << endl << "picies --->>" << pencil_pieces << endl;
					}
					break;
				case ruler:
					count_money += (0.5) * how_many;
					ruler_pieces -= 1 * how_many;
					if (ruler_pieces < 0) {
						cout << "\nWE HAVE NO PRODUCTS!!! \n";
						ruler_pieces += 1 * how_many;
						break;
					}
					else {
						cout << "\nit costs " << count_money << " $ USD " << endl << "picies --->>" << ruler_pieces << endl;
					}
					break;
				case paper:
					count_money += 1 * how_many;
					paper_pieces -= 1 * how_many;
					if (ruler_pieces < 0) {
						cout << "\nWE HAVE NO PRODUCTS!!! \n";
						paper_pieces += 1 * how_many;
						break;
					}
					else {
						cout << "\nit costs " << count_money << " $ USD " << endl << "picies --->>" << paper_pieces << endl;
					}
					break;
				case notebook:
					count_money += 3 * how_many;
					notebook_pieces -= 1 * how_many;
					if (notebook_pieces < 0) {
						cout << "\nWE HAVE NO PRODUCTS!!! \n";
						notebook_pieces += 1 * how_many;
						break;
					}
					else {
						cout << "\nit costs " << count_money << " $ USD " << endl << "picies --->>" << notebook_pieces << endl;
					}
					break;
				case stapler:
					count_money += 4 * how_many;
					stapler_pieces -= 1 * how_many;
					if (stapler_pieces < 0) {
						cout << "\nWE HAVE NO PRODUCTS!!! \n";
						stapler_pieces += 1 * how_many;
						break;
					}
					else {
						cout << "\nit costs " << count_money << " $ USD " << endl << "picies --->>" << stapler_pieces << endl;
					}
					break;
				case scissors:
					count_money += 2 * how_many;
					scissors_pieces -= 1 * how_many;
					if (scissors_pieces < 0) {
						cout << "\nWE HAVE NO PRODUCTS!!! \n";
						scissors_pieces += 1 * how_many;
						break;
					}
					else {
						cout << "\nit costs " << count_money << " $ USD " << endl << "picies --->>" << scissors_pieces << endl;
					}
					break;
				default:
					cout << "\nERROR!!! Choise 1,2,3,4,5,6 or 7 !!!" << endl;
					continue;
				}
				revenue += count_money;
				count_money = 0;
				cout << "\nContinue to shop --->>> 0" << endl << "Stop shopping --->>> 1" << endl << "--->>>\n";
				cin >> choise_to_exit;
			} while (choise_to_exit == 0);
		}
		//-------------------------------------------------- Total store revenue --------------------------------------------------
		else if (custumer_choise == TSR) {
			system("CLS");
			cout << endl << "Revenue --->>> " << revenue << " $ USD" << endl << endl;
		}
		//-------------------------------------------------- Выход из приложения -------------------------------------------------
		else if (custumer_choise == exit) {
			cout << endl << "EXIT " << endl;
			break;
		}
		//--------------------------------------- Предусмотреть неправильно вводимые данные ---------------------------------------
		else {
			system("CLS");
			cout << endl << "ERROR!!! Enter 1,2 or 3 !!!" << endl;
		}
	} while (true);

}