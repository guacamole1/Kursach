#include "Train.h"

using namespace std;

void Train::handle(std::string request) {
	string str = "train.txt";
	cout << "Обработчик 'Поезд':" << endl;
	function(request, str);

}
Train::Train() {}
Train::~Train() {}