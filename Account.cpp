#include "Account.h"


Account::Account(string name, string nickname, string password) : _name(name), _nickname(nickname), _password(password) {}

Account::~Account() {
	_messages.Delete();
}

string Account::getName()const {
	return _name;
}

string Account::getNickname()const {
	return _nickname;
}

bool Account::ComparePassword(string password)const {
	return _password == password;
}

bool Account::CompareNickname(string nickname)const {
	return _nickname == nickname;
}

void Account::AddMessage(string text_m, string from_m, string for_m) {
	_messages.append(new Message(text_m, from_m, for_m));
}

void Account::PrintPrivate(string nick_friend) {
	for (int i = 0; i < _messages.len(); i++) {
		string from_m = _messages[i]->getFrom();
		string for_m = _messages[i]->getFor();
		if (for_m == nick_friend && from_m == _nickname ||
			from_m == nick_friend && for_m == _nickname) {
			_messages[i]->Print();
		}
	}
}

