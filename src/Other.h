#include <vector>
#include <time.h>
#include <iostream>

class Array {
private:
	static std::vector<int> findMaxCrossingSubarray(std::vector<int> A, int low, int mid, int high);
	static std::vector<int> findMaxSubarray(std::vector<int> A, int low, int high);
	
	friend void launchAllOtherAlgorithms();
};

// ------------------------ LAUNCHER ----------------------------
// Brief description: laucnh all algorithms without any category
// --------------------------------------------------------------
void launchAllOtherAlgorithms() {
	//---------------------------------------------------------------------------------------
	std::vector<int> A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

	//---------------------------------------------------------------------------------------
	auto maxArStart = clock();
	Array::findMaxSubarray(A, 0, A.size() - 1);
	auto maxArEnd = clock() - maxArStart;
	std::cout << std::endl << "Find maximal subarray: " << maxArEnd<< " ms" << std::endl;
}