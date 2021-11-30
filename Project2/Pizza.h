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
	friend ofstream& operator << (ofstream& fout, Pizza& other); // запис даних у файл
	//ostream& operator<<(ostream& out);
	friend ifstream& operator >> (ifstream& fin, Pizza& other); // читання даних з файлу
	//ostream& operator>>(ostream& in);
};

#endif // !PIZZA_H
