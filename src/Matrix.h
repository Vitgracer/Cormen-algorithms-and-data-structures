#include <vector>

class Matrix {
private:
	// LU-decomposition methods
	static std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> LUdecomposition(std::vector<std::vector<double>> A);
	static std::vector<double> solveLU(std::vector<std::vector<double>> A, std::vector<double> b);
	static std::vector<double> solveLowerUpperMatrices(std::vector<std::vector<double>> L,
													   std::vector<std::vector<double>> U,
													   std::vector<double> b);

	// Matrix operations 
	static std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> A);
	static std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> A, decltype(A) B);
	static std::vector<std::vector<double>> inverse(std::vector<std::vector<double>> A);
public:
	friend void launchAllMatrixAlgorithms();
};
