#include "Train.h"

using namespace std;

void Train::handle(int flag, std::string request) {
	cout << "Handle 'Train':" << endl;
	function(flag,request, file);

}
Train::Train() {
	file = "train.txt";
}
Train::~Train() {}