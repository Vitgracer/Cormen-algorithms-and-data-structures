#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Sort.h"
#include "Selection.h"

// ----------------RANDOMIZED-SELECT (246) -----------------------
// Brief description: find i-ordinal element in the current array
// ---------------------------------------------------------------
// avg = teta( n )
// worst = teta( n ^ n )
//----------------------------------------------------------------
int Selection::randomizedSelect(std::vector<int> A, int p, int r, int i) {
	if (p == r) return A[p];

	int q = getResultFromRandomizedPartition(A, p, r);
	int k = q - p + 1;

	if (k == i) return A[q];
	else if (i < k) {
		return randomizedSelect(A, p, q - 1, i);
	}
	else {
		return randomizedSelect(A, q + 1, r, i - k);
	}
}

// ----------------------------- LAUNCHER ------------------------------
// Brief description: laucnh all algorithms related to Selection problem
// ---------------------------------------------------------------------
void launchAllSelectionAlgorithms() {
	//-------------------------------------------------
	const int iStatistic = 1;
	std::vector<int> A;
	for (int i = 0; i < 10; i++) A.push_back(rand());

	//-------------------------------------------------
	auto rSelStart = clock();
	auto rSel = A;
	int rSelResult = Selection::randomizedSelect(rSel, 0, A.size() - 1, iStatistic);
	auto rSelEnd = clock() - rSelStart;
	std::cout << "Randomized selection: " << rSelEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (rSelResult == *(std::min_element(A.begin(), A.end())));

	if (check) std::cout << "All selection algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}