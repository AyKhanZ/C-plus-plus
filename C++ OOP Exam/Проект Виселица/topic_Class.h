#pragma once
#include <iostream>
#include "fstream"
#include "string"
#include <ctime>
#include "vector"

using namespace std;

class topic_Class {
public:
	topic_Class() :rnd_animal{ "No animal" }, rnd_city{ "No animal" } {};
	void animals_rnd();
	void cities_rnd();
	string get_rnd_animal() {
		return rnd_animal;
	};
	string get_rnd_city() {
		return rnd_city;
	};
private:
	vector <string> vec_saver;
	ifstream file;
	string rnd_animal;
	string rnd_city;
};

