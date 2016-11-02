#include <vector>

struct Point {
	int x;
	int y;
};

class Geometry {
private:
	// segments intersection
	static bool onSegment(Point p1, Point p2, Point p3);
	static int direction(Point p1, Point p2, Point p3);
	static bool segmentsIntersect(Point p1, Point p2, Point p3, Point p4);

	// Graham scan 
	static bool checkAngle(Point p1, Point p2, Point p3);
	static std::vector<Point> GrahamScan(std::vector<Point> inputPoints);

	// Jarvis scan 
	static std::vector<Point> JarvisScan(std::vector<Point> inputPoints);
	static Point findPointWithMinPolarAngle(std::vector<Point> inputPoints, int inputPointInd);
	static float calcPolarAngle(Point main, Point current);
public:
	friend void launchAllGeometryAlgorithms();
};
