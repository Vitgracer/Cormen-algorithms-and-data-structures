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
	for (int i = 0; i < n; i++) L[i][i] = 1;

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
// --------------------------- SOLVE-LU (p 857) ---------------------------------
// Brief description: A = LU, Ax = b, LUx = b. Ux = y => Ly = b => find y, find x
//-------------------------------------------------------------------------------
// avg = teta (n ^ 2)
//----------------------------------------------------------------------------
std::vector<double> Matrix::solveLowerUpperMatrices(std::vector<std::vector<double>> L,
													std::vector<std::vector<double>> U,
													std::vector<double> b) {
	const int n = L.size();
	std::vector<double> x(n, 0);
	std::vector<double> y(n, 0);

	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j <= i - 1; j++) {
			sum += L[i][j] * y[j];
		}
		y[i] = b[i] - sum;
	}

	for (int i = n - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum += U[i][j] * x[j];
		}
		x[i] = (y[i] - sum) / U[i][i];
	}
	return x;
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

// ------------ TRANSPOSE -------------
// Brief description: matrix transpose 
//-------------------------------------
// avg = teta (n ^ 2)
//-------------------------------------
std::vector<std::vector<double>> Matrix::transpose(std::vector<std::vector<double>> A) {
	const int n = A.size();
	decltype(A) result = std::vector<std::vector<double>>(n, std::vector<double>(0, n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[j][i] = A[i][j];
		}
	}

	return result;
}

// ----------------MULTIPLY ----------------
// Brief description: matrix multiplication
//------------------------------------------
// avg = teta (n ^ 3)
//------------------------------------------
std::vector<std::vector<double>> Matrix::multiply(std::vector<std::vector<double>> A, decltype(A) B) {
	const int Awidth = A[0].size();
	const int Aheight = A.size();

	const int Bwidth = B[0].size();
	const int Bheight = B.size();

	decltype(A) result = std::vector<std::vector<double>>(Awidth, std::vector<double>(0, Bheight));

	if (Awidth != Bheight) return result;

	for (int y = 0; y < Awidth; y++) {
		for (int x = 0; x < Bheight; x++) {
			for (int k = 0; k < Awidth; k++) {
				result[y][x] += A[y][k] * B[k][x];
			}
		}
	}

	return result;
}

// -------------------------------- INVERSE --------------------------
// Brief description: matrix inverse, using LU-decomposition technique
//--------------------------------------------------------------------
// avg = teta (n ^ 3)
//--------------------------------------------------------------------
std::vector<std::vector<double>> Matrix::inverse(std::vector<std::vector<double>> A) {
	const int n = A.size();
	decltype(A) result;

	// create In matrix 
	decltype(A) ones = std::vector<std::vector<double>>(n, std::vector<double>(0, n));
	for (int i = 0; i < n; i++) ones[i][i] = 1;

	// apply LU-decomposition for each row 
	for (int i = 0; i < n; i++) {
		auto xCol = solveLU(A, ones[i]);
		result.push_back(xCol);
	}

	return result;
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available matrix
// algorithms and compare their timings in console output 
// -------------------------------------------------------
void launchAllMatrixAlgorithms() {
	//-------------------------------------------------
	const int matrixSize = 4;
	std::vector<std::vector<double>> A = 
	{{2, 3,  1, 5}, 
	 {6, 13, 5,  19}, 
	 {2, 19, 10, 23}, 
	 {4, 10, 11, 31}};

	std::vector<double> b = {1,2,3,4};
	decltype(b) gt = { 175.0 / 8, -13.0 / 4, 32, -13 };

	//-------------------------------------------------
	auto start = clock();
	auto result = Matrix::solveLU(A, b);
	auto end = clock() - start;
	std::cout << "LUP-decomposition procedure: " << end << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (result == gt);

	if (check) std::cout << "All Matrix algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}