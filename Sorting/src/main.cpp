#include "FileProcessing.h"
#include "Utilities.h"
#include "SortAlgorithm.h"

#include <vector>

int main()
{
	/*std::map<SortAlgorithm, std::string> sortAlg;
	std::map<State, std::string> state;
	std::vector<int> size = { 1000, 3000, 10000, 30000, 100000 };

	initOutputStr(sortAlg, state);
	
	writeResult(sortAlg, state, size, "result/Result.csv");*/
	
	int a[] = { 1, 30, 3, 12, 53, 62, 14, 32, 41, 49 };
	heapSort(a, 9);

	return 0;
}

