#ifndef COMMAND_H
#define COMMAND_H
#include"Pizza.h"
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
};

#endif // !COMMAND_H