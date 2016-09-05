#include <vector>

class Selection {
private:
	static int randomizedSelect(std::vector<int> A, int p, int r, int i);
public:
	friend void launchAllSelectionAlgorithms();
};
