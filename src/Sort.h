#include <vector>

class Sort {
private:
	// simple teta (n ^ 2) sortings
	static void bubbleSort(std::vector<int>& A);
	static void insertionSort(std::vector<int>& A);
	static void insertionSortRecursive(std::vector<int>& A, int n);
	static void selectionSort(std::vector<int>& A);

	// merge-sort 
	static void merge(std::vector<int>& A, int p, int q, int r);
	static void mergeSort(std::vector<int>& A, int p, int r);

	// heap-sort
	static int left(int i);
	static int right(int i);
	static int parent(int i);
	static void maxHeapify(std::vector<int>& A, int i, int heapSize);
	static void buildMaxHeap(std::vector<int>& A);
	static void heapSort(std::vector<int>& A);

	// quick-sort 
	static void quickSort(std::vector<int>& A, int p, int r);
public:
	static void launchAllSortingAlgorithms();
};
