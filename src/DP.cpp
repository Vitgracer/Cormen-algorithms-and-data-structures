#include <iostream>
#include <time.h>
#include "DP.h"

// ----------------- LAUNCHER ----------------------------
// Brief description: use all available sorting algorithms
// and compare their timings in console output 
// -------------------------------------------------------
void launchAllSortingAlgorithms() {
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
	auto qStart = clock();
	auto qui = A;
	Sort::quickSort(qui, 0, qui.size() - 1);
	auto qEnd = clock() - qStart;
	std::cout << "Quick sort: " << qEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto countStart = clock();
	auto count = A;
	Sort::countingSort(count);
	auto countEnd = clock() - countStart;
	std::cout << "Counting sort: " << countEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (sel == ins) &&
		(sel == mer) &&
		(sel == bub) &&
		(sel == pyr) &&
		(sel == qui) &&
		(sel == count) &&
		(sel == insR);

	if (check) std::cout << "All sortings algorithms are correct" << std::endl << std::endl;
	else std::cout << "Error!" << std::endl << std::endl;
}