#include "Class_String.h"
#include <iostream>
using namespace std;


void Class_String:: way_file() {
	//	C:\Step\С++lesson_03\Docs\Less03.docx
	string exer1, exer2, exer3, exer4, exer5;
	int count = 0;
	int index_start_4slesh = 0;
	int index_start_3slesh = 0;
	int dot = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '\\') {
			count++;
			if (count == 4) {
				index_start_4slesh = i;
			}
			if (count == 3) {
				index_start_3slesh = i;
			}

		}
	}
	for (size_t i = index_start_4slesh; i < str.size(); i++)
	{
		if (str[i] == '.') {
			dot = i;
		}
	}
	exer1 = str.substr(0, index_start_4slesh);
	exer2 = str.substr(index_start_3slesh + 1, index_start_4slesh - index_start_3slesh - 1);
	exer3 = str.substr(index_start_4slesh + 1, str.length() - index_start_4slesh - 1);
	exer4 = str.substr(dot, str.length() - index_start_4slesh - 1);
	exer4 = str.substr(index_start_4slesh + 1, str.length() - dot + 1);
	cout << "(1) exercise: " << exer1 << endl;
	cout << "(2) exercise: " << exer2 << endl;
	cout << "(3) exercise: " << exer3 << endl;
	cout << "(4) exercise: " << exer4 << endl;

}

void Class_String:: rim_numbers() {

	string new_string = "";
	string arr_singul[10] = { " ", "I","II","III","IV","V","VI","VII","IIX","IX" };
	string arr_double[10] = { " ", "X","XX","XXX","XL","L","LX","LXX","XXC","XC" };
	string arr_hundreds[10] = { " ", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
	string arr_thousands[5] = { " ", "M","MM","MMM","MMMM" };

	int num = stoi(str); // 4235
	new_string += arr_thousands[num / 1000];
	new_string += arr_hundreds[num / 100 % 10];
	new_string += arr_double[num % 100 / 10];
	new_string += arr_singul[num % 10];
	str = new_string;
}

int Class_String::solve() {
	int solv = 0;
	int index_start = 0;
	int index_end = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '+') {
			solv = solv_left(i, index_start) + solv_right(i, index_end);
			str.replace(index_start, index_end - index_start + 1, to_string(solv));
		};
		if (str[i] == '-') {
			solv = solv_left(i, index_start) - solv_right(i, index_end);
			str.replace(index_start, index_end - index_start + 1, to_string(solv));
		};
		if (str[i] == '*') {
			solv = solv_left(i, index_start) * solv_right(i, index_end);
			str.replace(index_start, index_end - index_start + 1, to_string(solv));
		};
		if (str[i] == '/') {
			solv = solv_left(i, index_start) / solv_right(i, index_end);
			str.replace(index_start, index_end - index_start + 1, to_string(solv));
		};

	}
	// [start,end]
	return solv;
}

void Class_String::search_suf(string full_str, string sufiks_search) {
	int start_with = 0;
	str = full_str;
	int len_search = 0;
	len_search = sufiks_search.length();
	do {
		start_with = str.find(sufiks_search, start_with + 1);
		if (start_with != -1 /*&& start_with -1 < */) {
			str.insert(start_with, "(");
			start_with = str.find(sufiks_search, start_with + 1);
			str.insert(start_with + len_search, ")");
		}

	} while (start_with != -1);
}

void Class_String::del_comment() {
	size_t i = 0;
	for (; i < str.length(); i++)
	{
		if (str[0] == '/' && str[1] == '/') {
			str.erase(0, 2);
		}
		if (str[i] == '/' && str[i + 1] == '*') {
			str.erase(i, i + 1);
		};
		if (str[i] == '*' && str[i + 1] == '/') {
			str.erase(i, i + 1);
		}
	}
}
void Class_String::compress() {
	int search = 0;
	bool switch_ = true;
	size_t i = 0;
	int count = 0;
	for (size_t j = 0; j < str.length(); j++)
	{

		if (str[j] == ' ') { count++; }
		if (count == str.length()) {
			continue;
		}
		if (switch_) {
			if (str[j] != ' ') {
				search = j;
				switch_ = false;
			}
		}
		else {
			for (; i < str.length(); i++)
			{

				if (str[i] == ' ' && str[i + 1] == ' ' && i > search) {
					str.erase(i, 1);
					i = 0;
				};
			}
		}
	}

}