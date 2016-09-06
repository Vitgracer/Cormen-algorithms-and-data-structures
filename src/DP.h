#include <vector>

class DP {
private:
	static int cutRod(std::vector<int> p, int n);
	static int memoizedCutRod(std::vector<int> p, int n);
	static int memoizedCutRodAux(std::vector<int> p, std::vector<int> r, int n);
public:
	friend void launchDPAlgorithms();
};
