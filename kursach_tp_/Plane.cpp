#include "Plane.h"


using namespace std;

void Plane::handle(std::string request) {
	string str = "plane.txt";
	cout << "Обработчик 'Самолёт':" << endl;
	function(request, str);
}
