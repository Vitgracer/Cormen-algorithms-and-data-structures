#include <vector>

class DP {
private:
	// non-effective recursive algorithm
	static int cutRod(std::vector<int> p, int n);

	// store calculated values in "r"-array
	static int memoizedCutRod(std::vector<int> p, int n);
	static int memoizedCutRodAux(std::vector<int> p, std::vector<int> r, int n);
	
	// another practice to store calculated values 
	static int bottomUpCutRod(std::vector<int> p, int n);

	// find longest common subsequence 
	static std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> LCSlength(std::vector<int>& X, std::vector<int>& Y);

	// Fibonacci 
	static int findFibonacciIter(int N);
	static int findFibonacciRec(int N);
	static int findFibonacciTopDown(int N);

	// knap problem 
	static struct Item { int size; int val; };
	std::vector<Item> capItems = { {3, 4}, {4,5}, {7,10}, {8,11}, {9, 13} };
	static int knap(int cap);
public:
	friend void launchDPAlgorithms();
};
