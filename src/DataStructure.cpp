#include <iostream>
#include "DataStructure.h"

node::node(Item i, node* n) : item(i), next(n) {}

void li::deleteNode(Node n) {
	n->next = n->next->next;
	delete n->next;
}

void li::insert(Node src, Node ins) {
	ins->next = src->next;
	src->next = ins;
}

Node li::next(Node n) {
	return n->next;
}

Item li::item(Node n) {
	return n->item;
}

void li::show(Node n) {
	// consider we have 0 on the finished Node 
	for (Node t = n; t != 0; t = t->next) {
		std::cout << t->item << "\t";
	}
}