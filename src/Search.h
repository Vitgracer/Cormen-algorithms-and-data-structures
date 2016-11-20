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
};
