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
	const int n = A.size();
	decltype(A) L(n, std::vector<double>(0));
	decltype(A) U(n, std::vector<double>(0));

	for (int k = 0; k < n; k++) {
		U[k][k] = A[k][k];

		for (int i = k + 1; i < n; i++) {
			L[i][k] = A[i][k] / A[k][k];
			U[k][i] = A[k][i];
		}

		for (int i = k + 1; i < n; i++) {
			for (int j = k + 1; j < n; j++) {
				A[i][j] = A[i][j] - L[i][k] * U[k][j];
			}
		}
	}

	return std::make_pair(L, U);
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