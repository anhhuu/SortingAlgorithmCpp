#include "DataGenerator.h"
#include "Utilities.h"
#include <iostream>
#include <cmath>
#include <time.h>

void generateRandomData(int* arr, int size)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size;
	}
}

void generateSortedData(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

void generateReverseData(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = size - 1 - i;
	}
}

void generateNearlySortedData(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % size;
		int r2 = rand() % size;
		swap(arr[r1], arr[r2]);
	}
}

void generateData(int* arr, int size, int dataType)
{
	switch (dataType)
	{
	case 0:	//random
		generateRandomData(arr, size);
		break;
	case 1:	//sorted
		generateSortedData(arr, size);
		break;
	case 2:	//reverse
		generateReverseData(arr, size);
		break;
	case 3:	//nearly sorted
		generateNearlySortedData(arr, size);
		break;
	default:
		std::cout << "Error: unknown data type!" << std::endl;
	}
}

