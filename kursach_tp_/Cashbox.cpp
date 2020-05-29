#include "Cashbox.h"
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

Cashbox::Cashbox(){
	day = "";
	mouth = "";
	year = "";
	cost = "";
	point = "";
	next_handler = nullptr;
}

Cashbox::~Cashbox(){
	delete next_handler;
}

Handler* Cashbox:: SetNext(Handler *handler) {

	this-> next_handler = handler;
	return handler;
}
void Cashbox::handle(std::string request) {
	if (this->next_handler) {
		return this->next_handler->handle(request);
	}
	return;
}

void Cashbox::function(std::string request, std::string str) {
	vector <std::string> vec_string;
	vector <std::string> vec_string1;
	bool flag1 = false;
	string str1;
	int  check = 0, p = 0;
	int pos, num = -1,pp=0;

	unsigned i=0;
	ifstream fin;
	ofstream fot;

	try {
		fin.open(str, ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("File not open");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		fin.close();
		cout << "Please enter your request, it will be processed when the problems are fixed." << endl;
		fpush("raw_requests.txt");
		system("pause");
		return;
	}

	try {
		fot.open("tickets.txt", ios_base::app);
		if (!fot.is_open()) {
			fot.close();
			throw exception("File 'tickets' not open");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		fin.close();
		system("pause");
		return;
	}

	while (!fin.eof()) {
		getline(fin, str1);
		pos = str1.find(request);//ищем запрошеную запись целую/отдельный параметр
		if (string::npos != pos) {
			flag1 = true;
			vec_string.push_back(str1);
			cout << vec_string.size() << " " << str1 <<endl;
		}
	}
	if (flag1) {
		while (1) {
			pp = (int)vec_string.size();
			check = num;
			cout << "Choose the ticket you want to buy" << endl;
			cout << "To complete the review, enter '0'" << endl;
			cout << ">";
			cin >> num;
			num = num - 1;
			try {
				if (num <= pp && num >=-1) 
				{
					if (num == -1) {
						break;
					}
					if (num == check && p >= 6) {
						cout << "One ticket purchase limit exceeded" << endl;
						continue;
					}
					else {
						fot << vec_string[num] << "\n";
						if (num == check)
						{
							p++;
						}
					}
				}

				else
					throw ;
			}
			catch (...) {
				cout << "Please select a ticket from the specified interval." << endl;
				system("pause");
				break;
			}
		}

	}
	else {
		if(next_handler)
			next_handler->handle(request);
		else
			cout << "No results" << endl; system("pause");
	}
	fin.close();
	fot.close();
}

void Cashbox::push() {
	// ввод данных билета
	bool flag1 = true;
	string  str = "Incorrect input, use an example";
	int check;
	cout << "Request system Cashier -> Train -> Plane" << endl;
	cout << "Input your request" << endl;
		cout << "Example:"<< endl;
		cout << "Day:12 Month:12 Year:2020 Cost:1999 Destination:Volgograd" << endl;
		cout << "Input date: (1 -31) "<<endl;
		while (flag1)
		{
			try {
				cout << "Day:";
				cin >> day;     
				cout << "Month:";
				cin >> mouth; 
				cout << "Year:";
				cin >> year; 
				//проверка ввода параметров даты в заданых интервалах
				if (!((stoi(day) > 0 && stoi(day) < 32) && (stoi(mouth) > 0 && stoi(mouth) < 32) && (stoi(year) >= 2020 && stoi(year) < 2022))) {
					throw str;
				}
				flag1 = false;
			}
			catch (...) {
				cout << "Incorrect entry, please use an example" << endl;
				flag1 = true;
				system("pause");
			}
		}
		flag1 = true;
		cout << "Input the cost" << endl;
		while (1) {
			cout << "Cost:";
			cin >> cost;
			try {
				check = stoi(cost);
			}
			catch (...) {
				cout << "You must enter a numerical value" << endl;
				continue;
			}
			if (check <= 0) {
				cout << "Cost cannot be less than or equal to zero"; continue;
			}
			else
				break;
		}
		cout << "Input destination:" << endl;
		while (1) {
			cout << "City:";
			cin >> point;
			check = check_point(point);
			try {
				if (check == 0)
					throw exception("This city is not in the list of 'Destination'");
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
				system("pause");//поиск не дал результатов, вывод списка городов по которым следует самолёт/поезд
				fprint("point.txt");//чтобы пользователь мог сам выбрать
				continue;
			}
			break;
		}


}


std::string converter(Cashbox *ob) {
	std::string request ;
	
	request ="Day:" + ob->day + " " + "Month:" + ob->mouth + " " + "Year:" + ob->year + " " + "Cost:" +ob->cost + " " + "Destination:" + ob->point;
	return request;
}

void Cashbox::fpush(std::string str)
{
	ofstream fot;
	try {
		fot.open(str, ios_base::app);
		if (!fot.is_open()) {
			fot.close();
			throw exception("File not open.");
		}
	}
	catch (exception& ex) {
		fot.close();
		cout << ex.what() << endl;
		system("pause");
		return;
	}
	push();
	fot << endl <<"Day:"<< day << " " << "Month:" << mouth << "Year:" << year << " " << "Cost:" << cost << " " << "Destination" << point;
	fot.close();
	cout << "Record successfully added.";
}

void Cashbox::fprint(std::string str)
{
	string line;
	ifstream fout(str,ios_base::in);
	try {
		if (!fout.is_open())
			throw exception("File not open.");
	}
	catch (exception &ex) {
		cout << ex.what() << endl << endl;
		fout.close();
		system("pause");
		return;
	}

	try {
		if (fout.peek()==EOF)
			throw exception("File empty.");
	}
	catch (exception &ex) {
		cout << ex.what() << endl << endl;
		fout.close();
		system("pause");
		return;
	}
		while (!fout.eof())
		{
			getline(fout, line);
			cout << line << endl;
		}
		fout.close();
}

void Cashbox::change(int choice,string str, Cashbox *ob) {
	ofstream fot;
	ifstream fin;
	int p,i=0;
	vector <string> vec_string;
	string str1;
	try {
		fin.open(str, ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("File not open.");
		}
	}
	catch (exception& ex) {
		fin.close();
		cout << ex.what() << endl;
		system("pause");
		return;
	}

	while (!fin.eof()) {
		getline(fin, str1);//
		vec_string.push_back(str1);
		cout << vec_string.size() << " " << vec_string[i] << endl;
		i++;
		}
	fin.close();
	try {
		fot.open(str);
		if (!fot.is_open()) {
			fot.close();
			throw exception("File not open.");

		}
	}
	catch (exception& ex) {
		fot.close();
		cout << ex.what() << endl;
		system("pause");
		return;
	}
	cout << "Input the required line number: ";//введите строку для необходимых действий(изменения)
	while (1) {
		cin >> p;
		try {
			if (p <= 0 && p > (int)vec_string.size())
				throw exception("No such record");
		}
		catch (exception &ex) {
			cout << ex.what() << endl;
			system("pause");
		}
		break;
	}
	if (choice == 2) {
		cout << "Input new data";
		ob->push();
		str1 = converter(ob);
		vec_string.at(p - 1) = str1;
	}
	for (i = 0; i < vec_string.size();i++) {
		if ((choice == 1) && (i == (p - 1))) {
			continue;
		}
		else
			if ((choice == 2) && (i == (p - 1))) {
				if (i)
					fot << endl;
				fot << vec_string[i];
			}
			else {
				if (i)
					fot << endl;
				fot << vec_string[i];
			}
	}
	fot.close();
}

int Cashbox::checking(string str)
{
	ifstream fin;
	int i,j;
	string str1 ="";
	vector <string> line;
	bool flag= true;
	char a[80];
	try {
		fin.open(str, ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("File not open");
		}
	}
	catch (exception& ex) {
		fin.close();
		cout << ex.what() << endl;
		system("pause");
		return 0;
	}
	for (i = 0; i < 80; i++) {
		a[i] = 0;
	}
	i = 0;
	try {
		while (!fin.eof()) {

				fin.getline(a, 80);
				try {
					if (sizeof(a) >= 80)
						throw exception("Out of need size of string");
			}
			catch (exception &ex)
			{
				cout << ex.what() <<endl;
				system("pause");
				return 0;
			}
			while (1) {
				if (a[i] == 0) {
					line.push_back(str1);
					break;
				}
				if (a[i] != ' ' ) {
					str1 = str1 + a[i];
					i++;
				}
				else
				{
					line.push_back(str1);
					str1 = "";
					i++;
				}
				}
			for (i = 0; i < 80; i++) {
				a[i] =0;
			}
			str1 = "";
			i = 0;
			}
	}
	catch (...) {
		cout << "Eror in procces writing file" << endl;
		cout << "Pls,try again" << endl;
		system("pause");
		return 0;
	}

	for (i = 0; i < (line.size() / 5); i++)
	{			
		try{
				if ((stoi(line[i].substr(5, line[i].length())) <= 0) && (stoi(line[i].substr(5, line[i].length())) > 31)) {
					throw exception("Incorrect date record (day)");
				}
				i++;
				if ((stoi(line[i].substr(7, line[i].length())) <= 0) && (stoi(line[i].substr(7, line[i].length())) > 12)) {
					throw exception("Incorrect date record (month)");
				}
				i++;
				if ((stoi(line[i].substr(6, line[i].length())) <= 2020) && (stoi(line[i].substr(6, line[i].length())) > 2021)) {
					throw exception("Incorrect date record (year)");
				}
				i++;
				if ((stoi(line[i].substr(6, line[i].length())) <= 0) && (stoi(line[i].substr(6, line[i].length())) > 700000)) {
					throw exception("Incorrect  cost record");
				}
				i++;
				if (check_point(line[i].substr(13, line[i].length())) == 0) {
					throw exception("Incorrect Destination record");
				}
		}
		catch (exception &ex) {
			cout << ex.what() << endl;
			system("pause");
			return 0;
		}
	}
	return 1;
}

int Cashbox::check_point(string str) {
	ifstream fin;
	int pos;
	string str2;
	try {
		fin.open("point.txt", ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("File not open.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
		return 2;
	}

	while (!fin.eof()) {
		getline(fin, str2);
		pos = str2.find(str);//ищем конвертированную запись целую/отдельный параметр
		if (string::npos != pos) {
			return 1;
		}
	}
	return 0;
}

void Cashbox::set_name(string userfile) {
	UserFile = userfile;
}
string Cashbox::get_name() {
	return UserFile;
}