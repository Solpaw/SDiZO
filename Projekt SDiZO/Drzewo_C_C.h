#pragma once
#ifndef Drzewo_C_C_H
#define Drzewo_C_C_H
#include <string>
using namespace std;
class Drzewo_C_C
{public:
	struct node
	{
		node *up;
		node *left;
		node *right;
		char color;
		int data;
	};
private:
	node guard;
	node *root;
	int size;
	string cr, cl, cp;
public:
	Drzewo_C_C();
	~Drzewo_C_C();
	void deleteTree(node *p);
	void rotateLeft(node *a);
	void rotateRight(node *a);
	void add(int k);
	void remove(int k);
	node * nextNode(node *n)
	{
		node *r;
		if (n != &guard)
		{
			if (n->right != &guard)return minNode(n->right);
			else
			{
				r = n->up;
				while ((r != &guard) && (n == r->right))
				{
					n = r;
					r = r->up;
				}
				return r;
			}
		}
		return &guard;
	}
	node * minNode(node *n)
	{
		if (n != &guard)
		{
			while (n->left != &guard) n = n->left;
		}
		return n;
	}
	node *findN(int k, node *n)
	{
		node * p;

		p = root;
		while ((p != &guard) && (p->data != k))
			if (k < p->data) p = p->left;
			else           p = p->right;
		if (p == &guard) return NULL;
		return p;
	}
	void find(int k,node *root);
	node *getRoot()
	{
		return root;
	}
	void print();
	void printNode(string sp, string sn, node *n);
};

#endif
