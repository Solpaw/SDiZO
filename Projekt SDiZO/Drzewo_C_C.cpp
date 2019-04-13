#include "pch.h"
#include "Drzewo_C_C.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// destruktor wpisujacy liczby z pliku do drzewa
Drzewo_C_C::Drzewo_C_C()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	guard.color = 'B';
	guard.up = &guard;
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;
	
	
	ifstream plik;
	plik.open("Liczby.txt");
	if (!plik.is_open())
	{
		exit(EXIT_FAILURE);
	}
	int i = 0;
	plik >> i;
	int number;
	for (int j = 0; j < i; j++)
	{
		plik >> number;
		add(number);
	}
}

// destruktor wywolujacy funkcje zwalniajacy pamiec
Drzewo_C_C::~Drzewo_C_C()
{
	deleteTree(root);
}

// funkcja zwalniajaca pamiec
void Drzewo_C_C::deleteTree(node * n)
{
	if (n != &guard)
	{
		deleteTree(n->right);
		deleteTree(n->left);
		delete n;
	}
}

// funkcja przesuwajaca drzewo w prawo wzgledem danego elementu
void Drzewo_C_C::rotateRight(node * a)
{
	node *b, *c;
	b = a->left;
	if (b != &guard)
	{
		c = a->up;
		a->left = b->right;
		if (a->left != &guard)a->left->up = a;
		b->right = a;
		b->up = c;
		a->up = b;
		if (c != &guard)
		{
			if (c->left == a) c->left = b;
			else c->right = b;
		}
		else root = b;
	}
}


// dodanie liczby do drzewa
void Drzewo_C_C::add(int k)
{
	{
		node * temp, *uncle;

		temp = new node;        
		temp->left = &guard;          
		temp->right = &guard;
		temp->up = root;
		temp->data = k;
		if (temp->up == &guard) root = temp; 
		else
			while (true)             
			{
				if (k < temp->up->data)
				{
					if (temp->up->left == &guard)
					{
						temp->up->left = temp;  
						break;
					}
					temp->up = temp->up->left;
				}
				else
				{
					if (temp->up->right == &guard)
					{
						temp->up->right = temp; 
						break;
					}
					temp->up = temp->up->right;
				}
			}
		temp->color = 'R';        
		while ((temp != root) && (temp->up->color == 'R'))
		{
			if (temp->up == temp->up->up->left)
			{
				uncle = temp->up->up->right; 
				if (uncle->color == 'R')  
				{
					temp->up->color = 'B';
					uncle->color = 'B';
					temp->up->up->color = 'R';
					temp = temp->up->up;
					continue;
				}

				if (temp == temp->up->right) 
				{
					temp = temp->up;
					rotateLeft(temp);
				}

				temp->up->color = 'B'; 
				temp->up->up->color = 'R';
				rotateRight(temp->up->up);
				break;
			}
			else
			{                  
				uncle = temp->up->up->left;

				if (uncle->color == 'R') 
				{
					temp->up->color = 'B';
					uncle->color = 'B';
					temp->up->up->color = 'R';
					temp = temp->up->up;
					continue;
				}

				if (temp == temp->up->left) 
				{
					temp = temp->up;
					rotateRight(temp);
				}

				temp->up->color = 'B'; 
				temp->up->up->color = 'R';
				rotateLeft(temp->up->up);
				break;
			}
		}
		root->color = 'B';
	}
	
	size++;
	
	}


// usuniecie liczby z drzewa
void Drzewo_C_C::remove(int k)
{
	node *temp = findN(k, root);
	if (temp == nullptr)
	{
		cout << "Nie znaleziono tej liczby!" << endl;
		return;
	}
	node *w, *y, *z;
	if ((temp->left == &guard) || temp->right == &guard) y = temp;
	else y = nextNode(temp);

	if (y->left != &guard) z = y->left;
	else z = y->right;

	z->up = y->up;

	if (y->up == &guard) root = z;
	else if (y == y->up->left) y->up->left = z;
	else y->up->right = z;

	if (y != temp) temp->data = y->data;

	if(y->color=='B')
		while((z!=root)&&(z->color=='B'))
			if (z == z->up->left)
			{
				w = z->up->right;

				if (w->color == 'R')
				{
					w->color = 'B';
					z->up->color = 'R';
					rotateLeft(z->up);
					w = z->up->right;
				}

				if ((w->left->color == 'B') && (w->right->color == 'B'))
				{
					w->color = 'R';
					z = z->up;
					continue;
				}

				if (w->right->color == 'B')
				{
					w->left->color = 'B';
					w->color = 'R';
					rotateRight(w);
					w = z->up->right;
				}

				w->color = z->up->color;
				z->up->color = 'B';
				w->right->color = 'B';
				rotateLeft(z->up);
				z = root;
			}
			else
			{
				w = z->up->left;

				if (w->color == 'R')
				{
					w->color = 'B';
					z->up->color = 'R';
					rotateRight(z->up);
					w = z->up->left;
				}
				if ((w->left->color == 'B') && (w->right->color == 'B'))
				{
					w->color = 'R';
					z = z->up;
					continue;
				}

				if (w->left->color == 'B')
				{
					w->right->color = 'B';
					w->color = 'R';
					rotateLeft(w);
					w = z->up->left;
				}

				w->color = z->up->color;
				z->up->color = 'B';
				w->left->color = 'B';
				rotateRight(z->up);
				z = root;
			}
	z->color = 'B';
	delete y;
	size--;


}

// funkcja szukajaca czy dana liczba jest w drzewie
void Drzewo_C_C::find(int k,node *n)
{

	node *temp = findN(k, root);
	if (temp == nullptr)
	{
		cout << "Nie znaleziono tej liczby!" << endl;
		return;
	}
	else cout << endl << "Znaleziono!" << endl;
	
}


// funkcja wywolujaca funkcje pokazujacej drzewo
void Drzewo_C_C::print()
{
	printNode("","",root);
	
}

// funkcja rysujaca drzewo
void Drzewo_C_C::printNode(string sp, string sn, node * n)
{
	
	string t;

	if (n != &guard)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		printNode(t + cp, cr, n->right);

		t = t.substr(0, sp.length() - 2);
		cout << t << sn << n->color << ":" << n->data << endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		printNode(t + cp, cl, n->left);
	}

}





// funkcja przesuwajaca drzewo w lewo wzgledem danego elementu
void Drzewo_C_C::rotateLeft(node * a)
{
	node *b, *c;
	b = a->right;
	if (b != &guard)
	{
		c = a->up;
		a->right = b->left;
		if (a->right != &guard) a->right->up = a;
		b->left = a;
		b->up = c;
		a->up = b;
		if (c != &guard)
		{
			if (c->left == a) c->left = b;
			else c->right = b;
		}
		else root = b;
	}
}
