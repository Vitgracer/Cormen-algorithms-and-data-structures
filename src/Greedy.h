#include <vector>

class Greedy {
private:
	static std::vector<int> recursiveActivitySelector(std::vector<int> s, std::vector<int> f, int k, int n);
	static std::vector<int> greedyActivitySelector(std::vector<int> s, std::vector<int> f);
public:
	friend void launchAllGreedyAlgorithms();
};
