#include "Cashbox.h"
#include <string>

using namespace std;

Cashbox::Cashbox(){
	day = 0;
	mouth = 0;
	year = 0;
	point = "";
	next_handler = nullptr;
}

Cashbox::~Cashbox(){
}

Cashbox* Cashbox::gethandler() {
	return next_handler;
}

Cashbox* Cashbox:: SetNext(Cashbox *handler) {

	this->next_handler = handler;
	return handler;
}
void Cashbox::handle(std::string request) {
	if (this->next_handler) {
		return this->next_handler->handle(request);
	}
}

