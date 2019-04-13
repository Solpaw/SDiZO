#include "pch.h"
#include "List.h"
#include <iostream>
#include <fstream>
using namespace std;

// konstruktor wczytujacy liczby z pliku do listy
List::List()
{
	ifstream plik;
	plik.open("Liczby.txt");
	if (!plik.is_open())
	{
		exit(EXIT_FAILURE);
	}
	int number;
	plik >> number;
	int counter = number;
	for (int i = 0; i < counter; i++)
	{
		plik >> number;
		addBack(number);
	}
	plik.close();
}

// funkcja dodajaca nowa liczbe na poczatek listy
void List::addFront(int num)
{
		Element *temp = new Element;
		temp->data = num;
		temp->next = head;
		head = temp;
		size++;
}

// funkcja wypisujaca liste w konsoli
void List::show()
{
	cout << endl;
	Element *temp;
	temp = head;
	while(temp)
	{		cout << temp->data << " ";
			temp = temp->next;
	}
	cout << endl;
}

// funkcja sprawdzajaca  czy dana liczba jest w liscie
bool List::find(int num)
{
	Element *temp = new Element;
	temp = head;
	while (temp)
	{
		if (temp->data == num)return true;
		temp = temp->next;
	}
	return false;
}

// funkcja dodajaca liczbe na koniec listy
void List::addBack(int num)
{
	Element *temp = new Element;
	Element *cur = new Element;
	if (size == 0)
	{
		addFront(num);
		return;
	}
	temp->next = nullptr;
	temp->data = num;
	cur = head;
	while (cur->next) cur = cur->next;
	cur->next = temp;
	size++;
}


// funkcja dodajaca dana liczbe na dane miejsce
void List::addRandom(int number,int place)
{
	Element *temp = new Element;
	temp->data = number;
	Element *cur = new Element;
	cur = head;
	if (place == 0)
	{
		addFront(number);
		return;
	}
	if (place == size || place == size+1)
	{
		addBack(number);
		return;
	}
	for (int i = 0; i < place-1; i++)
	{
		cur = cur->next;
	}
	temp->next = cur->next;
	cur->next = temp;
	size++;

}

// funkcja zwracajaca rozmiar listy
int List::getSize()
{
	return size;
}


// funkcja usuwajaca liczbe z przodu listy
void List::removeFront()
{
	if (size > 0)
	{
		Element *temp;
		temp = head;
		
		head = temp->next;
		delete temp;
		size--;
	}
	else cout << endl << "Lista jest pusta!" << endl;
	
}

// funkca usuwajaca liczbe z konca listy
void List::removeBack()
{
	if (size == 1)
	{
		removeFront();
	}
	else if (size > 0)
	{
		Element *temp, *cur;
		temp = head;
		for (int i = 0; i < size - 2; i++)
		{
			temp = temp->next;
		}
		cur = temp->next;
		delete cur;
		temp->next = nullptr;
		size--;
	}
	else cout << endl << "Lista jest pusta!" << endl;
}


// funkca usuwajaca liczbe z danego miejsca w liscie
void List::removeRandom(int place)
{
	if (place > size || place <0)
	{
		cout << endl << "Nieprawidlowe miejsce" << endl;
		return;
	}
	if (size > 0)
	{
		Element *temp = new Element;
		Element *cur = new Element;
		cur = head;
		if (place == 0)
		{
			removeFront();
			return;
		}
		if (place == size || place == size + 1)
		{
			removeBack();
			return;
		}
		for (int i = 0; i < place - 1; i++)
		{
			cur = cur->next;
		}
		temp = cur->next;
		cur->next = temp->next;
		delete temp;
		size--;
	}
	else cout << endl << "Lista jest pusta!" << endl;
	
	
}


List::~List()
{

}
