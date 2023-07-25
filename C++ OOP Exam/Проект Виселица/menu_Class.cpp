#include "menu_Class.h"

string menu_Class::show_menu_and_ret_word() {
	cout << "1)Cities" << endl
		<< "2)Animals" << endl;
	int choose;
	cout << "Enter topic:";
	cin >> choose;
	switch (choose)
	{
	case 1:
		topic.cities_rnd();
		rnd_word = topic.get_rnd_city();
		return rnd_word;
		break;
	case 2:
		topic.animals_rnd();
		rnd_word = topic.get_rnd_animal();
		return rnd_word;
		break;
	default:
		return "error";
		break;
	}
}
