#include "Message.h"


Message::Message(string text, string from_m, string for_m) : _text(text), _from_m(from_m), _for_m(for_m){}

Message::~Message() {}

void Message::Print() {
	cout << '<' << _from_m << '>' << "  " << _text << "\n" << endl;
}
