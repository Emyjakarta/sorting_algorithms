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
 * shell_sort-sorts an array of integers in ascending
 * order using the shell sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t space, a, b;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;
	for (; space >= 1; space /= 3)
	{
		for (a = space; a < size; a++)
		{
			b = a;
			while (b >= space && array[b - space] > array[b])
			{
				switch_ints(array + b, array + (b - space));
				b -= space;
			}
		}
		print_array(array, size);
	}
}
