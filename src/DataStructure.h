
typedef int Item;

struct node {
	Item item;
	node* next;

	node(Item i, node* n) : 
		item(i), 
		next(n) {}
};

typedef node* link;