#include <iostream>
#include <algorithm>
#include <climits>
#include <time.h>
#include "Substring.h"

// ---------------------- NAIVE-STRING-MATCHER -------------------
// Brief description: the simpliest algorithm for string matching
// ---------------------------------------------------------------
// previous processing time: 0 
// comparison time: O ( (n - m + 1) * m )
//---------------------------------------------------------
int Substring::naiveStringMatcher(std::vector<int>& T, std::vector<int>& P) {
	return 0;
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available string matching 
// algorithms and compare their timings in console output 
// -------------------------------------------------------
void launchAllSubstringAlgorithms() {
	//-------------------------------------------------
	std::vector<int> T = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> P = { 4, 5, 6, 7, 8, 9 };

	//-------------------------------------------------
	auto nStart = clock();
	int nOutput = Substring::naiveStringMatcher(T, P);
	auto nEnd = clock() - nStart;
	std::cout << "Naive string matching: " << nEnd << " ms" << std::endl;

	bool check = nOutput;
	
	if (check) std::cout << "All substring algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}