#include <iostream>
#include <time.h>
#include <algorithm>
#include "DP.h"

//---------------------- CUT-ROD (p 396) -----------------------------------
// Brief description: we have a vector with price of rod part after cutting.
// Vector index means the length of the rod part. The main goal is 
// to maximize total price for sell.
// -------------------------------------------------------------------------
// Input : 
// Length (i)   | 1 | 2 | 3 | ... | n
// Price  (p_i) | 1 | 5 | 8 | ... | p_n
// -------------------------------------------------------------------------
int DP::cutRod(std::vector<int> p, int n) {
	if (n == 0) return 0;
	
	int q = -1;
	for (int i = 1; i <= n; i++) {
		q = std::max(q, p[i] + cutRod(p, n - i));
	}
	
	return q;
}

//---------------------MEMOIZED-CUT-ROD-AUX (WRAPPER) ------------------------
// Brief description: wrapper for memoizedCutRodAux() function
// ---------------------------------------------------------------------------
int DP::memoizedCutRod(std::vector<int> p, int n) {
	std::vector<int> r(n + 1, -1);
	return memoizedCutRodAux(p, r, n);
}

//---------------------- MEMOIZED-CUT-ROD-AUX (p 396) ------------------------
// Brief description: the same as a previoius task, but now we use DP to store
// tree values in additional arrat to avoid multiple recomputatation.
// ---------------------------------------------------------------------------
int DP::memoizedCutRodAux(std::vector<int> p, std::vector<int> r, int n) {
	// check if the cutRod for n was computed 
	if (r[n] >= 0) return r[n];
	
	int q;
	if (n == 0) q = 0; // crutch for convinient writing to "r"
	else {
		q == -1;
		for (int i = 1; i <= n; i++) {
			q = std::max(q, p[i] + memoizedCutRodAux(p, r, n - i));
		}
	}

	// write computed value 
	r[n] = q;

	return q;
}

//---------------------- BOTTOM-UP-CUT-ROD (p 399) ----------------------------
// Brief description: one more effective DP algorithm with another technique 
// of calculated elements storage 
// ---------------------------------------------------------------------------
int DP::bottomUpCutRod(std::vector<int> p, int n) {
	std::vector<int> r(n + 1, -1);
	r[0] = 0;

	for (int j = 1; j <= n; j++) {
		int q = -1;

		for (int i = 1; i <= j; i++) {
			q = std::max(q, p[i] + r[j - i]);
		}
		r[j] = q;
	}
	return r[n];
}

//---------------------- LCS-LENGTH (p 428)---------------------------------
// Brief description: main goal is to find the longest common subsequence of 
// two sequences.
// -------------------------------------------------------------------------
// Input : X = 1 2 0 2 1, Y = 1 3 0 2 1, Result = 1 0 2
// avg = O( m * n )
// -------------------------------------------------------------------------
std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> DP::LCSlength(std::vector<int>& X, std::vector<int>& Y) {
	const int m = X.size();
	const int n = Y.size();
	
	std::vector<int> cN(n + 1, 0);
	std::vector<std::vector<int>> c(m + 1, cN);

	std::vector<int> bN(n + 1, 0);
	std::vector<std::vector<int>> b(m + 1, bN);
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (X[i] == Y[j]) {
				c[i + 1][j + 1] = c[i][j] + 1;
				b[i + 1][j + 1] = -1; // /
			}
			else if (c[i][j + 1] >= c[i + 1][j]) {
				c[i + 1][j + 1] = c[i][j + 1];
				b[i + 1][j + 1] = -2; // |
			}
			else {
				c[i+1][j+1] = c[i+1][j];
				b[i+1][j+1] = -3; // -
			}
		}
	}
	return std::make_pair(c, b);
}

//---------------------- PRINT-LCS (p 429)--------------
// Brief description: recursively print all LCS 
// -----------------------------------------------------
// avg = O( m + n )
// -----------------------------------------------------
void printLCS(std::vector<std::vector<int>> b, std::vector<int> X, int i, int j) {
	if (i == 0 || j == 0) return;
	if (b[i][j] == -1) {
		printLCS(b, X, i - 1, j - 1);
		std::cout << X[i - 1] << " ";
	}
	else if (b[i][j] == -2) {
		printLCS(b, X, i - 1, j);
	}
	else if (b[i][j] == -3) printLCS(b, X, i, j - 1);
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available dynamic programming 
// algorithms and compare their timings in console output 
// -------------------------------------------------------
void launchDPAlgorithms() {
	//-------------------------------------------------
	std::vector<int> A;
	for (int i = 0; i < 10; i++) A.push_back(rand());

	//-------------------------------------------------
	auto crStart = clock();
	auto cr = A;
	int crResult = DP::cutRod(A, A.size() - 1);
	auto crEnd = clock() - crStart;
	std::cout << "Cut-Rod DP procedure: " << crEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto crmStart = clock();
	auto crm = A;
	int crmResult = DP::memoizedCutRod(A, A.size() - 1);
	auto crmEnd = clock() - crmStart;
	std::cout << "Memoized Cut-Rod DP procedure: " << crmEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto bucrStart = clock();
	auto bucr = A;
	int bucrResult = DP::bottomUpCutRod(A, A.size() - 1);
	auto bucrEnd = clock() - bucrStart;
	std::cout << "Bottom-up Cut-Rod DP procedure: " << bucrEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto lcsStart = clock();
	std::vector<int> Y = { 1, 3, 2, 0, 1, 0};
	std::vector<int> X = { 0, 1, 2, 1, 3, 0, 1 };
	auto lcsResult = DP::LCSlength(X, Y);
	std::cout << "algorithm result: ";
	printLCS(lcsResult.second, X, X.size(), Y.size());
	std::cout << std::endl << "GT result: " << "1 2 1 0" << std::endl;
	auto lcsEnd = clock() - lcsStart;
	std::cout << "LCS-length DP procedure: " << lcsEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (crResult == crmResult) &&
			     (crResult == bucrResult);

	if (check) std::cout << "All DP algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}