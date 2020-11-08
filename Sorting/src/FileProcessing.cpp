#include "FileProcessing.h"
#include "DataGenerator.h"
#include "SortAlgorithm.h"
#include "Utilities.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

std::string outFileName(std::string sortAlg, std::string state, int size)
{
	std::stringstream outFileName;
	outFileName << "result/" << sortAlg << "_" << state << "_" << size << ".txt";
	std::string returnVal = outFileName.str();
	return returnVal;
}

void writeArrSorted(int arr[], int n, std::string fileName)
{
	std::ofstream outSort(fileName);

	for (int k = 0; k < n; k++)
	{
		outSort << arr[k] << " ";
	}

	outSort.close();
}

void writeResult(std::map<SortAlgorithm, std::string> sortAlg, std::map<State, std::string> state, std::vector<int> size, std::string fileName)
{
	std::ofstream result(fileName);
	result << "Input State,Input Size,";
	for (int sortType = static_cast<int>(SortAlgorithm::SelectionSort);	sortType <= static_cast<int>(SortAlgorithm::FlashSort); sortType++)
	{
		result << sortAlg[static_cast<SortAlgorithm>(sortType)] << ",";
	}
	result << std::endl;

	for (int dataType = static_cast<int>(State::Sorted); dataType <= static_cast<int>(State::NearlySorted); dataType++)
	{
		for (int indexSize = 0; indexSize < size.size(); indexSize++)
		{
			int sizeArr = size[indexSize];
			int* arr = new int[sizeArr];
			generateData(arr, sizeArr, dataType);

			result << state[static_cast<State>(dataType)] << "," << size[indexSize] << ",";

			for (int sortType = 0; sortType < 12; sortType++)
			{
				int* temp = new int[sizeArr];
				for (int z = 0; z < sizeArr; z++)
				{
					temp[z] = arr[z];
				}
				std::cout.setf(std::ios::left);
				std::cout << "Algorithm: " << std::setw(21) << (sortAlg[static_cast<SortAlgorithm>(sortType)] + ", ");
				std::cout << "State: " << std::setw(14) << state[static_cast<State>(dataType)] + ", ";
				std::cout << "Size: " << std::setw(8) << std::to_string(size[indexSize]) + ", ";
				std::cout << "Time lapsed: ";

				unsigned long long timeLapse = timeOfSortAlg(temp, size[indexSize], sortType);

				writeArrSorted(temp, size[indexSize], outFileName(sortAlg[static_cast<SortAlgorithm>(sortType)], state[static_cast<State>(dataType)], size[indexSize]));
				
				std::cout << std::setw(12) << timeLapse << "OK!" << std::endl;

				result << timeLapse << ",";

				delete[] temp;
			}
			result << std::endl;
			std::cout << std::endl;
			delete[] arr;
		}
	}

	result.close();
}