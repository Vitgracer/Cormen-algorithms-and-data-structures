///////////////////////////////////////
// ------------- GRAPH ---------------
///////////////////////////////////////
struct Edge {
	int v;
	int w;
	Edge(int vIn = -1, int wIn = -1) 
	: v(vIn) 
	, w(wIn) 
	{}
};

class GRAPH {
private:
public:
	GRAPH(int, bool);
	~GRAPH();
	int V() const;
	int E() const;
	bool directed() const;
	int insert(Edge);
	int remove(Edge);
	bool edge(int, int);

	class adjIteartor {
	public:
		adjIteartor(const GRAPH&, int);
		int beg();
		int nxt();
		bool end();
	};
};