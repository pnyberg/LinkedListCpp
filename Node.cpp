#include "Node.h"

#include <iostream>

using namespace std;

Node::Node() {
	nextAdded = false;
	prevAdded = false;

	value = -1;
}

Node::Node(int amount) {
	nextAdded = false;
	prevAdded = false;

	value = amount;
}

Node::Node(const Node& n) {
	next = n.getNext();
	prev = n.getPrev();
	value = n.value;
}

Node::Node(Node& n) {
	next = n.getNext();
	prev = n.getPrev();
	value = n.value;
}

Node::~Node() {
	if (nextAdded) {
		next = NULL;
	}
	if (prevAdded) {
		prev = NULL;
	}
}


void Node::setPrev(Node* node) {
	prev = node;
	prevAdded = true;
}

void Node::setNext(Node* node) {
	next = node;
	nextAdded = true;
}

void Node::removePrev() {
	prev = NULL;
	prevAdded = false;
}

void Node::removeNext() {
	next = NULL;
	nextAdded = false;
}

Node* Node::getPrev() const {
	return prev;
}

Node* Node::getNext() const {
	return next;
}

/*int main() {
	Node n(5);

	Node m;

	m.value = 10;

	Node k = n;
	Node* l = &n;
	Node* j = new Node();
	j = l;

	n.value = 15;

	cout << n.value << endl;
	cout << m.value << endl;
	cout << k.value << endl;
	cout << l->value << endl;

	cout << "--- Nexting ---" << endl;
	k.setNext(&m);

	n.setNext(&k);

	cout << n.value << endl;
	cout << n.getNext()->value << endl;
	cout << n.getNext()->getNext()->value << endl;
	cout << n.getNext()->getNext()->getNext()->value << endl;

	return 0;
}*/