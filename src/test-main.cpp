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

	//-------------------------------------------------
	auto selStart = clock();
	auto sel = A;
	so::Sort::selectionSort(sel);
	auto selEnd = clock() - insEnd;

	//-------------------------------------------------
	auto merStart = clock();
	auto mer = A;
	so::Sort::mergeSort(mer, 0, mer.size() - 1);
	auto merEnd = clock() - merStart;

	//-------------------------------------------------
	bool check = (sel == ins) && (sel == mer);

	return 0;
}