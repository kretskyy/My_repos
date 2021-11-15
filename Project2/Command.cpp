#include"Repository.h"
#include"Command.h"
#include"Pizza.h"
#include"Error.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

Command::Command(int maxCapacity): pizzaRepository(maxCapacity)
{
	
}
Command::~Command()
{
	
}
void Command::AddPizza(Pizza& pizza)
{
	pizzaRepository.Add(pizza);
}
void Command::RemovePizza(int idx)
{
	pizzaRepository.Remove(idx);
}
void Command::PrintPizza()
{
	pizzaRepository.Print();
}

/*string Command::GetLowestPricePizza()
{
	//to do:implement correct logic
	//return pizzas[0].GetLowestPrice();
}*/

/*ostream& Command::operator<<(ostream& out)
{
	return out << pizza();
}*/

/*ofstream& operator<<(ofstream& fout, Pizza& other) // запис даних у файл
{
	fout << other.ToString();
	return fout;
}*/

/*ostream& Command::operator>>(ostream& in)
{

}*/

/*ifstream& operator >> (ifstream& fin, Pizza& other) // читання даних з файлу
{
	int max = 100;
	char* buff = new char[max + 1];

	fin.get(buff, max);
	other.ToString() = buff;
	fin.get();

	fin.getline(buff, max);

	delete[] buff;
	return fin;
}*/


/*void Command::ReadFromFile()
{
	//open file
	char buff[100];
	ifstream fin("pizza.txt");
	//loop pizzas from file
	string localstr;
	while (!fin.eof())
	{
		localstr = "";
		getline(fin, localstr);
		cout << localstr << endl;
	}
	//close file
	fin.close();
}*/

