#pragma once
#ifndef List_h
#define List_h


class List
{
public:
	struct Element 
	{
		Element *next = nullptr;
		int data;
	};
private:
	Element *head;
	int size;
public:
	List();
	void addFront(int num);
	void show();
	bool find(int num);
	void addBack(int num);
	void addRandom(int number,int place);
	int getSize();
	void removeFront();
	void removeBack();
	void removeRandom(int place);
	~List();
};

#endif