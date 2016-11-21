#include <stdlib.h>

static int maxKey = 1000;
typedef int Key;

class Item {
private:
	Key keyval;
	float info;
public:
	Item() : keyval(maxKey), info(0) {}
	Key key() const { return keyval; }
	int null() const { return keyval == maxKey; }
	void rand() { 
		keyval = 100 * ::rand() / RAND_MAX; 
		info = 1.0 * ::rand() / RAND_MAX; 
	}
};

/////////////////////////////////////////////////
//--- SYMBOL-TABLE (based on array) (S 448)-----
//------------ distributed search --------------
/////////////////////////////////////////////////
template <class Item, class Key>
class STdistributed {
private:
	Item nullItem;
	Item* st;
	int M;
	int size;
public:
	STdistributed(int maxN) 
		: M(nullItem.key())
		, size(maxN)
		, st(new Item[size]) { 
		for (int i = 0; i < size; i++) {
			st[i] = Item();
		}
	}
	
	int count() const {
		int n = 0; 
		for (int i = 0; i < size; i++) {
			if (!st[i].null()) n++;
		}
		return n;
	}
	void insert(Item x) { st[x.key()] = x; }
	Item search(Key v) const { return st[v]; }
	void remove(Item x) { st[x.key()] = nullItem; }
	Item select(int k) {
		for (int i = 0; i < size; i++) {
			if (!st[i].null())
				if (k-- == 0) return st[i];
		}
		return nullItem;
	}
};

/////////////////////////////////////////////////
//--- SYMBOL-TABLE (based on array) (S 450)-----
//--------sequental search, ordered array-------
/////////////////////////////////////////////////
template <class Item, class Key>
class STsequental {
private:
	Item nullItem;
	Item* st;
	int N;
	Item binarySearch(int l, int r, Key v) {
		if (l > r) return nullItem;
		int m = (l + r) / 2;
		if (v == st[m].key()) return st[m];
		if (l == r) return nullItem;
		if (v < st[m].key())
			return binarySearch(0, m - 1, v);
		else
			return binarySearch(m + 1, r, v);

	}
public:
	STsequental(int maxN)
		: N(0)
		, st(new Item[maxN + 1]) {
		for (int i = 0; i < N; i++) {
			st[i] = Item();
		}
	}

	int count() const { return N; }
	void insert(Item x) { 
		int i = N++;
		Key v = x.key();
		while (i > 0 && v < st[i - 1].key()) {
			st[i] = st[i - 1];
			i--;
		}
		st[i] = x;
	}

	Item search(Key v) const { 
		for (int i = 0; i < N; i++) 
			if (v == st[i].key()) return st[i];
		return nullItem;
	}

	Item Bsearch(Key v) {
		return binarySearch(0, N - 1, v);
	}
};

///////////////////////////////////////////////////////
//--- SYMBOL-TABLE (based on linked list) (S 452)-----
//------------------unordered array-------------------
///////////////////////////////////////////////////////
template <class Item, class Key>
class STll {
private:
	Item nullItem;
	struct node {
		Item item;
		node* next;

		node (Item inItem, node* inNext) 
			: item(inItem)
			, next(inNext) {}
	};
	typedef node* link;

	int N;
	link head;

	Item searchR(link t, Key v) {
		if (t == 0) return nullItem;
		if (t->item.key() == v) return t->item;
		return searchR(t->next, v);
	}
public:
	STll(int maxN)
		: N(0)
		, head(0) { }

	int count() const { return N; }
	void insert(Item x) {
		head = new node(x, head);
		N++;
	}

	Item search(Key v) {
		return searchR(head, v);
	}
};

/////////////////////////////////////////////////
//--- BINARY-SEARCH-TREE (BST) (S 462) ---------
/////////////////////////////////////////////////
template <class Item, class Key> 
class BST {
private:
	struct node {
		Item item;
		node* l;
		node* r;

		node(Item inItem)
			: item(inItem)
			, l(0)
			, r(0) {}
	};
	typedef node* link;
	Item nullitem;
	Item searchR(link treeNode, Key inputKey) {
		if (treeNode == 0) return nullitem;
		Key currentKey = treeNode->key();
		if (currentKey == inputKey) return treeNode->item;
		if (inputKey < currentKey)
			return searchR(treeNode->l, inputKey);
		else
			return searchR(treenode->r, inputKey);
	}
};