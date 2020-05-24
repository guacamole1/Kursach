
#include "friend.h"


using namespace std;

string converter(int day, int mouth, int year, double cost, string str) {
	string request;
	request = to_string(day) + "." + to_string(mouth) + "." + to_string(year) + " " + to_string(cost) + " " + str;
	return request;
}

void function(string request, string str) {
	Cashbox ob;
	vector <string> vec_string;

	bool flag1 = false;
	string str1;
	int num, check = 0, p = 0;
	ifstream fin;
	ofstream fot;

	try {
		fin.open(str, ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("���� �� ��������.");
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
			throw exception("���� '������' �� ��������.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}

	while (!fin.eof()) {
		getline(fin, str1);
		if (str.find(request) != std::string::npos) {
			flag1 = true;
			vec_string.push_back(str1);
			cout << vec_string.size() << " " << str1 << endl;
		}
	}
	if (flag1) {
		while (num != 0) {
			check = num;
			cout << "�������� �����,������� ������ ������" << endl;
			cout << "��� ���������� ������ ������� '0'" << endl;
			cout << ">";
			cin >> num;
			fot << vec_string[num];
			if (num == check)
			{
				p++;
				if (p > 5)
				{
					cout << "�������� ����� ������� ������� ������" << endl;
				}
			}
		}

	}
	else {

		cout << "�� ��� �����������" << endl;
		return ob.handle(request);
	}
	fin.close();
	fot.close();
}