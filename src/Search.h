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
