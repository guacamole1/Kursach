#include "Train.h"

void Train::handle(std::string request) {
	string str = "train.txt";
	cout << "Обработчик 'Поезд':" << endl;
	function(request, str);

}