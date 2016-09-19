#include <iostream>
#include "MaximumSubarray.h"
#include "Selection.h"
#include "Matrix.h"
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

	//launch all Matrix algorithms 
	launchAllMatrixAlgorithms();

	return 0;
}