#include <vector>

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

template <class Graph> 
std::vector<Edge> edges(GRAPH& G) {
	int E = 0;
	vector<Edge> a(G.E());
	for (int v = 0; v < G.V(); v++) {
		typename Graph::adjIterator A(G, v);
		for (int w = A.beg(); w != A.end(); w = A.nxt()) {
			if (G.directed() || v < w) {
				a[E++] = Edge(v, w);
			}
		}
	}
	return a;
}