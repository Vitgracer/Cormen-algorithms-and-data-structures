#include <vector>

class Greedy {
private:
	static std::vector<int> recursiveActivitySelector(std::vector<int> s, std::vector<int> f, int k, int n);
public:
	friend void launchAllGreedyAlgorithms();
};
