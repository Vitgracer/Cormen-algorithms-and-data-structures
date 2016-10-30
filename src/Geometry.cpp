#include <iostream>
#include <algorithm>
#include <climits>
#include <time.h>
#include <math.h>
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

// -------------------------- CHECK-ANGLE ----------------------
// Brief description: if p3 turn to let regars to p1-p2 - false, 
// else - true 
// --------------------------------------------------------------
static bool checkAngle(Point p1, Point p2, Point p3) {

}

// ----------------- GRAHAM-SCAN (p 1077) ----------------------
// Brief description: find convex-hull using Graham scan 
// -------------------------------------------------------------
// avg = teta(n * log(n) )
// -------------------------------------------------------------
std::vector<Point> Geometry::GrahamScan(std::vector<Point> inputPoints) {
	
	// find point with the lowest y-coordinate (and left, if it's not only)
	int minY = INT_MAX;
	
	for (int i = 0; i < inputPoints.size(); i++) {
		if (inputPoints[i].y < minY) minY = inputPoints[i].y;
	}
	
	// find left 
	int minLeft = INT_MAX;
	int minLeftInd = INT_MAX;
	for (int i = 0; i < inputPoints.size(); i++) {
		if (inputPoints[i].y == minY) {
			if (inputPoints[i].x < minLeft) {
				minLeft = inputPoints[i].x;
				minLeftInd = i;
			}
		}
	}
	
	// calculcate polar angles 
	std::vector<std::pair<Point, double>> sortedInputPoints(0, std::pair<Point, double>({0,0},0));
	for (int i = 0; i < inputPoints.size(); i++) {
		if (i == minLeftInd) continue;
		double angle = atan((inputPoints[i].y - inputPoints[minLeftInd].y) / (double)
							(inputPoints[i].x - inputPoints[minLeftInd].x));
		sortedInputPoints.push_back(std::make_pair(inputPoints[i], angle));
	}

	// sort vector with angle criterian and remove similar angles 
	// (leave only point with max distance to p0)
	// using selection sort
	for (int i = 0; i < sortedInputPoints.size() - 1; i++) {
		double minVal = DBL_MAX;
		int minInd = 0;

		for (int j = i; j < sortedInputPoints.size(); j++) {
			if (sortedInputPoints[j].second < minVal) {
				minVal = sortedInputPoints[j].second;
				minInd = j;
			}
		}

		auto temp = sortedInputPoints[i];
		sortedInputPoints[i] = sortedInputPoints[minInd];
		sortedInputPoints[minInd] = temp;
	}

	// remove duplicates 
	decltype(sortedInputPoints) filtratedInputPoints(0, std::pair<Point, double>({ 0,0 }, 0));;
	for (int i = 0; i < sortedInputPoints.size(); i++) {
		
		int j = i;
		double maxDist = 0;
		auto maxPoint = std::pair<Point, double>({ 0,0 }, 0);

		while (i < sortedInputPoints.size() - 1 && sortedInputPoints[j].second == sortedInputPoints[j + 1].second) {
			auto p0 = inputPoints[minLeftInd];
			auto p1 = sortedInputPoints[j].first;
			auto p2 = sortedInputPoints[j + 1].first;
			double dist1 = sqrt((p1.x - p0.x)*(p1.x - p0.x) + (p1.y - p0.y)*(p1.y - p0.y));
			double dist2 = sqrt((p2.x - p0.x)*(p2.x - p0.x) + (p2.y - p0.y)*(p2.y - p0.y));
			
			if (dist1 >= dist2) {
				if (dist1 > maxDist) {
					maxDist = dist1;
					maxPoint = sortedInputPoints[j];
				}
			}
			else {
				if (dist2 > maxDist) {
					maxDist = dist2;
					maxPoint = sortedInputPoints[j + 1];
				}
			}
			j++;
			i = j;
		}
		if (maxDist == 0) filtratedInputPoints.push_back(sortedInputPoints[i]);
		else filtratedInputPoints.push_back(maxPoint);
	}

	// Graham algorithm
	if (filtratedInputPoints.size() < 2) return{ {0,0} };
	else {
		std::vector<Point> S = std::vector<Point>(0, { 0,0 });
		S.push_back(inputPoints[minLeftInd]);
		S.push_back(filtratedInputPoints[0].first);
		S.push_back(filtratedInputPoints[1].first);
		
		for (int i = 2; i < filtratedInputPoints.size(); i++) {
			while (checkAngle(S[0], S[1], filtratedInputPoints[i])) {
				S.pop_back();
			}
			S.push_back(filtratedInputPoints[i]);
		}
	}
	return S;
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

	//-------------------------------------------------
	std::vector<Point> grAnswer = { { 0, 10 },{ 10, 10 },{ 10, 0 },{ 0, 0 } };
	std::vector<Point> inputPoints = grAnswer;
	for (int i = 0; i < 10; i++) inputPoints.push_back( {1 + std::rand() % 9,1 +  std::rand() % 9 });

	auto grStart = clock();
	auto convexHull = Geometry::GrahamScan(inputPoints);
	auto grEnd = clock() - grStart;
	std::cout << "Graham Scan: " << grEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (isIntersect1 == true) &&
		         (isIntersect2 == false);
	
	if (check) std::cout << "All geometry algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}