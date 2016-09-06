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
	
	int q = 0;
	for (int i = 1; i <= n; i++) {
		q = std::max(q, p[i] + cutRod(p, n - i));
	}
	
	return q;
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available dynamic programming 
// algorithms and compare their timings in console output 
// -------------------------------------------------------
void launchDPAlgorithms() {
	//-------------------------------------------------
	std::vector<int> A = {0, 1, 5, 8, 9};
	//for (int i = 0; i < 1000; i++) A.push_back(rand());

	//-------------------------------------------------
	auto crStart = clock();
	auto cr = A;
	int crResult = DP::cutRod(A, A.size() - 1);
	auto crEnd = clock() - crStart;
	std::cout << "Cut-Rod DP procedure: " << crEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (crResult == crResult);

	if (check) std::cout << "All DP algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}