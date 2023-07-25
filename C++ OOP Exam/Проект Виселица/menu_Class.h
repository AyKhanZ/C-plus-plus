#pragma once
#include "topic_Class.h"
#include <iostream>

using namespace std;

class menu_Class
{
public:
	menu_Class() :rnd_word{ "No word" } {};
	string show_menu_and_ret_word();
private:
	topic_Class topic;
	string rnd_word;
};

