#include "Utilities.h"
#include "SortAlgorithm.h"

#include <chrono>

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int getMax(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}

int getMin(int* arr, int size)
{
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}

	return min;
}

void initOutputStr(std::map<SortAlgorithm, std::string>& sortAlg, std::map<State, std::string>& state)
{
	//Sort algorithm string for output
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::SelectionSort, "SelectionSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::InsertionSort, "InsertionSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::BinaryInsertionSort, "BinaryInsertionSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::BubbleSort, "BubbleSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::ShakerSort, "ShakerSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::ShellSort, "ShellSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::HeapSort, "HeapSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::MergeSort, "MergeSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::QuickSort, "QuickSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::CountingSort, "CountingSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::RadixSort, "RadixSort"));
	sortAlg.insert(std::pair<SortAlgorithm, std::string>(SortAlgorithm::FlashSort, "FlashSort"));

	//State string for output
	state.insert(std::pair< State, std::string>(State::Sorted, "Sorted"));
	state.insert(std::pair< State, std::string>(State::Reversed, "Reversed"));
	state.insert(std::pair< State, std::string>(State::Random, "Random"));
	state.insert(std::pair< State, std::string>(State::NearlySorted, "NearlySorted"));
}


unsigned long long timeOfSortAlg(int arr[], int size, int sortType)
{
	std::chrono::time_point<std::chrono::steady_clock> start;
	std::chrono::time_point<std::chrono::steady_clock> end;

	float time_use = 0;
	switch (sortType)
	{
	case 0:
		start = std::chrono::high_resolution_clock::now();
		selectionSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 1:
		start = std::chrono::high_resolution_clock::now();
		insertionSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 2:
		start = std::chrono::high_resolution_clock::now();
		binaryInsertionSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 3:
		start = std::chrono::high_resolution_clock::now();
		bubbleSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 4:
		start = std::chrono::high_resolution_clock::now();
		shakerSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 5:
		start = std::chrono::high_resolution_clock::now();
		shellSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 6:
		start = std::chrono::high_resolution_clock::now();
		heapSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 7:
		start = std::chrono::high_resolution_clock::now();
		mergeSort(arr, 0, size - 1);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 8:
		start = std::chrono::high_resolution_clock::now();
		quickSort(arr, 0, size - 1);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 9:
		start = std::chrono::high_resolution_clock::now();
		countingSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 10:
		start = std::chrono::high_resolution_clock::now();
		radixSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	case 11:
		start = std::chrono::high_resolution_clock::now();
		flashSort(arr, size);
		end = std::chrono::high_resolution_clock::now();
		break;
	default:
		break;
	}
	long long microSeconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	return microSeconds;
}

