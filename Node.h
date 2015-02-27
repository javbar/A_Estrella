#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node
{
	public:
		char *origin;
		char *destiny;
		int cost;
		Node *next;

		Node();
		~Node();
};

#endif
