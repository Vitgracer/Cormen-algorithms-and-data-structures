#include <iostream>
#include <time.h>
#include <algorithm>
#include "Greedy.h"

//---------- RECURSIVE-ACTIVITY-SELECTOR (p 453) ----------------------------
// Brief description: n - number of processes, s_i - start timings, f_i - end 
// timings. Need to find max number of compatible processes. Compatible means 
// not intersected timing intervals
// -------------------------------------------------------------------------
// Input : 
// s_i   | 1 | 3 | 0 | 5 | 
// f_i   | 4 | 5 | 6 | 7 | - SHOULD BE SORTED!!!!!!!
// answer: 1-4, 5-7
// -------------------------------------------------------------------------
// avg = teta (n)
// -------------------------------------------------------------------------
std::vector<int> Greedy::recursiveActivitySelector(std::vector<int> s, std::vector<int> f, int k, int n) {
	int m = k + 1;

	while (m <= n && s[m] < f[k]) m++;
	if (m <= n) {
		auto res = recursiveActivitySelector(s, f, m, n);
		res.push_back(m);
		return res;
	}
	else return {};
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available greedy
// algorithms and compare their timings in console output 
// -------------------------------------------------------
void launchAllGreedyAlgorithms() {
	//-------------------------------------------------
	auto gStart = clock();
	std::vector<int> s = { 0/*fictive*/, 1, 3, 0, 5, 3, 5, 6,  8,  8,  2,  12 };
	std::vector<int> f = { 0/*fictive*/, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16 };
	auto gResult = Greedy::recursiveActivitySelector(s, f, 0, f.size() - 1);
	auto gEnd = clock() - gStart;
	std::cout << "Greedy Activity selector procedure: " << gEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = gResult[0];

	if (check) std::cout << "All Greedy algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}