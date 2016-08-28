#include <vector>
#include <climits>
#include "Other.h"

// ----------------FIND-MAX-CROSSING-SUBARAAY-------------------------
// Brief description: we have "low", "mid", "high" positions in 
// A array. Main goal is to find maximal subarray crossing "mid" point
// -------------------------------------------------------------------
// avg = teta(n)
//---------------------------------------------------------
std::vector<int> Array::findMaxCrossingSubarray(std::vector<int> A, int low, int mid, int high) {
	int leftSum = INT_MIN;
	int maxLeft = high;
	int sum = 0;

	for (int i = mid; i >= low; i--) {
		sum = sum + A[i];
		if (sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
	}

	int rightSum = INT_MIN;
	int maxRight = low;
	sum = 0;

	for (int i = mid + 1; i <= high; i++) {
		sum = sum + A[i];
		if (sum > rightSum) {
			rightSum = sum;
			maxRight = i;
		}
	}

	return { maxLeft, maxRight, leftSum + rightSum };
}

// ----------------------FIND-MAX-SUBARAAY-------------------------
// Brief description: main goal is to find subarray with maximal sum 
// of elements in current array A 
// -------------------------------------------------------------------
// avg = teta(n * log(n) )
//---------------------------------------------------------
std::vector<int> Array::findMaxSubarray(std::vector<int> A, int low, int high) {
	if (high == low) return{ low, high, A[low] };
	else {
		int mid = (high + low) / 2;

		std::vector<int> leftVec = findMaxSubarray(A, low, mid);
		int leftLow = leftVec[0];
		int leftHigh = leftVec[1];
		int leftSum = leftVec[2];

		std::vector<int> rightVec = findMaxSubarray(A, mid + 1, high);
		int rightLow = rightVec[0];
		int rightHigh = rightVec[1];
		int rightSum = rightVec[2];

		std::vector<int> crossVec = findMaxCrossingSubarray(A, low, mid, high);
		int crossLow = crossVec[0];
		int crossHigh = crossVec[1];
		int crossSum = crossVec[2];

		if (leftSum > rightSum && leftSum > crossSum) return{ leftLow, leftHigh, leftSum };
		if (rightSum > leftSum && rightSum > crossSum) return{ rightLow, rightHigh, rightSum };
		if (crossSum > leftSum && crossSum > rightSum) return{ crossLow, crossHigh, crossSum };
	}
}

// ------------------------ LAUNCHER ----------------------------
// Brief description: laucnh all algorithms without any category
// --------------------------------------------------------------
void launchAllOtherAlgorithms() {
	//---------------------------------------------------------------------------------------
	std::vector<int> A = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };

	//---------------------------------------------------------------------------------------
	auto maxArStart = clock();
	std::vector<int> maxSubarray = Array::findMaxSubarray(A, 0, A.size() - 1);
	auto maxArEnd = clock() - maxArStart;
	std::cout << std::endl << "Find maximal subarray: " << maxArEnd << " ms" << std::endl;
}