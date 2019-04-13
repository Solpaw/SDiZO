#include "pch.h"
#include "Tablica.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;



// konstruktor tablicy, funkcja otwiera plik z folderu programu i wpisuje dane z niego
// do tablicy
Tablica::Tablica()
{
	ifstream plik;
	plik.open("Liczby.txt");
	if (!plik.is_open())
	{
		exit(EXIT_FAILURE);
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
	plik.close();
}

// funkca dodająca nowy element na początek tablicy, w tym celu alokuje nową pamięć o 1 miejsce
// większą niż poprzednio
void Tablica::addOnStart(int x)
{
	int *temp = new int[size + 1];
	temp[0] = x;
	for (int i = 1; i < size+1; i++)
	{
		temp[i] = table[i-1];
	}
	size += 1;
	delete[]table;
	table = temp;
	cout << endl << "Dodano!" << endl;
}

// funkcja dodająca nowy element na koniec tablicy
void Tablica::addOnEnd(int x)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = table[i];
	}
	temp[size] = x;
	size = size + 1;
	delete[]table;
	table = temp;
	cout << endl << "Dodano!" << endl;
}


// funkcja dodająca nowy element na losowe miejsce w tablicy
void Tablica::addRandom(int x)
{
	srand(time(NULL));
	int where = rand() % (size - 1);
	int *temp = new int[size + 1];
	int j = 0;
	for (int i = 0; i < size + 1; i++)
	{
		if (i == where)
		{
			temp[i] = x;
			continue;
		}
		temp[i] = table[j];
		j++;
	}
	size += 1;
	delete[]table;
	table = temp;
	cout << endl << "Dodano!" << endl;
}


// funkcja usuwająca element z początku tablicy
void Tablica::removeFromStart()
{
	if (size <= 0)
	{
		cout << endl << "Tablica jest pusta" << endl;
		return;
	}
	int *temp = new int[size-1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = table[i + 1];
	}
	size -= 1;
	delete[]table;
	table = temp;
	cout << endl << "Usunieto!" << endl;
}


// funkcja usuwająca losowy element z  tablicy
void Tablica::removeRandom()
{
	srand(time(NULL));
	if (size <= 0)
	{
		cout << endl << "Tablica jest pusta" << endl;
		return;
	}
	
	int where;
	if (size > 1)
	{
		where = rand() % (size - 1);
	}
	else where = 0;
	cout << endl << where << endl;
	int *temp = new int[size -1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{

		if (i != where)
		{
			temp[j] = table[i];
		}
		else j--;
		j++;
	}
	size -= 1;
	delete[]table;
	table = temp;
	temp = NULL;
	cout << endl << "Usunieto!" << endl;

}


// funkca usuwająca element z końca tablicy
void Tablica::removeFromEnd()
{
	if (size <= 0)
	{
		cout << endl << "Tablica jest pusta" << endl;
		return;
	}
	int *temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = table[i];
	}
	size -= 1;
	delete[]table;
	table = temp;
	cout << endl << "Usunieto!" << endl;
}


// funkca zwraca "prawda" lub  "fałsz" w zależności od tego czy element o wartości podanej
// przez użytkownika znajduje się w tablicy
void Tablica::find(int x)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == x) 
		{
			cout << endl << "Znaleziono!";
			return;
		}
	}
	cout << endl << "Nie znaleziono" << endl;
}


// funkca wyświetlająca tablicę w konsoli
void Tablica::show()
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << table[i] << " ";
	}
}


// funkcja dodająca nowy element na wybrane przez użytkownika miejsce w tablicy
void Tablica::add(int x, int y)
{
	int where = y;
	int *temp = new int[size + 1];
	int j = 0;
	for (int i = 0; i < size + 1; i++)
	{
		if (i == where)
		{
			temp[i] = x;
			continue;
		}
		temp[i] = table[j];
		j++;
	}
	size += 1;
	delete[]table;
	table = temp;
	cout << endl << "Dodano!" << endl;
}


// funkcja usuwająca element o wartości podanej przez użytkownika
void Tablica::remove(int x)
{
	
	if (size <= 0)
	{
		cout << endl << "Tablica jest pusta" << endl;
		return;
	}

	int where = x;
	cout << endl << where << endl;
	int *temp = new int[size - 1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{

		if (i != where)
		{
			temp[j] = table[i];
		}
		else j--;
		j++;
	}
	size -= 1;
	delete[]table;
	table = temp;
	temp = NULL;
	cout << endl << "Usunieto!" << endl;

}


// funkcja zwracająca rozmiar tablicy
int Tablica::getSize()
{
	return size;
}

// destruktor zwalniający pamięć po tablicy
Tablica::~Tablica()
{
	delete[] table;
	table = NULL;
}
