#include "Plane.h"


using namespace std;

void Plane::handle(int flag, std::string request) {
	cout << "Handle 'Plane':" << endl;
	function(flag,request, file);
}
Plane::Plane(){
	file = "plane.txt";
}
Plane::~Plane() {}