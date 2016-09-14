#include <iostream>
#include "MaximumSubarray.h"
#include "Selection.h"
#include "Greedy.h"
#include "Sort.h"
#include "DP.h"

int main() {
	// compare sorting algorithms 
	launchAllSortingAlgorithms();

	// launch all algorithms with maximum 
	// subarray search 
	launchAllMaxSubarrayAlgorithms();

	// launch all selection algorithms 
	launchAllSelectionAlgorithms();

	// launch all DP algorithms 
	launchDPAlgorithms();

	// launch all greedy algorithms 
	launchAllGreedyAlgorithms();

	return 0;
}