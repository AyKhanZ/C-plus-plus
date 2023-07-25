#include "topic_Class.h"

void topic_Class:: animals_rnd() {
	srand(time(NULL));
	file.open("animals_file.txt");
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	string n;
	while (!file.eof()) {
		getline(file, n, ' ');
		vec_saver.push_back(n);
	}
	file.close();
	int num = rand() % (vec_saver.size()) + 0;
	rnd_animal = vec_saver[num];
}

void topic_Class::cities_rnd() {
	srand(time(NULL));
	file.open("cities_file.txt");
	if (!file.is_open()) {
		cout << "Error" << endl;
	}
	string n;
	while (!file.eof()) {
		getline(file, n, ' ');
		vec_saver.push_back(n);
	}
	file.close();
	int num = rand() % (vec_saver.size()) + 0;
	rnd_city = vec_saver[num];
}