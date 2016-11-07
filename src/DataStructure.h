typedef int Item;

struct node {
	Item item;
	node* next;

	node(Item i, node* n);
};
typedef node* link;
typedef link Node;

namespace li {
	void deleteNode(Node n);
	void insert(Node src, Node ins);
	Node next(Node n);
	Item item(Node n);
	void show(Node n);
}
 