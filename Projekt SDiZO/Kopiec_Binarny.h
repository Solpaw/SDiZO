#pragma once
#ifndef Kopiec_Binarny_h
#define Kopiec_Binarny_h
class Kopiec_Binarny
{
	int size;
	int *table;
public:
	Kopiec_Binarny();
	void setHeap();
	void show();
	void add(int num);
	void remove(int num);
	bool find(int num);
	void findMain(int num);
	~Kopiec_Binarny();
};

#endif