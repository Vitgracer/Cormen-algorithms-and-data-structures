#include <vector>
#include <climits>
#include "Other.h"

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