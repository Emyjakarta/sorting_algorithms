#include "sort.h"
#include "sort.h"
/**
 * switch_ints-swap two integers in an array
 * @i: first integer to be swapped
 * @j: second integer to be swapped
 */
void switch_ints(int *i, int *j)
{
	int temp = 0;

	temp = *i;
	*i = *j;
	*j = temp;
}
/**
 * lomuto_partition-order a subset of an array of integers
 * according to lomuto partition scheme
 * @array: array of integers
 * @size: size of array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				switch_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot)
	{
		switch_ints(array + up, pivot);
		print_array(array, size);
	}
	return (up);
}
/**
 * lomuto_sort-implement the quicksort algorithm through recursion
 * @array: array of integers to sort
 * @size: size of array
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition to order
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}
/**
 * quick_sort-sort an array of integers in ascending order
 * using the quick sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
