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
 * selection_sort-sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	int *small;
	size_t a, b;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		small = array + a;
		for (b = a + 1; b < size; b++)
			small = (array[b] < *small) ? (array + b) : small;
		if ((array + a) != small)
		{
			switch_ints(array + a, small);
			print_array(array, size);
		}
	}
}
