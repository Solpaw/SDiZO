#include "pch.h"
#include "Kopiec_Binarny.h"
#include <fstream>
#include <iostream>
#include "Kopiec_Binarny.h"
#include <cmath>
using namespace std;

// funkcja wczytujaca liczby z pliku do tablicy
Kopiec_Binarny::Kopiec_Binarny()
{
	ifstream plik;
	plik.open("Liczby.txt");
	if (!plik.is_open())
	{

	}
	int number;
	plik >> number;
	size = number;
	table = new int[size];

	int i = 0;
	while (plik >> number)
	{
		table[i] = number;
		i++;
	}
}


// funkcja ustawiajaca liczby w kolejnosci kopca
void Kopiec_Binarny::setHeap()
{
	bool flag = false;
	do
	{
		flag = false;
		for (int i = 0; i < size; i++)
		{
			if (table[2 * i + 1] > table[i] && 2*i+1<size)
			{
				int temp = table[i];
				table[i] = table[2 * i + 1];
				table[2 * i + 1] = temp;	
				flag = true;
			}
			else if (table[2 * i + 2] > table[i] && 2 * i + 2 < size)
			{
				int temp = table[i];
				table[i] = table[2 * i + 2];
				table[2 * i + 2] = temp;
				flag = true;
			}
		}
	} while (flag);
}

// funkcja pokazujaca kopiec
void Kopiec_Binarny::show()
{
	int nrOfRows = 0;
	int i = 0;
	while (size - (pow(2,i)) > 0)
	{
		i++;
		nrOfRows++;
	}
	int number=0;
	int nrOfSpaces = size;
	int nrOfNr = 0;
	cout << endl;
	for (int i = 0; i < nrOfRows; i++)
	{
		if (i == 0)nrOfNr = 1;
		else if (i == 1)nrOfNr = 2;
		else if (i >= 2)nrOfNr = pow(2, i);
		for (int j = 0; j < nrOfNr; j++)
		{
			for (int k = 0; k < nrOfSpaces;k++) cout << " ";
			if (number < size)
			{
				cout << table[number];
				number++;
			}
			else return;
		}
		cout << endl;
		nrOfSpaces = nrOfSpaces / 2;
	}
}


// funkcja dodajaca liczbe do kopca
void Kopiec_Binarny::add(int num)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = table[i];
	}
	temp[size] = num;
	delete[]table;
	table = temp;
	size++;
	bool counter = true;
	int cur = size-1;
	while (counter)
	{
		counter = false;
		if (table[cur] > table[(cur-1) / 2] && (cur - 1) / 2 >= 0)
		{
			int t = table[cur];
			table[cur] = table[(cur - 1) / 2];
			table[(cur - 1) / 2] = t;
			cur = (cur - 1) / 2;
			counter = true;
		}
	}
}

// funkcja usuwajaca liczbe z kopca
void Kopiec_Binarny::remove(int num)
{
	if (size == 0)
	{
		cout << endl << "Kopiec jest pusty!" << endl;
		return;
	}
	
	if (!find(num))
	{
		cout << endl << "Nie znaleziona takiej liczby!" << endl;
		return;
	}
	int j = 0;
	bool done=false;
	int *temp = new int[size-1];
	for (int i = 0; i < size; i++)
	{
		if (table[i] == num && !done)
		{
			done = true;
			continue;
		}
		temp[j] = table[i];
		j++;
	}
	delete[]table;
	table = temp;
	size--;
	setHeap();

}


// funkcja sprawdzajaca czy dana liczba znajduje sie w kopcu
bool Kopiec_Binarny::find(int num)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == num)return true;
	}
	return false;
}

void Kopiec_Binarny::findMain(int num)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == num)
		{
			cout << endl << "Znaleziono!" << endl;
			return;
		}
		
	}
	cout << endl << "Nie znaleziono!" << endl;
}

// destruktor zwalniajacy pamiec
Kopiec_Binarny::~Kopiec_Binarny()
{
	delete[]table;
}
