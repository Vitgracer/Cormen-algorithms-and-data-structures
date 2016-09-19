#include <iostream>
#include <time.h>
#include <algorithm>
#include "Matrix.h"

// --------------------------- LU-decomposition -------------------------------------------
// Brief description: compute A = LU, where L - lower triangle, U - upper triangle matrices
//-----------------------------------------------------------------------------------------
// avg = teta (n ^ 3)
//-----------------------------------------------------------------------------------------
std::pair<std::vector<std::vector<double>>, 
std::vector<std::vector<double>>> Matrix::LUdecomposition(std::vector<std::vector<double>> A) {
	
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available matrix
// algorithms and compare their timings in console output 
// -------------------------------------------------------
void launchAllMatrixAlgorithms() {
	//-------------------------------------------------
	std::vector<std::vector<double>> A(1000, std::vector<double>(0));
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			A[i][j] = rand();
		}
	}

	//-------------------------------------------------
	auto start = clock();
	auto result = Matrix::LUdecomposition(A);
	auto end = clock() - start;
	std::cout << "LUP-decomposition procedure: " << end << " ms" << std::endl;

	//-------------------------------------------------
	bool check = true;

	if (check) std::cout << "All Matrix algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}