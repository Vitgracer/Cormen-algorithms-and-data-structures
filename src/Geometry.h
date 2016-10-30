#include <vector>

class Geometry {
private:
	static bool segmentsIntersect(int p1, int p2, int p3, int p4);
public:
	friend void launchAllGeometryAlgorithms();
};
