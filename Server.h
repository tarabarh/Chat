#pragma once
#include "Account.h"
#include "Array.h"
#include "Message.h"


class Server {

	Array<Account*> _accounts;
	Account* _now = nullptr;
	Array<Message*> _messages_evryone;

public:

	Server() = default;
	~Server();

	Account* getNow()const;

	void Registration();

	void Login();

	void Logout();

	Account* Inside(string new_name);

	void EnterPrivateChat();

	void Chat(Account* my_friend);

	void EnterChatAll();

	void PrintChatEvryone();

};
