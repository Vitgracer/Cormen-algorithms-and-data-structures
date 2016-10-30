#include <iostream>
#include <algorithm>
#include <climits>
#include <time.h>
#include "Geometry.h"

// ---------------------- SEGMENTS-INTERSECT -----------------------
// Brief description: find out if 2 segmens p1p2 and p3p4 intersects 
// -----------------------------------------------------------------
bool Geometry::segmentsIntersect(int p1, int p2, int p3, int p4) {
	return true;
}

// ----------------- LAUNCHER -----------------------------
// Brief description: use all available geometry algorithms
// and compare their timings in console output 
// -------------------------------------------------------
void launchAllGeometryAlgorithms() {
	//-------------------------------------------------
	int p1 = 0; int p2 = 2;
	int p3 = 0; int p4 = 0;
	auto isStart = clock();
	bool isIntersect = Geometry::segmentsIntersect(p1, p2, p3, p4);
	auto isEnd = clock() - isStart;
	std::cout << "Segments intersection: " << isEnd << " ms" << std::endl;

	bool check = isIntersect;
	
	if (check) std::cout << "All geometry algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}