#include <stdlib.h>

static int maxKey = 1000;
typedef int Key;

class Item {
private:
	Key keyval;
	float info;
public:
	Item() : keyval(maxKey) {}
	Key key() const { return keyval; }
	int null() const { return keyval == maxKey; }
	void rand() { 
		keyval = 1000 * ::rand() / RAND_MAX; 
		info = 1.0 * ::rand() / RAND_MAX; 
	}
};

/////////////////////////////////////////
//--- SYMBOL-TABLE (based on array)-----
/////////////////////////////////////////
class STarray {
private:
	Item nullItem;
	Item* st;
	int M;
public:
	STarray() 
		: M(nullItem.key())
		, st(new Item[M]) {}
	
	int count() const {
		int n = 0; 
		for (int i = 0; i < M; i++) {
			if (!st[i].null()) n++;
		}
		return n;
	}
	void insert(Item x) { st[x.key()] = x; }
	Item search(Key v) const { return st[v]; }
	void remove(Item x) { st[x.key()] = nullItem; }
	Item select(int k) {
		for (int i = 0; i < M; i++) {
			if (!st[i].null())
				if (k-- == 0) return st[i];
		}
		return nullItem;
	}
};
