#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Node.h"

#include<iostream>
#include<iomanip>

#include<string.h>
#include<fstream>

using namespace std;

class List
{
private:
	int size;

public:
	Node *first;
	Node *last;

	List();
	~List();
	int insertFirstNode(char *origin, char *destiny, int cost);
	int	insertAtTop(char *origin, char *destiny, int cost);
	int insertAtBottom(char *origin, char *destiny, int cost);
	int deleteTop();
	void readList(char *name);
	void printList();

};

List::List()
{
	first = NULL;
	last = NULL;
	size = 0;

	readList("rutas.txt");
}

int List::insertFirstNode(char *origin, char *destiny, int cost)
{
	Node *newNode;

	if ((newNode = new Node[1]) == NULL)
		return -1;

	if ((newNode->origin = new char[50]) == NULL)
		return -1;

	if ((newNode->destiny = new char[50]) == NULL)
		return -1;


	strcpy(newNode->origin, origin);
	strcpy(newNode->destiny, destiny);
	newNode->cost = cost;

	newNode->next = NULL;

	first = newNode;
	last = newNode;
	size++;

	return 0;
}

int List::insertAtTop(char *origin, char *destiny, int cost)
{
	Node *newNode;

	if ((newNode = new Node[1]) == NULL)
		return -1;

	if ((newNode->origin = new char[50]) == NULL)
		return -1;

	if ((newNode->destiny = new char[50]) == NULL)
		return -1;

	strcpy(newNode->origin, origin);
	strcpy(newNode->destiny, destiny);
	newNode->cost = cost;

	newNode->next = first;
	first = newNode;
	size++;

	return 0;
}

int List::insertAtBottom(char *origin, char *destiny, int cost)
{
	Node *newNode, *actual;
	actual = last;

	if ((newNode = new Node[1]) == NULL)
		return -1;

	if ((newNode->origin = new char[50]) == NULL)
		return -1;

	if ((newNode->destiny = new char[50]) == NULL)
		return -1;

	strcpy(newNode->origin, origin);
	strcpy(newNode->destiny, destiny);
	newNode->cost = cost;

	actual->next = newNode;
	newNode->next = NULL;
	last = newNode;
	size++;
	return 0;
}

int List::deleteTop()
{
	if (size == 0)
		return -1;

	Node *deleteNode;
	deleteNode = first;
	first = first->next;

	if (size == 1)
		last = NULL;

	delete[] deleteNode->origin;
	delete[] deleteNode->destiny;
	delete[] deleteNode;
	size--;
	return 0;
}

List::~List()
{
	while (size > 0)
		deleteTop();
}

void List::printList()
{
	Node *actual;

	actual = first;

	while (actual != NULL)
	{
		cout << "Origin: " << setw(10) << actual->origin << " Destiny: " << setw(10) << actual->destiny << " Cost: " << setw(3) << actual->cost << endl;
		actual = actual->next;
	}
}

void List::readList(char *name)
{
	char origin[50], destiny[50];
	int cost;
	int count = 0;

	ifstream input(name);

	while (!input.eof())
	{
		input >> origin;

		if (origin[0] == '\0')
			break;

		input >> destiny;
		input >> cost;

		if (size == 0)
			insertFirstNode(origin, destiny, cost);

		else
			insertAtBottom(origin, destiny, cost);
	}
	input.close();
}

#endif
