#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "Tablica.h"
#include "List.h"
#include "Kopiec_Binarny.h"
#include "Drzewo_C_C.h"
#include <chrono>
using namespace std;

string mainMenu = "1. Tablica \n2. Lista\n3. Kopiec binarny\n4. Drzewo Czerwono-Czarne\n5. Zakoncz";


// funkcja obsługująca GUI Drzewa Czerwono Czarnego
void drzewoMenu()
{
	string drzewoM = "1. Dodaj\n2. Usun\n3. Wyszukaj\n4. Pokaz\n5. Cofnij";
	Drzewo_C_C tree;
	cout << endl << drzewoM << endl;
	int exit = 1;
	int number;
	
	while (exit != 0)
	{

		char choice = _getch();
		switch (choice)
		{

		case '1':
			
			{
				cout << endl << "Podaj liczbe: " << endl;
				cin >> number;
				auto start = std::chrono::high_resolution_clock::now();
				tree.add(number);
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				cout << "Czas dodawania: " << elapsed.count() << " s\n";
				break;
			}
			break;
		case '2':
			{
				cout << endl << "Podaj liczbe: " << endl;
				cin >> number;
				auto start = std::chrono::high_resolution_clock::now();
				tree.remove(number);
				auto finish = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsed = finish - start;
				cout << "Czas odejmowania: " << elapsed.count() << " s\n";
				break;
			}
			break;
		case '3':
		{
			cout << endl << "Podaj liczbe: " << endl;
			cin >> number;
			auto start = std::chrono::high_resolution_clock::now();
			tree.find(number, tree.getRoot());
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout << "Czas szukania: " << elapsed.count() << " s\n";
			break;
		}
		case '4':
			tree.print();
			break;
		case '5':
			exit = 0;
			cout << endl << mainMenu << endl;
			break;
		default:
			break;
		}
	}
}


// funkcja obsługująca GUI kopca
void heapMenu()
{
	string heapM = "1. Dodaj\n2. Usun\n3. Wyszukaj\n4. Pokaz\n5. Cofnij\n";
	Kopiec_Binarny heap;
	heap.setHeap();
	cout << endl << heapM << endl;
	int exit = 1;
	int number;
	while (exit != 0)
	{

		char choice = _getch();
		switch (choice)
		{

		case '1':
		{
			cout << endl << "Podaj liczbe: " << endl;
			cin >> number;
			auto start = std::chrono::high_resolution_clock::now();
			heap.add(number);
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout << "Czas dodawania: " << elapsed.count() << " s\n";
			break;
		}
		case '2':
		{
			cout << endl << "Podaj liczbe: " << endl;
			cin >> number;
			auto start = std::chrono::high_resolution_clock::now();
			heap.remove(number);
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout << "Czas odejmowania: " << elapsed.count() << " s\n";
			break;
		}
		case '3':
		{
			cout << endl << "Podaj liczbe: " << endl;
			cin >> number;
			auto start = std::chrono::high_resolution_clock::now();
			heap.findMain(number);
			auto finish = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = finish - start;
			cout << "Czas szukania: " << elapsed.count() << " s\n";
			break;
		}
		case '4':
			heap.show();
			break;
		case '5':
			exit = 0;
			cout << endl << mainMenu << endl;
			break;
		default:
			break;
		}
	}
}

void countAddStartList(int number, List list)
{

	auto start = std::chrono::high_resolution_clock::now();
	list.addFront(number);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas dodawania: " << elapsed.count() << " s\n";
}

void countAddEndList(int number, List list)
{

	auto start = std::chrono::high_resolution_clock::now();
	list.addBack(number);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas dodawania: " << elapsed.count() << " s\n";
}

void countAddRandomList(int number, List list)
{

	auto start = std::chrono::high_resolution_clock::now();
	list.addRandom(number, 500);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas dodawania: " << elapsed.count() << " s\n";
}

void countRemoveEndList(List list)
{

	auto start = std::chrono::high_resolution_clock::now();
	list.removeBack();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas usuwania: " << elapsed.count() << " s\n";
}

void countFindList(int number, List list)
{

	auto start = std::chrono::high_resolution_clock::now();
	if (list.find(number)) cout << endl << "Znaleziono" << endl;
	else cout << endl << "Nie znaleziono" << endl;
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas szukania: " << elapsed.count() << " s\n";
}

void countRemoveFrontList(List list)
{

	auto start = std::chrono::high_resolution_clock::now();
	list.removeFront();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas usuwania: " << elapsed.count() << " s\n";
}

void countRemoveRandomList(List list)
{

	auto start = std::chrono::high_resolution_clock::now();
	list.removeRandom(500);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas usuwania: " << elapsed.count() << " s\n";
}

