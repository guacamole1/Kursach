
#include "friend.h"


using namespace std;

string converter(int day, int mouth, int year, int cost, string str) {
	string request;
	request = to_string(day) + "." + to_string(mouth) + "." + to_string(year) + " " + to_string(cost) + " " + str;
	return request;
}

void function(string request, string str) {
	Cashbox ob;
	vector <string> vec_string;

	bool flag1 = false;
	string str1;
	int num=1, check = 0, p = -1;
	ifstream fin;
	ofstream fot;

	try {
		fin.open(str, ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("Файл не открылся.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}

	try {
		fot.open("tickets.txt", ios_base::app);
		if (!fot.is_open()) {
			fot.close();
			throw exception("Файл 'билеты' не открылся.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}

	while (!fin.eof()) {
		getline(fin, str1);
		if (str1 == request) {
			flag1 = true;
			vec_string.push_back(str1);
			cout << vec_string.size() << " " << str1 << endl;
		}
	}
	if (flag1) {
		while (1) {
			check = num;
			cout << "Выберите билет,который хотите купить" << endl;
			cout << "Для завершения обзора введите '0'" << endl;
			cout << ">";
			cin >> num;
			if (num == -1) { break; }
			fot << vec_string[num];
			fot << "\n";
			
			if (num == check)
			{
				p++;
				if (p > 5)
				{
					cout << "Превышен лимит покупки данного билета" << endl;
				}
			}
		}

	}
	else {

		cout << "Не дал результатов" << endl;
		return ob.handle(request);
	}
	fin.close();
	fot.close();
}