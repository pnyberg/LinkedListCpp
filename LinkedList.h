#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

#include <iostream>

class LinkedList {
		Node * first;
		Node * last;
		int listSize;

		bool isSame(const Node, const Node);
	public:
		LinkedList();
		void add(Node*);
		void add(Node*, int);
		void swap(int, int);
		void replace(Node, int);
		void remove(int);
		void clear();
		int size();
		bool contains(const Node);
		Node* getFirst();
		Node* getLast();
		Node* get(int);
};

#endif /* LINKEDLIST_H */