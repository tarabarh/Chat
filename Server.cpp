#include "Server.h"
#include <string>
#include <iostream>
using namespace std;


Server::~Server() {
	_accounts.Delete();
	_messages_evryone.Delete();
}

Account* Server::getNow()const {
	return _now;
}

void Server::Registration() {
	string name;
	cout << "Enter you name: ";
	cin >> name;
	string nickname;
	cout << "Enter you nickname: ";
	cin >> nickname;
	if (Inside(nickname)) {
		cout << "Nickname is not free!" << endl;
		return;
	}
	string password;
	cout << "Enter you password (minimum of 6 characters): ";
	cin >> password;
	if (password.length() < 6) {
		cout << "Few characters!" << endl;
		return;
	}
	_accounts.append(new Account(name, nickname, password));
}

void Server::Login() {
	string nickname;
	cout << "Enter nickname: ";
	cin >> nickname;
	string password;
	cout << "Enter password: ";
	cin >> password;
	for (int i = 0; i < _accounts.len(); i++) {
		if (_accounts[i]->CompareNickname(nickname) && _accounts[i]->ComparePassword(password)) {
			_now = _accounts[i];
			cout << "Successfully!" << endl;
			return;
		}
	}
	cout << "Incorrect nickname or password!" << endl;
}

void Server::Logout() {
	_now = nullptr;
	cout << "Goodbye!" << endl;
}

Account* Server::Inside(string new_nickname) {                        //checking account availability (if available,    
	for (int i = 0; i < _accounts.len(); i++) {                       // returns a pointer to the account)
		if (_accounts[i]->getNickname() == new_nickname) {
			return _accounts[i];
		}
	}
	return nullptr;
}

void Server::EnterPrivateChat() {
	if (_accounts.len() < 2) {
		cout << "List of riends is empty!" << endl;
		return;
	}
	Array<Account*> list_friends;
	for (int i = 0; i < _accounts.len(); i++) {
		if (_accounts[i]->getNickname() == _now->getNickname()) {
			continue;
		}
		list_friends.append(_accounts[i]);
	}
	cout << "------------------------------------------" << endl;
	cout << "List of friends: " << endl;                                                // creating a list of friends
	for (int i = 0; i < list_friends.len(); i++) {
		cout << i + 1 << ") " << list_friends[i]->getNickname() << endl;
	}
	int pos = 0;
	while (pos < 1 || pos > list_friends.len() + 1) {
		cout << "------------------------------------------" << endl;
		cout << "Enter position: ";
		cin >> pos;
	}
	Chat(list_friends[pos - 1]);
	}

void Server::Chat(Account* my_friend) {
	cout << "------------------------------------------" << endl;
	_now->PrintPrivate(my_friend->getNickname());                                        // dialog output
	string text;
	cin.ignore();
	while (true) {
		cout << "Enter text or 'b' for back: ";                           
		getline(cin, text);
		if (text == "b") {
			break;
		}
		_now->AddMessage(text, _now->getNickname(), my_friend->getNickname());           // sending a message
		my_friend->AddMessage(text, _now->getNickname(), my_friend->getNickname());
	}
}

void Server::EnterChatAll() {
	cout << "------------------------------------------" << endl;
	PrintChatEvryone();
	string text;
	cin.ignore();
	while (true) {
		cout << "Enter text or 'b' for back: ";
		getline(cin, text);
		if (text == "b") {
			break;
		}
		_messages_evryone.append(new Message(text, _now->getNickname(), "For evryone"));
	}
}

void Server::PrintChatEvryone() {
	for (int i = 0; i < _messages_evryone.len(); i++) {
		_messages_evryone[i]->Print();
	}
}