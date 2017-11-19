#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string>
#include"Node.h"
#include<fstream>
using namespace std;
struct BTreeNode
{
	int *data;
	BTreeNode **child_ptr;
	bool leaf;
	int n;
}*root = NULL, *np = NULL, *x = NULL;
BTreeNode * init()
{
	int i;
	np = new BTreeNode;
	np->data = new int[5];
	np->child_ptr = new BTreeNode *[6];
	np->leaf = true;
	np->n = 0;
	for (i = 0; i < 6; i++)
	{
		np->child_ptr[i] = NULL;
	}
	return np;
}
void traverse(BTreeNode *p)
{
	cout << endl;
	int i;
	for (i = 0; i < p->n; i++)
	{
		if (p->leaf == false)
		{
			traverse(p->child_ptr[i]);
		}
		cout << " " << p->data[i];
	}
	if (p->leaf == false)
	{
		traverse(p->child_ptr[i]);
	}
	cout << endl;
}
void sort(int *p, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = i; j <= n; j++)
		{
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
int split_child(BTreeNode *x, int i)
{
	int j, mid;
	BTreeNode *np1, *np3, *y;
	np3 = init();
	np3->leaf = true;
	if (i == -1)
	{
		mid = x->data[2];
		x->data[2] = 0;
		x->n--;
		np1 = init();
		np1->leaf = false;
		x->leaf = true;
		for (j = 3; j < 5; j++)
		{
			np3->data[j - 3] = x->data[j];
			np3->child_ptr[j - 3] = x->child_ptr[j];
			np3->n++;
			x->data[j] = 0;
			x->n--;
		}
		for (j = 0; j < 6; j++)
		{
			x->child_ptr[j] = NULL;
		}
		np1->data[0] = mid;
		np1->child_ptr[np1->n] = x;
		np1->child_ptr[np1->n + 1] = np3;
		np1->n++;
		root = np1;
	}
	else
	{
		y = x->child_ptr[i];
		mid = y->data[2];
		y->data[2] = 0;
		y->n--;
		for (j = 3; j < 5; j++)
		{
			np3->data[j - 3] = y->data[j];
			np3->n++;
			y->data[j] = 0;
			y->n--;
		}
		x->child_ptr[i + 1] = y;
		x->child_ptr[i + 1] = np3;
	}
	return mid;
}
void insert(int a)
{
	int i, temp;
	x = root;
	if (x == NULL)
	{
		root = init();
		x = root;
	}
	else
	{
		if (x->leaf == true && x->n == 5)
		{
			temp = split_child(x, -1);
			x = root;
			for (i = 0; i < (x->n); i++)
			{
				if ((a > x->data[i]) && (a < x->data[i + 1]))
				{
					i++;
					break;
				}
				else if (a < x->data[0])
				{
					break;
				}
				else
				{
					continue;
				}
			}
			x = x->child_ptr[i];
		}
		else
		{
			while (x->leaf == false)
			{
				for (i = 0; i < (x->n); i++)
				{
					if ((a > x->data[i]) && (a < x->data[i + 1]))
					{
						i++;
						break;
					}
					else if (a < x->data[0])
					{
						break;
					}
					else
					{
						continue;
					}
				}
				if ((x->child_ptr[i])->n == 5)
				{
					temp = split_child(x, i);
					x->data[x->n] = temp;
					x->n++;
					continue;
				}
				else
				{
					x = x->child_ptr[i];
				}
			}
		}
	}
	x->data[x->n] = a;
	sort(x->data, x->n);
	x->n++;
}
int main()
{
	int sum = 0;
	ifstream file("Contacts for Project.txt");
	{
		for (unsigned int i = 0; i <16; ++i)
		{
			Node* newNode = new Node();
			file >> newNode->title;
			file >> newNode->surname;
			file >> newNode->givenName;
			file >> newNode->dateOfBirth;
			file >> newNode->address;
			file >> newNode->phoneNumber;
			file >> newNode->emailAddress;
			file >> newNode->occupation;
			file >> newNode->company;
			sum = 0;
			for (unsigned int i = 0; i < newNode->surname.size(); i++) {
				sum += newNode->surname[i];
			}
			newNode->surnameID = sum;
			sum = 0;
			for (unsigned int i = 0; i < newNode->givenName.size(); i++) {
				sum += newNode->givenName[i];
			}
			newNode->givenNameID = sum;
			newNode->ID = i + 1;
			insert(newNode->surnameID);
			/*cout << newNode->title << endl;
			cout << newNode->surname << endl;
			cout << newNode->givenName << endl;
			cout << newNode->dateOfBirth << endl;
			cout << newNode->address << endl;
			cout << newNode->phoneNumber << endl;
			cout << newNode->emailAddress << endl;
			cout << newNode->occupation << endl;
			cout << newNode->company << endl;
			cout << newNode->surnameID << endl;
			cout << newNode->givenNameID << endl;
			cout << newNode->ID << endl;*/

		}
	}

	/*int n, t;
	cout << "enter the no of elements to be inserted\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
	cin >> t;
	insert(t);
	}*/
	insert(499);
	cout << "traversal of constructed tree\n";
	traverse(root);
	getch();
}