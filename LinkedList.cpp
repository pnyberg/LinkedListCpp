#include "LinkedList.h"
#include "Node.h"

#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	listSize = 0;
	first = NULL;
	last = NULL;
}

void LinkedList::add(Node* n) {
	if (listSize == 0) {
		first = n;
	} else {
		(*last).setNext(n);
	}

	last = n;

	listSize++;
}

void LinkedList::add(Node* node, int index) {
	Node* currentNode = get(index);
	Node* previousNode = currentNode->getPrev();

	(*node).setPrev(previousNode);
	(*previousNode).setNext(node);

	(*node).setNext(currentNode);
	(*currentNode).setPrev(node);

	listSize++;
}

void swap(int, int);
void replace(Node, int);
void remove(int);

void LinkedList::clear() {
	Node* currentNode = first;
	Node* previousNode;
	for (int i = 0 ; i < (listSize - 1) ; i++) {
		previousNode = currentNode;
		currentNode = currentNode->getNext();

		previousNode->removePrev();
		previousNode->removeNext();
	}

	currentNode->removePrev();
	currentNode->removeNext();

	first = NULL;
	last = NULL;
	listSize = 0;
}

bool LinkedList::isSame(const Node n1, const Node n2) {
	if (n1.getNext() != n2.getNext()) {
		return false;
	}
	if (n1.getPrev() != n2.getPrev()) {
		return false;
	}
	if (n1.value != n2.value) {
		return false;
	}

	return true;
}

bool LinkedList::contains(const Node n) {
	if (listSize == 0) {
		return false;
	}

	Node* current = first;

	if (isSame(*current, n)) {
		return true;
	}

	for (int i = 1 ; i < listSize ; i++) {
		current = current->getNext();

		if (isSame(*current, n)) {
			return true;
		}
	}

	return false;
}

Node* LinkedList::getFirst() {
	return first;
}

Node* LinkedList::getLast() {
	return last;
}

Node* LinkedList::get(int index) {
	Node* currentNode = first;

	for (int i = 0 ; i < index ; i++) {
		currentNode = currentNode->getNext();
	}

	return currentNode;
}

int LinkedList::size() {
	return listSize;
}

int main() {
	cout << "<< Linking lists <<" << endl;

	LinkedList list;

	list.add(new Node());

	Node test;
	Node* n1 = &test;

	Node* n2 = new Node();

	(*n1).value = 5;
	(*n2).value = 7;

	list.add(n1);
	list.add(n2);

	cout << "The Linked List" << endl;
	for (int i = 0 ; i < list.size() ; i++) {
		cout << i << ": " << list.get(i)->value << endl;
	}

	cout << "contain-test" << endl;
	cout << list.contains(*n1) << endl;
	cout << list.contains(*new Node()) << endl;
	cout << list.contains(*list.get(0)) << endl;

	cout << "Clear list" << endl;
	list.clear();
	cout << list.size() << endl;
}