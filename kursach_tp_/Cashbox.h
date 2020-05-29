#pragma once
#include "Hendler.h"

using namespace std;

class Cashbox : public Handler {
private:
	string day;//����
	string mouth;
	string year;

	string cost;//���������

	string point;//����� ����������

	string UserFile;

	Handler *next_handler;//������ �� �������� ����������

public:

	Cashbox();
	~Cashbox();
	void push();// ���� ������ ������
	void fpush(std::string str);// ���� ������ � ����

	void fprint(std::string str);// ����� ������ ������ � ����
	void change(int choice, string str, Cashbox *ob);
	void function(std::string request, std::string str);//����� �������(request) � (str)�����
	
	int checking(string str);//�������� ������(������� �� �����/������ � �������� ������������ �����

	void set_name(string userfile);//�������� ���� � �����
	string get_name();//

	int check_point(string str);// �������� ���������� �� ����� � ������ 
	void handle(std::string request) override;//�������������� �������-����������
	Handler *SetNext(Handler *handler) override;//������������� ��������� �� ��. �����������

	friend std::string converter(Cashbox *ob);//�������� ������� �� �������
};