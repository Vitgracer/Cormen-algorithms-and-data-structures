#include <vector>

namespace so {

	class Sort {
	private:
		static void merge(std::vector<int>& A, int p, int q, int r);

	public:
		static void insertionSort(std::vector<int>& A);
		static void selectionSort(std::vector<int>& A);
		static void mergeSort(std::vector<int>& A, int p, int r);
	};

}