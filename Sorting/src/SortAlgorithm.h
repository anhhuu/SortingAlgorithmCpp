#pragma once
//1 Selection Sort
void selectionSort(int* arr, int size);
//2. Insertion Sort
void insertionSort(int* arr, int size);
//3. Binary Insertion Sort
int binarySearch(int* arr, int item, int left, int right);
void binaryInsertionSort(int* arr, int size);
//4. Bubble Sort
void bubbleSort(int* arr, int size);
//5. Shaker Sort
void shakerSort(int* arr, int size);
//6. Shell Sort
void shellSort(int* arr, int size);
//7. Heap Sort
void heapRebuild(int* arr, int size, int index);
void heapSort(int* arr, int size);
//8. Merge Sort
void merge(int* arr, int left, int mid, int right);
void mergeSort(int* arr, int left, int right);
//9. Quick Sort
void quickSort(int* arr, int left, int right);
//10. Counting Sort
void countingSort(int* arr, int size);
//11. Radix Sort
void countSort(int* arr, int size, int exp);
void radixSort(int* arr, int size);
//12. Flash Sort
void flashSort(int* arr, int size);