// funkcja obsługująca GUI listy jednokierunkowej
void listMenu()
{
	string listM = "1. Dodaj\n2. Usun\n3. Wyszukaj\n4. Pokaz\n5. Cofnij";
	string obliczenia = "1. Dodaj na start\n2. Dodaj na koniec\n3. Dodaj w srodku\n4. Usun z poczotku\n5. Usun z srodka\n6. Usun z konca\n7. Wyszukaj";
	List list;
	cout << endl << listM << endl;
	int exit = 1;
	int number, place;
	
	while (exit != 0)
	{

		char choice = _getch();
		char cho;
		switch (choice)
		{

		case '1':
			cout << "Podaj liczbe" << endl;
			cin >> number;
			cout << "Podaj miejsce" << endl;
			cin >> place;
			while(place <0 || place > list.getSize())
			{
				cout << "Podaj prawidlowe miejsce" << endl;
				cin >> place;
			}
			list.addRandom(number, place);
			break;
		case '2':
			cout << "Podaj miejsce: " << endl;
			cin >> place;
			list.removeRandom(place);
			break;
		case '3':
			cout << "Podaj liczbe" << endl;
			cin >> number;
			if (list.find(number))cout << endl << "Znaleziono!" << endl;
			else cout << endl << "Nie znaleziono!" << endl;
			break;
		case '4':
			list.show();
			break;
		case '5':
			exit = 0;
			cout << endl << mainMenu << endl;
			break;
		default:
			break;
		}
	}
}

void countAddStartArray(int number, Tablica table)
{

	auto start = std::chrono::high_resolution_clock::now();
	table.addOnStart(number);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas dodawania: " << elapsed.count() << " s\n";
}

void countAddEndArray(int number, Tablica table)
{

	auto start = std::chrono::high_resolution_clock::now();
	table.addOnEnd(number);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas dodawania: " << elapsed.count() << " s\n";
}

void countAddRandomArray(int number, Tablica table)
{

	auto start = std::chrono::high_resolution_clock::now();
	table.addRandom(number);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas dodawania: " << elapsed.count() << " s\n";
}

void countRemoveEndArray(Tablica table)
{

	auto start = std::chrono::high_resolution_clock::now();
	table.removeFromEnd();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas usuwania: " << elapsed.count() << " s\n";
}

void countFindArray(int number, Tablica table)
{

	auto start = std::chrono::high_resolution_clock::now();
	table.find(number);
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas szukania: " << elapsed.count() << " s\n";
}

void countRemoveFrontArray(Tablica table)
{

	auto start = std::chrono::high_resolution_clock::now();
	table.removeFromStart();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas usuwania: " << elapsed.count() << " s\n";
}

void countRemoveRandomArray(Tablica table)
{

	auto start = std::chrono::high_resolution_clock::now();
	table.removeRandom();
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Czas usuwania: " << elapsed.count() << " s\n";
}

// funkcja obsługująca obsługę tablicy dynamicznej
void tableMenu()
{
	string tableM = "1. Dodaj\n2. Usun\n3. Wyszukaj\n4. Pokaz\n5. Cofnij\n";
	string obliczenia = "1. Dodaj na start\n2. Dodaj na koniec\n3. Dodaj w srodku\n4. Usun z poczotku\n5. Usun z srodka\n6. Usun z konca\n7. Wyszukaj";

	Tablica table;

	cout << endl << tableM << endl;
	int exit = 1;
	int number, place;
	int i = 0;
	while (exit != 0)
	{

		char choice = _getch();
		char choice2;
		int x = 1;
		switch (choice)
		{

		case '1':
			cout << endl << "Podaj liczbe: " << endl;
			cin >> number;
			cout << endl << "Podaj miejsce: " << endl;
			cin >> place;
			while (place < 0 || place >= table.getSize())
			{
				cout << endl << "Podaj prawidlowe miejsce" << endl;
				cin >> place;
			}
			table.add(number, place);
			break;
		case '2':
			cout << endl << "Podaj miejsce: " << endl;
			cin >> place;
			if (table.getSize() != 0)
			{
				while (place < 0 || place >= table.getSize())
				{
					cout << endl << "Podaj prawidlowe miejsce: " << endl;
					cin >> place;
				}
			}

			table.remove(place);
			break;
		case '3':
			cout << endl << "Podaj liczbe: " << endl;
			cin >> number;
			table.find(number);
			break;
		case '4':
			table.show();
			break;
		case '5':
			exit = 0;
			cout << endl << mainMenu << endl;
			break;
			/*		case '6':

						while (x)
						{
							cout << endl << obliczenia << endl;
							choice2 = _getch();
							switch (choice2)
							{
							case '1':
								cout << endl << "Podaj liczbe: ";
								cin >> number;
								countAddStartArray(number, table);
								tableMenu();
								break;
							case '2':
								cout << endl << "Podaj liczbe: ";
								cin >> number;
								countAddEndArray(number, table);
								tableMenu();
								break;
							case '3':
								cout << endl << "Podaj liczbe: ";
								cin >> number;
								countAddRandomArray(number, table);
								tableMenu();
								break;
							case '4':
								countRemoveFrontArray(table);
								tableMenu();
								break;
							case '5':
								countRemoveRandomArray(table);
								tableMenu();
								break;
							case '6':
								countRemoveEndArray(table);
								tableMenu();
								break;
							case '7':
								cout << endl << "Podaj liczbe: ";
								cin >> number;
								countFindArray(number, table);
								tableMenu();
								break;
							case '8':
								x = 0;
								break;
							default:
								break;
							}
							break;
					}*/
		default:
			break;
			
		}
	}
}



// funkcja main
int main()
{
	int exit = 1;
	
	cout << mainMenu << endl;

	while (exit != 0)
	{
		
		char choice = _getch();

		switch (choice)
		{
		case '1':
			tableMenu();
			break;
		case '2':
			listMenu();
			break;
		case '3':
			heapMenu();
			break;
		case '4':
			drzewoMenu();
			break;
		case '5':
			exit = 0;
			break;
		default:
			break;
		}
	}
	
}

