#ifndef PIZZA_H
#define PIZZA_H

#include<string>
#include<fstream>
using namespace std;

class Pizza
{
private:
	string name;
	int size;
	int pieces_num;
	int value;
public:
	Pizza(string name = "", int size = 0, int pieces_num = 0);
	string ToString();
	int PizzaValue(string name, int size, int pieces_num);
	friend ofstream& operator << (ofstream& fout, Pizza& other); // ����� ����� � ����
	//ostream& operator<<(ostream& out);
	friend ifstream& operator >> (ifstream& fin, Pizza& other); // ������� ����� � �����
	//ostream& operator>>(ostream& in);
};

#endif // !PIZZA_H
