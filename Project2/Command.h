#ifndef COMMAND_H
#define COMMAND_H
#include"Pizza.h"
#include"Repository.h"
#include"PizzaRepository.h"

class Command
{
	PizzaRepository pizzaRepository;
public:
	Command(int maxCapacity = 100);
	~Command();
	void AddPizza(Pizza& pizza);
	void RemovePizza(int idx);
	void PrintPizza();
	//string GetLowestPricePizza();
	//ostream& operator<<(ostream& out);
	//friend ifstream& operator >> (ifstream& fin, Pizza& other); // читання даних з файлу
	//ostream& operator>>(ostream& in);
	
	
};

#endif // !COMMAND_H