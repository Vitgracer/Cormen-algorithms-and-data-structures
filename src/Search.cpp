#include <iostream>
#include "DataStructure.h"

/////////////////////////
// ---- LINKED-LIST -----
/////////////////////////
node::node(int i, node* n) : item(i), next(n) {}

void li::deleteNode(Node n) {
	n->next = n->next->next;
}

void li::insert(Node src, Node ins) {
	ins->next = src->next;
	src->next = ins;
}

Node li::next(Node n) {
	return n->next;
}

int li::item(Node n) {
	return n->item;
}

void li::show(Node n) {
	// consider we have 0 on the finished Node 
	Node head = n;
	Node t = n;
	do {
		std::cout << item(t) << "\t";
		t = t->next;
	} while (t != head);
}

link li::reverse(link x) {
	link t = x;
	link y = x;
	link r = 0;
	link head = x;

	do {
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	} while (y != head);
	
	return r;
}

///////////////////////////////////////
// ------ BINARY-TREE ----------------
///////////////////////////////////////
BinaryTree::BinaryTree(int in, BinaryTree* nodeL, BinaryTree* nodeR) 
	: item(in)
	, l(nodeL)
	, r(nodeR) {}

void biTree::visit(BinaryTreeLink h) {
	std::cout << h->item << std::endl;
}

void biTree::traverse(BinaryTreeLink h) {
	if (h == 0) return;
	visit(h);
	traverse(h->l);
	traverse(h->r);
}

void biTree::traverseStack(BinaryTreeLink h) {
	Stack<BinaryTreeLink> stack(10);
	stack.push(h);

	while (!stack.empty())
	{
		auto h = stack.pop();
		visit(h);
		if (h->r != 0) stack.push(h->r);
		if (h->l != 0) stack.push(h->l);
	}
}

void biTree::levelTraverseQueue(BinaryTreeLink h) {
	QueueArray<BinaryTreeLink> queue(10);
	queue.put(h);

	while (!queue.empty())
	{
		auto h = queue.get();
		visit(h);
		if (h->r != 0) queue.put(h->r);
		if (h->l != 0) queue.put(h->l);
	}
}

int biTree::count(BinaryTreeLink h) {
	if (h == 0) return 0;
	return count(h->l) + count(h->r) + 1;
}

int biTree::height(BinaryTreeLink h) {
	if (h == 0) return -1;
	int u = height(h->l);
	int v = height(h->r);
	if (u > v) return u + 1;
	else return v + 1;
}