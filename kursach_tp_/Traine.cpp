#include "Train.h"

void Train::handle(std::string request) {
	string str = "train.txt";
	cout << "���������� '�����':" << endl;
	function(request, str);

}

Train::Train() {}
Train::~Train() {}