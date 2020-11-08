#include "SortAlgorithm.h"
#include "Utilities.h"

#include <iostream>


//1 Selection Sort
void selectionSort(int* arr, int size)
{
	int i = 0, j = 0, minIndex = 0;

	//One by one move boundary of unsorted subarray
	for (i = 0; i < size - 1; i++)
	{
		//Find the minimum element in unsorted array
		minIndex = i;
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		//Swap the found minimum element with the first element
		swap(arr[minIndex], arr[i]);
	}
}

//2. Insertion Sort
void insertionSort(int* arr, int size)
{
	int i = 0, key = 0, j = 0;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;

		//Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//3. Binary Insertion Sort
int binarySearch(int* arr, int item, int left, int right)
{
	if (right <= left)
		return (item > arr[left]) ? (left + 1) : left;

	int mid = (left + right) / 2;

	if (item == arr[mid])
		return mid + 1;

	if (item > arr[mid])
		return binarySearch(arr, item, mid + 1, right);
	return binarySearch(arr, item, left, mid - 1);
}


void binaryInsertionSort(int* arr, int size)
{
	int i = 0, loc = 0, j = 0, selected = 0;

	for (i = 1; i < size; ++i)
	{
		j = i - 1;
		selected = arr[i];

		//Find location where selected sould be inseretd 
		loc = binarySearch(arr, selected, 0, j);

		//Move all elements after location to create space 
		while (j >= loc)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = selected;
	}
}

//4. Bubble Sort
void bubbleSort(int* arr, int size)
{
	int i = 0, j = 0;
	for (i = 0; i < size - 1; i++)
	{
		//Last i elements are already in place  
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//5. Shaker Sort
void shakerSort(int* arr, int size)
{
	int left = 0;
	int right = size - 1;
	int k = 0;
	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		}
		right = k;
		for (int i = right; i > left; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		}
		left = k;
	}
}

//6. Shell Sort
void shellSort(int* arr, int size)
{
	// Start with a big gap, then reduce the gap 
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		//Do a gapped insertion sort for this gap size
		//The first gap elements a[0..gap-1] are already in gapped order keep adding one more element until the entire array is gap sorted  
		for (int i = gap; i < size; i += 1)
		{
			//Add a[i] to the elements that have been gap sorted
			//Save a[i] in temp and make a hole at position i
			int temp = arr[i];

			//Shift earlier gap-sorted elements up until the correct location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//Put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}
}

//7. Heap Sort
void heapRebuild(int* arr, int size, int index)
{
	int largest = index; // Initialize largest as root 
	int l = 2 * index + 1; // left = 2*i + 1 
	int r = 2 * index + 2; // right = 2*i + 2 

	//If left child is larger than root 
	if (l < size && arr[l] > arr[largest])
		largest = l;

	//If right child is larger than largest so far 
	if (r < size && arr[r] > arr[largest])
		largest = r;

	//If largest is not root 
	if (largest != index)
	{
		swap(arr[index], arr[largest]);

		//Recursively heapify the affected sub-tree 
		heapRebuild(arr, size, largest);
	}
}

void heapSort(int* arr, int size)
{
	//Build heap (rearrange array) 
	for (int i = size / 2 - 1; i >= 0; i--)
		heapRebuild(arr, size, i);

	//One by one extract an element from heap 
	for (int i = size - 1; i >= 0; i--)
	{
		//Move current root to end 
		swap(arr[0], arr[i]);

		//Call max heapify on the reduced heap 
		heapRebuild(arr, i, 0);
	}
}

//8. Merge Sort
void merge(int* arr, int left, int mid, int right)
{
	int i = 0, j = 0, k = 0;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	//Create temp arrays
	int* leftArr = new int[n1];
	int* rightArr = new int[n2];

	//Copy data to temp arrays leftArr[] and rightArr[]
	for (i = 0; i < n1; i++)
		leftArr[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		rightArr[j] = arr[mid + 1 + j];

	//Merge the temp arrays back into arr[l..r]
	i = 0; //Initial index of first subarray
	j = 0; //Initial index of second subarray
	k = left; //Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	//Copy the remaining elements of leftArr[], if there are any
	while (i < n1)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	//Copy the remaining elements of rightArr[], if there are any
	while (j < n2)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}

	delete[] leftArr;
	delete[] rightArr;
}

void mergeSort(int* arr, int left, int right)
{
	if (left < right)
	{
		//Same as (l+r)/2, but avoids overflow for large l and h 
		int m = left + (right - left) / 2;

		//Sort first and second halves 
		mergeSort(arr, left, m);
		mergeSort(arr, m + 1, right);

		merge(arr, left, m, right);
	}
}

//9. Quick Sort
void quickSort(int* arr, int left, int right)
{
	if (left >= right) return;
	int leftIndex = left;
	int rightIndex = right;
	int pivot = arr[left + (right - left) / 2];
	while (leftIndex <= rightIndex)
	{
		while (arr[leftIndex] < pivot)leftIndex++;  
		while (arr[rightIndex] > pivot)rightIndex--;
		if (leftIndex <= rightIndex)
		{
			swap(arr[leftIndex], arr[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}
	if (left < rightIndex)quickSort(arr, left, rightIndex); 
	if (leftIndex < right)quickSort(arr, leftIndex, right); 
}

//10. Counting Sort
void countingSort(int* arr, int size)
{
	int* output = new int[size]; //The output will have sorted input array
	int max = getMax(arr, size);
	int min = getMin(arr, size);
	int i = 0;

	int k = max - min + 1; //Size of count array

	int* countArr = new int[k]; //Create a countArr to store count of each individual input value
	std::fill_n(countArr, k, 0); //Initialize countArr elements as zero

	for (i = 0; i < size; i++)
		countArr[arr[i] - min]++; //Store count of each individual input value

	//Change countArr so that countArr now contains actual position of input values in output array 
	for (i = 1; i < k; i++)
		countArr[i] += countArr[i - 1];

	//Populate output array using countArr and input array
	for (i = 0; i < size; i++)
	{
		output[countArr[arr[i] - min] - 1] = arr[i];
		countArr[arr[i] - min]--;
	}

	for (i = 0; i < size; i++)
		arr[i] = output[i]; //Copy the output array to input, so that input now contains sorted values

	delete[] output;
	delete[] countArr;
}

//11. Radix Sort
void countSort(int* arr, int size, int exp)
{
	int* output = new int[size]; // output array 
	int i, count[10] = { 0 };

	//Store count of occurrences in count[] 
	for (i = 0; i < size; i++)
		count[(arr[i] / exp) % 10]++;

	//Change count[i] so that count[i] now contains actual position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	//Build the output array 
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	//Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit 
	for (i = 0; i < size; i++)
		arr[i] = output[i];

	delete[] output;
}

void radixSort(int* arr, int size)
{
	//Find the maximum number to know number of digits 
	int m = getMax(arr, size);

	//Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i 
	//Where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countSort(arr, size, exp);
	}
}

//12. Flash Sort
void flashSort(int* arr, int size)
{
	if (size == 0) return;
	int m = (int)((0.2 * size) + 2);

	int min, max, maxIndex;
	min = max = arr[0];
	maxIndex = 0;

	for (int i = 1; i < size - 1; i += 2)
	{
		int small = 0;
		int big = 0;
		int bigIndex = 0;

		if (arr[i] < arr[i + 1])
		{
			small = arr[i];
			big = arr[i + 1];
			bigIndex = i + 1;
		}
		else
		{
			big = arr[i];
			bigIndex = i;
			small = arr[i + 1];
		}

		if (big > max)
		{
			max = big;
			maxIndex = bigIndex;
		}

		if (small < min)
		{
			min = small;
		}
	}

	if (arr[size - 1] < min)
	{
		min = arr[size - 1];
	}
	else if (arr[size - 1] > max)
	{
		max = arr[size - 1];
		maxIndex = size - 1;
	}

	if (max == min)
	{
		return;
	}

	int* L = new int[m + 1];

	for (int t = 1; t <= m; t++)
	{
		L[t] = 0;
	}

	double c = (m - 1.0) / (max - min);
	int K;
	for (int h = 0; h < size; h++)
	{
		K = ((int)((arr[h] - min) * c)) + 1;
		L[K] += 1;
	}

	for (K = 2; K <= m; K++)
	{
		L[K] = L[K] + L[K - 1];
	}

	int temp = arr[maxIndex];
	arr[maxIndex] = arr[0];
	arr[0] = temp;

	int j = 0;

	K = m;

	int numMoves = 0;

	while (numMoves < size)
	{
		while (j >= L[K])
		{
			j++;
			K = ((int)((arr[j] - min) * c)) + 1;
		}

		int evicted = arr[j];

		while (j < L[K])
		{
			K = ((int)((evicted - min) * c)) + 1;

			int location = L[K] - 1;

			int temp = arr[location];
			arr[location] = evicted;
			evicted = temp;

			L[K] -= 1;

			numMoves++;
		}
	}


	int threshold = (int)(1.25 * ((size / m) + 1));
	const int minElements = 30;

	for (K = m - 1; K >= 1; K--)
	{
		int classSize = L[K + 1] - L[K];

		if (classSize > threshold&& classSize > minElements)
		{
			flashSort(&arr[L[K]], classSize);
		}
		else
		{
			if (classSize > 1)
			{
				insertionSort(&arr[L[K]], classSize);
			}
		}
	}

	delete[] L;
}
