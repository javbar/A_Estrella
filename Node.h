#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#define ORDER 2
#include<iostream>
using namespace std;

class Node
{
	public:
		int value, height, EF;
		Node *father;
		Node *branch[ORDER];

		Node();
		~Node(){}
};

Node::Node()
{
	father = NULL;
	height = 1;
	EF = 0;
	for (int i = 0; i < ORDER; i++)
		branch[i] = NULL;
}
#endif
