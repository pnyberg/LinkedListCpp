#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
		Node* next;
		Node* prev;
		bool nextAdded;
		bool prevAdded;
	public:
		int value;

		Node();
		Node(int);
		Node(const Node&);
		Node(Node&);
		~Node();

		void setPrev(Node*);
		void setNext(Node*);
		void removePrev();
		void removeNext();
		Node* getPrev() const;
		Node* getNext() const;
};

#endif /* NODE_H */