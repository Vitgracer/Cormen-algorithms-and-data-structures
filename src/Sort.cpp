#include "Sort.h"

// best = teta(n), worst = teta(n^2) (p 48)
//---------------------------------------------------------
// sorting like in a gambling =))
void so::Sort::insertionSort(std::vector<int>& A) {
	for (int j = 1; j < A.size(); j++) {
		int key = A[j];
		int i = j - 1;

		while (i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}

		A[i + 1] = key;
	}
}

// without additional information (p 52)
//-----------------------------------------------------------
// get minimum and put to 1st element, get leftover elements, 
// get min and put to the 2nd element and etc.
void so::Sort::selectionSort(std::vector<int>& A) {
	for (int i = 0; i < A.size() - 1; i++) {

		int minVal = 2147483647;
		int minInd = 0;

		for (int j = i; j < A.size(); j++) {
			if (A[j] < minVal) {
				minVal = A[j];
				minInd = j;
			}
		}

		int temp = A[i];
		A[i] = minVal;
		A[minInd] = temp;
	}
}

// procedure MERGE for mergeSort(), complexity = teta(n), (p 54)
//-----------------------------------------------------------
// sorting two sorted sequences 
void so::Sort::merge(std::vector<int>& A, int p, int q, int r) {

	const int lSize = q - p + 1;
	const int rSize = r - q;

	std::vector<int>::const_iterator begA = A.begin() + p;

	auto L = std::vector<int>(begA, begA + lSize);
	auto R = std::vector<int>(begA + lSize, begA + lSize + rSize);

	// signal card!
	L.push_back(2147483647);
	R.push_back(2147483647);

	int kl = 0;
	int kr = 0;

	// merge two arrays into one 
	for (int i = p; i <= r; i++) {
		if (L[kl] <= R[kr]) A[i] = L[kl++];
		else A[i] = R[kr++];
	}
}

// mergeSort, complexity = teta(n * log(n) ), (p 56)
// ----------------------------------------------------------
// separate sequence parts recursievly and merge sorted parts 
void so::Sort::mergeSort(std::vector<int>& A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}
