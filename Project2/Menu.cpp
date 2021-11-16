#include "Menu.h"
#include"Pizza.h"
#include"Error.h"
#include<iostream>
#include<string>
using namespace std;

void Menu::ShowMenu()
{
	char userInput;

	do {
		showMainMenu();
		cin >> userInput;
		safeHandleUserInput(userInput);
		cout << endl;
	} while (userInput != '0');
}
void Menu::showMainMenu()
{
	cout << "Welcome to pizzeria 'Shablezubyk'!!!\nPlease select an option:\n";
	cout << "1 - Add new pizza;\n";
	cout << "2 - Print pizza;\n";
	cout << "3 - Remove pizza;\n";
	//cout << "4 - Get pizza with the lowest price;\n";
	cout << "0 - Exit.\n";
}
void Menu::showAndHandleAddPizzaMenu()
{
	string name;
	int size, pieces_num;
	cout << "Name:\n";
	cin >> name;
	cout << "Size:\n";
	cin >> size;
	cout << "Number of pieces:\n";
	cin >> pieces_num;

	Pizza pizza(name, size, pieces_num);
	
	command.AddPizza(pizza); //command + pizza;
	cout << "Pizza Added!!!\n";
}

void Menu::showAndHandleRemovePizzaMenu()
{
	int idx;
	cout << "Type pizza ID:\n";
	cin >> idx;

	command.RemovePizza(idx); //command - idx;
	cout << "Pizza Removed!!!\n";
}

void Menu::safeHandleUserInput(char userInput)
{
	try
	{
		handleUserInput(userInput);
	}
	catch (Error& error)
	{
		cout << "Error occurs: " << error.ToString() << endl;
	}
	catch (...)
	{
		cout << "Some error occurs!" << endl;
	}
}

void Menu::handleUserInput(char userInput)
{
	switch (userInput)
	{
		case '1':
			showAndHandleAddPizzaMenu();
			break;
		case '2':
			command.PrintPizza();
			cout << endl;
			break;
		case '3':
			showAndHandleRemovePizzaMenu();
			break;
		/*case '4':
			cout << "Pizza with the lowest price is: " << command.GetLowestPricePizza() << endl;
			break;*/
		case '0':
			break;
		default:
			cout << "Invalid command entered!!!\n";
			break;
	}
}