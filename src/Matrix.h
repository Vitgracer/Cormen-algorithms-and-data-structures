#include <vector>

class Matrix {
private:
	static std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> LUdecomposition(std::vector<std::vector<double>> A);
	static std::vector<double> solveLU(std::vector<std::vector<double>> A, std::vector<double> b);
	static std::vector<double> solveLowerUpperMatrices(std::vector<std::vector<double>> L,
													   std::vector<std::vector<double>> U,
													   std::vector<double> b);
public:
	friend void launchAllMatrixAlgorithms();
};
