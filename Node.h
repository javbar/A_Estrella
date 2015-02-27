#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node
{
	public:
		char *origin, *destiny;
		int cost;
		Node *next;

		Node(){}
		~Node(){}
};

#endif
