#pragma once
#include"Error.h"
#include<iostream>  
#include<fstream>
using namespace std;

template <class T>
class Repository
{
	T* entities;
	int maxCapacity;
	int currentCapacity;
	bool sync = true;

	void SyncWrite()
	{
		if (sync)
			WriteToFile();
	}

	void SyncRead()
	{
		if (sync)
		{
			currentCapacity = 0;
			ReadFromFile();
		}
	}

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
		SyncWrite();
	}
	void Remove(int idx)
	{
		if (idx < 0 || idx >= currentCapacity)
			throw Error(ErrorCode::IdxOutsideLimit);

		for (int i = idx; i < (currentCapacity - 1); i++)
			entities[i] = entities[i + 1];
		currentCapacity--;
		SyncWrite();
	}
	void Print()
	{
		SyncRead();
		cout << GetTitle() << endl;
		for (int i = 0; i < currentCapacity; i++)
		{
			cout << i << "--" << entities[i].ToString() << endl;
		}
	}

protected:
	virtual string GetTitle() { return ""; }
	virtual string GetFileName() {return "";}

	void WriteToFile()
	{
		ofstream fout(GetFileName());
		for (int i = 0; i < currentCapacity; i++)
		{
			fout << entities[i];
			if (i + 1 != currentCapacity)
				fout << endl;

		}
		fout.close(); 
	}

	void ReadFromFile()
	{
		bool prevSync = sync;
		sync = false;

		ifstream fin(GetFileName());
		while (!fin.eof())
		{
			T item;
			fin >> item;
			Add(item);
		}
		fin.close();

		sync = prevSync;
	}
	
};