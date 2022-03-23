#pragma once
#include <string>
#include <iostream>
using namespace std;


class Message {
	string _text;
	string _from_m;
	string _for_m;

public:
	Message(string text = "", string from_m = "", string for_m = "");
	~Message();

	void Print();

	string getFor() const { return _for_m; }
	string getFrom()const { return _from_m; }
};

