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
	auto crmStart = clock();
	auto crm = A;
	int crmResult = DP::memoizedCutRod(A, A.size() - 1);
	auto crmEnd = clock() - crmStart;
	std::cout << "Memoized Cut-Rod DP procedure: " << crmEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (crResult == crmResult);

	if (check) std::cout << "All DP algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}