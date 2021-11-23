#pragma once
#include"Repository.h"
#include"Pizza.h"
#include<string>
using namespace std;

class PizzaRepository: public Repository<Pizza>
{
protected:
	string GetFileName() { return "C:\\Users\\Akret\\source\\repos\\Project2\\Project2\\Pizza.txt"; }
	string GetTitle() { return "Pizza: "; }
public:
	PizzaRepository(int max) : Repository(max)
	{
		ReadFromFile();
	}
	~PizzaRepository() 
	{
		WriteToFile();
	}
	
};