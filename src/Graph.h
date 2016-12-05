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
std::vector<Edge> edges(Graph& G) {
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

template <class Graph>
class IO {
public:
	static void show(Graph&);
	static void scanEZ(Graph&);
	static void scan(Graph&);
};

template <class Graph> 
void IO<Graph>::show(const Graph& G) {
	for (int s = 0; s < G.V(); s++) {
		std::cout << s << " : ";
		typename Graph::adjIterator(G, s);
		for (int t = A.beg(); t != A.end(); t = A.nxt()) {
			std::cout << t << " ";
		}
		std::cout << std::endl;
	}
}

template <class Graph> 
class CC {
private:
public:
	CC(const Graph&);
	int count();
	bool connect(int, int);
};