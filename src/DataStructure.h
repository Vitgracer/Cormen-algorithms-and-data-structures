struct node {
	int item;
	node* next;

	node(int i, node* n);
};
typedef node* link;
typedef link Node;

namespace li {
	void deleteNode(Node n);
	void insert(Node src, Node ins);
	link reverse(link x);
	Node next(Node n);
	int item(Node n);
	void show(Node n);
}
 
template <class Item>
class Stack {
	Stack(int);
	int empty();
	void push(Item);
	Item pop();
};
