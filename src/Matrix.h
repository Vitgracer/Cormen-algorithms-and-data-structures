#include <vector>

class Matrix {
private:
	static std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> LUdecomposition(std::vector<std::vector<double>> A);
public:
	friend void launchAllMatrixAlgorithms();
};
