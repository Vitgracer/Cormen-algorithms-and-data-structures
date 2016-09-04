#include <iostream>
#include <climits>
#include <time.h>
#include "Sort.h"

// --------------------INSERTION SORT (p 48)---------------
// Brief description: sorting like in a gambling
// --------------------------------------------------------
// best = teta(n) 
// avg = teta(n^2)
// worst = teta(n^2) 
//---------------------------------------------------------
void Sort::insertionSort(std::vector<int>& A) {
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

// ---------------INSERTION SORT (RECURSIVE)--------
// Brief description: insertion sort using recursion 
// -------------------------------------------------
// best = teta(n) 
// avg = teta(n^2)
// worst = teta(n^2) 
//--------------------------------------------------
void Sort::insertionSortRecursive(std::vector<int>& A, int n) {
	if (n > 1)
		insertionSortRecursive(A, n - 1);
	
	int key = A[n];
	int i = n - 1;

	while (i >= 0 && A[i] > key) {
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = key;
}

// --------------------BUBBLE SORT---------------------------
// Brief description: elements' pair replacement, 
// when minimal element goes to the beginning like a "bubble"
// ----------------------------------------------------------
// best = teta(n^2) 
// avg = teta(n^2)
// worst = teta(n^2) 
//---------------------------------------------------------
void Sort::bubbleSort(std::vector<int>& A) {
	for (int i = 0; i < A.size() - 1; i++) {
		bool swapped = false;

		for (int j = 0; j < A.size() - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

//---------------------SELECTION SORT (p 52)------------------------
// Brief description: get minimum and put to 1st element.
// Put left elements, find min and place to the 2nd position and etc
//------------------------------------------------------------------
// best = teta(n^2)
// avg = teta(n^2)
// worst = teta(n^2)
//------------------------------------------------------------------ 
void Sort::selectionSort(std::vector<int>& A) {
	for (int i = 0; i < A.size() - 1; i++) {
		int minVal = INT_MAX;
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

//--------ADDITIONAL FUNCTION FOR MERGE-SORT (p 54)--------
// Brief description: allows to join two sorted vectors to 
// one sorted vector 
//---------------------------------------------------------
// worst = teta(n)
//---------------------------------------------------------
void Sort::merge(std::vector<int>& A, int p, int q, int r) {

	const int lSize = q - p + 1;
	const int rSize = r - q;

	std::vector<int>::const_iterator begA = A.begin() + p;

	auto L = std::vector<int>(begA, begA + lSize);
	auto R = std::vector<int>(begA + lSize, begA + lSize + rSize);

	// signal card!
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);

	int kl = 0;
	int kr = 0;

	// merge two arrays into one 
	for (int i = p; i <= r; i++) {
		if (L[kl] <= R[kr]) A[i] = L[kl++];
		else A[i] = R[kr++];
	}
}

//----------------------MERGE-SORT (p 56)--------------------
// Brief description: separate sequence parts recursievly and 
// merge sorted parts by merge() function
// ----------------------------------------------------------
// worst = teta(n * log(n) )
// ----------------------------------------------------------
void Sort::mergeSort(std::vector<int>& A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

//----------------------LEFT (p 180)--------------------
// Brief description: get left child of the current node
// -----------------------------------------------------
int Sort::left(int i) { return 2 * i; }

//----------------------RIGHT (p 180)--------------------
// Brief description: get right child of the current node
// -----------------------------------------------------
int Sort::right(int i) { return 2 * i + 1; }

//----------------------PARENT (p 180)----------------------
// Brief description: get parent node of the current child
// -------------------------------------------------------
int Sort::parent(int i) { return i / 2; }

//----------------------MAX-HEAPIFY (p 183)-----------------------------
// Brief description: get A-array, represent it as pyramid (binary tree),
// and transform it to non-increasing case for i-node and all its childs 
// ---------------------------------------------------------------------
// worst = teta(log(n) )
// ---------------------------------------------------------------------
void Sort::maxHeapify(std::vector<int>& A, int i, int heapSize) {
	int l = left(i);
	int r = right(i);
	int largest = i;

	if (l < heapSize && A[i] < A[l]) largest = l;
	if (r < heapSize && A[largest] < A[r]) largest = r;

	if (largest != i) {
		int tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;

		maxHeapify(A, largest, heapSize);
	}
}

//----------------------MAX-HEAPIFY (p 185)-----------------------------
// Brief description: get A-array, represent it as pyramid (binary tree),
// and transform it to non-increasing pyramid 
// ---------------------------------------------------------------------
// worst = teta(n * log(n) )
// ---------------------------------------------------------------------
void Sort::buildMaxHeap(std::vector<int>& A) {
	for (int i = (A.size() - 1) / 2; i > 0; i--) {
		maxHeapify(A, i, A.size());
	}
}

//----------------------DUMMY-VECTOR-----------------
// Brief description: crutch to apply indexing from 1
// --------------------------------------------------
void dummyVector(std::vector<int>& A) {
	A.insert(A.begin(), -1);
}

//--------------UNDUMMY-VECTOR---------
// Brief description: remove crutch :) 
// ------------------------------------
void undummyVector(std::vector<int>& A) {
	A.erase(A.begin());
}

//------------------------------------HEAPSORT-----------------------------
// Brief description: get A-array, represent it as pyramid (binary tree),
// and transform it to non-increasing pyramid, using buildMaxHeap procedure.
// After that, extract the max pyramid element and put it to the end of tree,
// decrasing heap size.
// -------------------------------------------------------------------------
// worst = teta(n * log(n) )
// ---------------------------------------------------------------------
void Sort::heapSort(std::vector<int>& A) {
	dummyVector(A);

	int heapSize = A.size();
	buildMaxHeap(A);

	for (int i = A.size() - 1; i > 1; i--) {
		int tmp = A[1];
		A[1] = A[i];
		A[i] = tmp;
		
		heapSize--;
		maxHeapify(A, 1, heapSize);
	}

	undummyVector(A);
}

//------------PARTITION (p 199)----------------
// Brief description: find reliable element q.
// --------------------------------------------
// avg = teta(n)
// --------------------------------------------
int Sort::partition(std::vector<int>& A, int p, int r) {
	return 0;
}

//---------------------- QUICKSORT (p 198)-----------------------------
// Brief description: use procedure "partition" to determine separation 
// element q. Next, use quicksort for 0 -> q, q + 1 -> p arrays. 
// ---------------------------------------------------------------------
// avg = teta(n * log(n) )
// worst = teta( n ^ 2 )
// ---------------------------------------------------------------------
void Sort::quickSort(std::vector<int>& A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q);
		quickSort(A, q + 1, r);
	}
}

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available sorting algorithms
// and compare their timings in console output 
// -------------------------------------------------------
void Sort::launchAllSortingAlgorithms() {
	//-------------------------------------------------
	std::vector<int> A;
	for (int i = 0; i < 1000; i++) A.push_back(rand());

	//-------------------------------------------------
	auto insStart = clock();
	auto ins = A;
	Sort::insertionSort(ins);
	auto insEnd = clock() - insStart;
	std::cout << "Insertion sort: " << insEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto insRStart = clock();
	auto insR = A;
	Sort::insertionSortRecursive(insR, insR.size() - 1);
	auto insREnd = clock() - insRStart;
	std::cout << "Insertion resursive sort: " << insREnd << " ms" << std::endl;

	//-------------------------------------------------
	auto selStart = clock();
	auto sel = A;
	Sort::selectionSort(sel);
	auto selEnd = clock() - selStart;
	std::cout << "Selection sort: " << selEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto merStart = clock();
	auto mer = A;
	Sort::mergeSort(mer, 0, mer.size() - 1);
	auto merEnd = clock() - merStart;
	std::cout << "Merge sort: " << merEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto bubStart = clock();
	auto bub = A;
	Sort::bubbleSort(bub);
	auto bubEnd = clock() - bubStart;
	std::cout << "Bubble sort: " << bubEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto pyrStart = clock();
	auto pyr = A;
	Sort::heapSort(pyr);
	auto pyrEnd = clock() - pyrStart;
	std::cout << "Heap sort: " << pyrEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (sel == ins) && 
				 (sel == mer) && 
				 (sel == bub) &&
				 (sel == pyr) &&
				 (sel == insR);
	
	if (check) std::cout << "All sortings algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}