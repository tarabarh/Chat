#pragma once
#include <string>
#include "Array.h"
#include "Message.h"
using namespace std;


class Account {

	string _name;
	string _nickname;
	string _password;
	Array<Message*> _messages;


public:
	Account() = default;
	Account(string name, string nickname, string password);
	~Account();

	string getName()const;
	string getNickname()const;

	bool ComparePassword(string password)const;
	bool CompareNickname(string nickname)const;

	void AddMessage(string text_m, string from_m, string for_m);

	void PrintPrivate(string nick_friend);
};