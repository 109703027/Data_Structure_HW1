// C++ program for 3-way quick sort
#include <bits/stdc++.h>
#include "Quick_sort.h"
using namespace std;

/* This function partitions a[] in three parts
a) a[l..i] contains all elements smaller than pivot
b) a[i+1..j-1] contains all occurrences of pivot
c) a[j..r] contains all elements greater than pivot */

// It uses Dutch National Flag Algorithm
void DutchPartition(int* arr, int low, int high, int& i, int& j)
{
	// To handle 2 elements
	if (high - low <= 1) {
		if (arr[high] < arr[low])
			swap(arr[high], arr[low]);
		i = low;
		j = high;
		return;
	}

	int mid = low;
	int pivot = arr[high];
	while (mid <= high) {
		if (arr[mid] < pivot)
			swap(arr[low++], arr[mid++]);
		else if (arr[mid] == pivot)
			mid++;
		else if (arr[mid] > pivot)
			swap(arr[mid], arr[high--]);
	}

	// update i and j
	i = low - 1;
	j = mid; // or high+1
}

// 3-way partition based quick sort
void DutchQuickSort(int* arr, int low, int high)
{
	if (low >= high) // 1 or 0 elements
		return;

	int i, j;

	// Note that i and j are passed as reference
	DutchPartition(arr, low, high, i, j);

	// Recur two halves
	DutchQuickSort(arr, low, i);
	DutchQuickSort(arr, j, high);
}
