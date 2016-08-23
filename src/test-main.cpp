#include <iostream>
#include <time.h>
#include "Sort.h"

int main() {

	//-------------------------------------------------
	std::vector<int> A;
	for (int i = 0; i < 1000; i++) A.push_back(rand());

	//-------------------------------------------------
	auto insStart = clock();
	auto ins = A;
	so::Sort::insertionSort(ins);
	auto insEnd = clock() - insStart;
	std::cout << "Insertion sort: " << insEnd  << " ms" << std::endl;

	//-------------------------------------------------
	auto selStart = clock();
	auto sel = A;
	so::Sort::selectionSort(sel);
	auto selEnd = clock() - selStart;
	std::cout << "Selection sort: " << selEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto merStart = clock();
	auto mer = A;
	so::Sort::mergeSort(mer, 0, mer.size() - 1);
	auto merEnd = clock() - merStart;
	std::cout << "Merge sort: " << merEnd << " ms" << std::endl;

	//-------------------------------------------------
	auto bubStart = clock();
	auto bub = A;
	so::Sort::bubbleSort(bub);
	auto bubEnd = clock() - bubStart;
	std::cout << "Bubble sort: " << bubEnd << " ms" << std::endl;

	//-------------------------------------------------
	bool check = (sel == ins) && (sel == mer) && (sel == bub);
	if (check) std::cout << "All sortings algorithms are correct" << std::endl;
	else std::cout << "Error!" << std::endl;

	return 0;
}