#include"Pizza.h"
#include"Error.h"
#include<string>
#include<iostream>
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