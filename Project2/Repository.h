#pragma once
#include"Error.h"
#include<iostream>  
#include<fstream>
#include<string>
using namespace std;

template <class T>
class Repository
{
	T* entities;
	int maxCapacity;
	int currentCapacity;

public:
	Repository(int maxCapacity = 100)
	{
		this->maxCapacity = maxCapacity;
		currentCapacity = 0;
		entities = new T[maxCapacity];
	}
	~Repository()
	{
		//WriteToFile(); виносимо в дочірній клас, оскільки деструктор базового класу знищується останнім
		delete[] entities;
	}
	void Add(T& item)
	{
		if (currentCapacity >= maxCapacity)
			throw Error(ErrorCode::MaxSizeReached);
		entities[currentCapacity++] = item;
	}
	void Remove(int idx)
	{
		if (idx < 0 || idx >= currentCapacity)
			throw Error(ErrorCode::IdxOutsideLimit);

		for (int i = idx; i < (currentCapacity - 1); i++)
			entities[i] = entities[i + 1];
		currentCapacity--;
	}
	void Print()
	{
		cout << GetTitle() << endl;
		for (int i = 0; i < currentCapacity; i++)
		{
			cout << i << "--" << entities[i].ToString() << endl;
		}
	}

	void ReadFromFile()
	{
		ifstream filein("Pizza.txt");
		for (string line; getline(filein, line);)
		{
			//cout << line << endl;
			filein >> line;
		}
	}
	void operator+(T& pizza)
	{
		Add(pizza);
	}

	/*void operator-(T& pizza)
	{
		Remove(pizza);
	}*/

protected:
	virtual string GetTitle() { return ""; }
	virtual string GetFileName() {return "";}

	void WriteToFile()
	{
		ofstream fout(GetFileName());
		for (int i = 0; i < currentCapacity; i++)
		{
			fout << entities[i] << endl;

		}
		fout.close(); 
	}
	
};