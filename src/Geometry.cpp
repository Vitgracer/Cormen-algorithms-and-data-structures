#include <iostream>
#include <algorithm>
#include <climits>
#include <time.h>
#include "Geometry.h"

// ---------------------- DIRECTION --------------------------------
// Brief description: define if pk lies from the left or right side
// regarding to pi-pj
// -----------------------------------------------------------------
int Geometry::direction(Point pi, Point pj, Point pk) {
	return ((pk.x - pi.x) * (pj.y - pi.y) - (pj.x - pi.x) * (pk.y - pi.y));
}

// ---------------------- ON-SEGMENT --------------------------------
// Brief description: define if the point pk lies on the segment pi-pj
// ------------------------------------------------------------------
bool Geometry::onSegment(Point pi, Point pj, Point pk) {
	if ((std::min(pi.x, pj.x) < pk.x && std::max(pi.x, pj.x) > pk.x) &&
		(std::min(pi.y, pj.y) < pk.y && std::max(pi.y, pj.y) > pk.y)) return true;
	else return false;
}

// --------------------- SEGMENTS-INTERSECT (p 1064) ---------------
// Brief description: find out if 2 segmens p1p2 and p3p4 intersects 
// -----------------------------------------------------------------
bool Geometry::segmentsIntersect(Point p1, Point p2, Point p3, Point p4) {
	int d1 = direction(p3, p4, p1);
	int d2 = direction(p3, p4, p2);
	int d3 = direction(p1, p2, p3);
	int d4 = direction(p1, p2, p4);

	if ((((d1 > 0) && (d2 < 0)) || ((d1 < 0) && (d2 > 0))) &&
		(((d3 > 0) && (d4 < 0)) || ((d3 < 0) && (d4 > 0)))) return true;

	else if (d1 == 0 && onSegment(p3, p4, p1)) return true;
	else if (d2 == 0 && onSegment(p3, p4, p2)) return true;
	else if (d3 == 0 && onSegment(p1, p2, p3)) return true;
	else if (d4 == 0 && onSegment(p1, p2, p4)) return true;
	else return false;
}

// ----------------- LAUNCHER -----------------------------
// Brief description: use all available geometry algorithms
// and compare their timings in console output 
// -------------------------------------------------------
void launchAllGeometryAlgorithms() {
	//-------------------------------------------------
	Point p1 = { 0, 0 }; Point p2 = { 2, 0 };
	Point p3 = { 1, 1 }; Point p4 = { 1, -1 };
	Point p5 = { 2, 1 };

	auto isStart = clock();
	bool isIntersect1 = Geometry::segmentsIntersect(p1, p2, p3, p4);
	bool isIntersect2 = Geometry::segmentsIntersect(p1, p2, p3, p5);
	auto isEnd = clock() - isStart;
	std::cout << "Segments intersection: " << isEnd << " ms" << std::endl;

	bool check = (isIntersect1 == true) && 
				 (isIntersect2 == false);
	
	if (check) std::cout << "All geometry algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}