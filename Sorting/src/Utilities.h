#pragma once
#include <map>
#include <string>

enum class SortAlgorithm
{
	SelectionSort,
	InsertionSort,
	BinaryInsertionSort,
	BubbleSort,
	ShakerSort,
	ShellSort,
	HeapSort,
	MergeSort,
	QuickSort,
	CountingSort,
	RadixSort,
	FlashSort,
};

enum class State
{
	Sorted,
	Reversed,
	Random,
	NearlySorted
};

void swap(int& num1, int& num2);

int getMax(int* arr, int size);
int getMin(int* arr, int size);

void initOutputStr(std::map<SortAlgorithm, std::string>& sortAlg, std::map<State, std::string>& state);

unsigned long long timeOfSortAlg(int arr[], int size, int sortType);

