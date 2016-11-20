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
template <class Item>
class STarray {
private:
	Item nullItem;
	Item* st;
	int m;
public:
	ST()
};
