#pragma once
#ifndef Array_h
#define Array_h

class Tablica
{
private:
	int size;
	int *table;
public:
	Tablica();
	void addOnStart(int x);
	void addOnEnd(int x);
	void addRandom(int x);
	void removeFromStart();
	void removeRandom();
	void removeFromEnd();
	void find(int x);
	void show();
	void add(int x, int y);
	void remove(int x);
	int getSize();
	~Tablica();
};


#endif