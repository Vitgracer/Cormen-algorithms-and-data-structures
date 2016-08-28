#include <vector>
#include <time.h>
#include <iostream>

class Array {
private:
	static std::vector<int> findMaxCrossingSubarray(std::vector<int> A, int low, int mid, int high);
	static std::vector<int> findMaxSubarray(std::vector<int> A, int low, int high);
public:
	friend void launchAllOtherAlgorithms();
};
