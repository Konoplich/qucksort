#include <stdlib.h>

int select_pivot_index (int *array, int left, int right)
{
	int midIndex = (left + right) / 2;
	int lowIndex = left;

	if (array[lowIndex] >= array[midIndex])
	{
		lowIndex = midIndex;
		midIndex = left;
	}

	if (array[right] <= array[lowIndex])
		return lowIndex;

	else
		if (array[right] <= array[midIndex])
			return midIndex;

	return right;
}


int partition (int *array, int left, int right, int pivotIndex)
{
	int pivot = array[pivotIndex];
	int tmp;
	tmp = array[right];
	array[right] = array[pivotIndex];
	array[pivotIndex] = tmp;
	int store = left;

	for (int idx = left; idx < right; idx++)
	{
		if (array[idx] <= pivot)
		{
			tmp = array[idx];
			array[idx] = array[store];
			array[store] = tmp;
			store++;
		}
	}

	tmp = array[right];
	array[right] = array[store];
	array[store] = tmp;
	return store;
}

/**
    Quick sort algorithm,
    if (l < r) then ; p = part(a, left, right) ; quick(a, l, p - 1) ; quick(a, p+1, r)
    Best: O(n log n)
    Average: O(n log n)
    Worst: O (n^2)
*/
void _quicksort(int* array, int left, int right)
{
	if (right <= left)
		return;

	int pivotIndex = select_pivot_index (array, left, right);
	pivotIndex = partition (array, left, right, pivotIndex);
	_quicksort (array, left, pivotIndex - 1);
	_quicksort (array, pivotIndex + 1, right);
}

void quicksort(int *array, size_t size)
{
	_quicksort(array, 0, size - 1);
}
