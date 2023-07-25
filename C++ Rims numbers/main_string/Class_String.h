#pragma once
#include <iostream>
#include <string>

using namespace std;

class Class_String
{
private:
	string str;
	int solv_left(int i_, int& index_start) {
		int a = 0, b = 0, c = 0;
		int solv_left = 0;

		if (str[i_ - 1] >= '0' && str[i_ - 1] <= '9') {
			a = str[i_ - 1] - '0';
			index_start = i_ - 1;
		}

		if (str[i_ - 2] >= '0' && str[i_ - 2] <= '9') {
			b = str[i_ - 2] - '0';
			index_start = i_ - 2;
		}

		if (str[i_ - 3] >= '0' && str[i_ - 3] <= '9') {
			c = str[i_ - 3] - '0';
			index_start = i_ - 3;
		}
		solv_left = a + b * 10 + c * 100;
		return solv_left;
	}
	int solv_right(int i_, int& index_end) {
		int solv_right = 0;
		int a = 0, b = 0, c = 0;
		if (str[i_ + 1] >= '0' && str[i_ + 1] <= '9') {
			a = str[i_ + 1] - '0';
			index_end = i_ + 1;
		}

		if (str[i_ + 2] >= '0' && str[i_ + 2] <= '9') {
			b = str[i_ + 2] - '0';
			index_end = i_ + 2;
		}

		if (str[i_ + 3] >= '0' && str[i_ + 3] <= '9') {
			c = str[i_ + 3] - '0';
			index_end = i_ + 3;
		}
		solv_right = a + b * 10 + c * 100;
		return solv_right;
	}


public:
	string Get_str() const { return str; }
	void Set_str(string s) { str = s; }
	void show() { cout << "string: " << endl << str << endl; }


	void compress();
	void del_comment();
	void search_suf(string full_str, string sufiks_search);
	int solve();
	void rim_numbers();
	void way_file();
};