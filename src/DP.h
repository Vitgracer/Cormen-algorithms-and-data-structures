#include <vector>

class DP {
private:
	// non-effective recursive algorithm
	static int cutRod(std::vector<int> p, int n);

	// store calculated values in "r"-array
	static int memoizedCutRod(std::vector<int> p, int n);
	static int memoizedCutRodAux(std::vector<int> p, std::vector<int> r, int n);
public:
	friend void launchDPAlgorithms();
};
