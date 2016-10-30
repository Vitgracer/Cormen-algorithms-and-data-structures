#include <vector>

struct Point {
	int x;
	int y;
};

class Geometry {
private:
	static bool onSegment(Point p1, Point p2, Point p3);
	static int direction(Point p1, Point p2, Point p3);
	static bool segmentsIntersect(Point p1, Point p2, Point p3, Point p4);
public:
	friend void launchAllGeometryAlgorithms();
};
