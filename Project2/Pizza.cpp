#include"Pizza.h"
#include"Error.h"
#include<string>
#include<fstream>
using namespace std;

Pizza::Pizza(string name, int size, int pieces_num)
{
	this->name = name;
	this->size = size;
	this->pieces_num = pieces_num;
	if (size * pieces_num * 25 < 0)
		throw Error(ErrorCode::NegativeValue);

	value = size * pieces_num * 25;
}

int Pizza::PizzaValue(string name, int size, int pieces_num)
{
	return value = size * pieces_num * 25;
}

string Pizza::ToString()
{
	return "Pizza: " + name + " " + to_string(size) + " " + to_string(pieces_num) + " " + to_string(value);
}

ofstream& operator << (ofstream& fout, Pizza& pizza)
{
	fout << pizza.name << " " << pizza.size << " " << pizza.pieces_num << " " << pizza.value << endl;
	return fout;
}

/*ostream& Pizza::operator<<(ostream& out)
{
	return out<< name << " " << size << " " << pieces_num << " " << value << endl;
}*/

ifstream& operator>>(ifstream& fin, Pizza& pizza)
{
	int max = 100;
	char* buff = new char[max + 1];

	fin.get(buff, max, ',');
	pizza.name = buff;
	fin.get();

	fin.getline(buff, max);
	pizza.size = atoi(buff);

	fin.getline(buff, max);
	pizza.pieces_num = atoi(buff);

	fin.getline(buff, max);
	pizza.value = atoi(buff);

	delete[] buff;
	return fin;
}