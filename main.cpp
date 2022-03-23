#include <iostream>
#include <string>
#include "Server.h"
using namespace std;


int main() {

	Server server1;

	while (true) {
		string oper;
		if (!server1.getNow()) {
			cout << "Enter '1' - Login, '2' - Registration, 'q' - Exit: ";
			cin >> oper;
			if (oper != "1" && oper != "2" && oper != "q") {
				continue;
			}
			if (oper == "1") {
				server1.Login();
			}
			else if (oper == "2") {
				server1.Registration();
			}
			else if (oper == "q") {
				return 0;
			}
		}
		else {
			cout << "------------------------------------------" << endl;
			cout << "Hello, " << server1.getNow()->getName() << "!" << "\n" << endl;
			cout << "Enter '1' - Private chat, '2' - Chat for everyone, '3' - Logout, 'q' - Exit: ";
			cin >> oper;
			if (oper != "1" && oper != "2" && oper != "3" && oper != "q") {
				continue;
			}
			if (oper == "1") {
				server1.EnterPrivateChat();
			}
			else if (oper == "2") {
				server1.EnterChatAll();
			}
			else if (oper == "3"){
				server1.Logout();
			}
			else if (oper == "q") {
				return 0;
			}
		}
	}
	return 0;
}