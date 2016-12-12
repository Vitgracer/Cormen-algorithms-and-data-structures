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
void IO<Graph>::show(Graph& G) {
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

//////////////////////////////////////////////////////////
/////////////// Graph based on adjscency matrix //////////
//////////////////////////////////////////////////////////
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

class DenseGraph::adjIterator {
private:
	const DenseGraph& G;
	int i;
	int v;
public:
	adjIterator(const DenseGraph& GiN, int vIn) 
		: G(GiN)
		, v(vIn)
		, i(-1) {}

	int beg() { 
		i = -1;
		return nxt();
	}

	int nxt() {
		for (i++; i < G.V(); i++) {
			if (G.adj[v][i] == true) return i;
		}
		return -1;
	}

	bool end() {
		return i >= G.V();
	}
};


//////////////////////////////////////////////////////////
/////////////// Graph based on adjacency list //////////
//////////////////////////////////////////////////////////
class SparseMultiGRAPH{
private:
	int Vcnt;
	int Ecnt;
	bool digraph;
	struct node {
		int v;
		node* next;
		
		node(int inV, node* inNext)
			: v(inV)
			, next(inNext) {}
	};
	typedef node* link;
	std::vector <link> adj;
public:
	SparseMultiGRAPH(int V, bool digraphIn = false)
		: adj(V)
		, Vcnt(V)
		, Ecnt(0)
		, digraph(digraphIn) {
		adj.assign(V, 0);
	}

	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	int directed() const { return digraph; }

	void insert(Edge e) {
		int v = e.v;
		int w = e.w;
		adj[v] = new node(w, adj[v]);
		if (!digraph) adj[w] =new node(v, adj[w]);
		Ecnt++;
	}

	void remove(Edge e);
	bool edge(int v, int w);

	class adjIterator;
	friend class adjIterator;
};

class SparseMultiGRAPH::adjIterator {
private:
	const SparseMultiGRAPH& G;
	int v;
	link t;
public:
	adjIterator(const SparseMultiGRAPH& GiN, int vIn)
		: G(GiN)
		, v(vIn)
		, t(0) {}

	int beg() {
		t = G.adj[v];
		return t ? t->v : -1;
	}

	int nxt() {
		if (t) t = t->next;
		return t ? t->v : -1;
	}

	bool end() {
		return t == 0;
	}
};

template <class Graph>
void randG(Graph& G, int E) {
	double p = 2.0 * E / G.V() / (G.V() - 1);
	for (int i = 0; i < G.V(); i++) {
		for (int j = 0; j < i; j++) {
			if (rand() < p * RAND_MAX) {
				G.insert(Edge(i, j));
			}
		}
	}
}

//////////////////////////////////////////////////////////
/////////////// DFS search simple path ///////////////////
//////////////////////////////////////////////////////////
template <class Graph> 
class sPATH {
private:
	const Graph& G;
	bool isPath;
	std::vector<int> visited;

	bool search(int v, int w) {
		if (v == w) return true;
		visited[v] = true;
		typename Graph::adjIterator A(G, v);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (!visited[t]) {
				if (search(t, w)) return true;
			}
		}
		return false;
	}

public:
	sPATH(const Graph& Gin, int vin, int win)
		: G(Gin)
		, visited(G.V(), false)
		, isPath(false)
	{
		isPath = search(vin, win);
	}
	bool exists() const { return isPath; }
};

//////////////////////////////////////////////////////////
/////////////// DFS search Gamilton path /////////////////
//////////////////////////////////////////////////////////
template <class Graph>
class gPATH {
private:
	const Graph& G;
	bool isPath;
	std::vector<int> visited;

	bool search(int v, int w, int d) {
		if (v == w) return (d == 0);
		visited[v] = true;
		typename Graph::adjIterator A(G, v);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (!visited[t]) {
				if (search(t, w, d - 1)) return true;
			}
		}
		visited[v] = false;
		return false;
	}

public:
	gPATH(const Graph& Gin, int vin, int win, int din)
		: G(Gin)
		, visited(G.V(), false)
		, isPath(false)
	{
		isPath = search(vin, win, din);
	}
	bool exists() const { return isPath; }
};

//////////////////////////////////////////////////////////
/////////////// DFS drawing in 2 colours /////////////////
//////////////////////////////////////////////////////////
template <class Graph>
class BI {
private:
	const Graph& G;
	bool OK;
	std::vector<int> vc;
	bool dfs(int v, int c) {
		vc[v] = (c + 1) % 2;
		typename Graph::adjIterator A(G, v);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (vc[t] == -1) {
				if (!dfs(t, vc[v])) return false;
			}
			else if (vc[t] != c) return false;
		}
		return true;
	}

public:
	BI(const Graph& Gin)
		: G(Gin)
		, OK(true)
		, vc(G.V(), -1) {

		for (int v = 0; v < G.V(); v++) {
			if (vc[v] == -1) {
				if (!dfs(v, 0)) {
					OK = false;
					return;
				}
			}
		}
	}
	
	bool bipartive() const { return OK; }
	int color(int v) const { return vc[v]; }
};