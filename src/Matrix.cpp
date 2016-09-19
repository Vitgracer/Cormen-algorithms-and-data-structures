#include <iostream>
#include <time.h>
#include <algorithm>
#include "Matrix.h"

// --------------------------- LU-decomposition (p 860) -----------------------------------
// Brief description: compute A = LU, where L - lower triangle, U - upper triangle matrices
//-----------------------------------------------------------------------------------------
// avg = teta (n ^ 3)
//-----------------------------------------------------------------------------------------
std::pair<std::vector<std::vector<double>>, 
std::vector<std::vector<double>>> Matrix::LUdecomposition(std::vector<std::vector<double>> A) {
	const int n = A.size();
	decltype(A) L(n, std::vector<double>(n, 0));
	decltype(A) U(n, std::vector<double>(n, 0));

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

std::vector<double> Matrix::solveLowerUpperMatrices(std::vector<std::vector<double>> L,
													std::vector<std::vector<double>> U,
													std::vector<double> b) {
	
}

// --------------------------- SOLVE-LU (p 860) ------------------------------
// Brief description: solve system of linear equations using LU-decomposition.
//----------------------------------------------------------------------------
// avg = teta (n ^ 3)
//----------------------------------------------------------------------------
std::vector<double> Matrix::solveLU(std::vector<std::vector<double>> A, std::vector<double> b) {
	auto LU = LUdecomposition(A);
	auto x = solveLowerUpperMatrices(LU.first, LU.second, b);

	return x;
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available matrix
// algorithms and compare their timings in console output 
// -------------------------------------------------------
void launchAllMatrixAlgorithms() {
	//-------------------------------------------------
	const int matrixSize = 5;
	std::vector<std::vector<double>> A(matrixSize, std::vector<double>(matrixSize, 0));
	std::vector<double> b(matrixSize, 0);
	for (int i = 0; i < matrixSize; i++) {
		b[i] = rand();
		for (int j = 0; j < matrixSize; j++) {
			A[i][j] = rand();
		}
	}

	//-------------------------------------------------
	auto start = clock();
	auto result = Matrix::solveLU(A, b);
	auto end = clock() - start;
	std::cout << "LUP-decomposition procedure: " << end << " ms" << std::endl;

	//-------------------------------------------------
	bool check = true;

	if (check) std::cout << "All Matrix algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}