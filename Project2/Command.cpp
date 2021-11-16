#include"Command.h"
#include"Pizza.h"
#include"Error.h"
#include<iostream>
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

/*string command::getlowestprice()
{
	//to do:implement correct logic
	//return pizzas[0].getlowestprice();
}*/
