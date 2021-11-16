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
	//string GetLowestPrice();
	void operator+(Pizza& pizza);
	//void operator-(Pizza& pizza);
};

#endif // !COMMAND_H