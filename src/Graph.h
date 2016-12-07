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

class DenseGraph {
private:
	int Vcnt;
	int Ecnt;
	bool digraph;
	std::vector<std::vector<bool>> adj;
public:
	DenseGraph(int V, bool digraphIn = false)
		: adj(V)
		, Vcnt(V)
		, Ecnt(0)
		, digraph(digraphIn) {
		for (int i = 0; i < V; i++) {
			adj[i].assign(V, false);
		}
	}
	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	int directed() const { return digraph; }
	
	void insert(Edge e) {
		int v = e.v;
		int w = e.w;
		if (adj[v][w] == false) Ecnt++;
		adj[v][w] = true;
		if (!digraph) adj[w][v] = true;
	}

	void remove(Edge e) {
		int v = e.v;
		int w = e.w;
		if (adj[v][w] == true) Ecnt--;
		adj[v][w] = false;
		if (!digraph) adj[w][v] = false;
	}

	bool edge(int v, int w) const {
		return adj[v][w];
	}

	class adjIterator;
	friend class adjIterator;
};