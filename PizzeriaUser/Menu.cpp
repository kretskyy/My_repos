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
	cout << "1 - Print pizza;\n";
	//cout << "4 - Get pizza with the lowest price;\n";
	cout << "0 - Exit.\n";
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
		command.PrintPizza();
		cout << endl;
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