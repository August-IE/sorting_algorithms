#include <stdio.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_partition - Divides a portion of array into partition according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @lo: The starting index of left side of the pivot.
 * @hi: The ending index of right side of the pivot.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int lo, int hi)
{
	int i, j, *pivot;
    
	pivot = array + hi;
	for (i = j = lo; j < hi; j++)
	{
		 if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 * @lo: The starting index of left side of the pivot.
 * @hi: The ending index of right side of the pivot.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int lo, int hi)
{
	int p;

    if (lo >= hi || lo < 0) 
    return;

	if (lo < hi)
	{
		p = lomuto_partition(array, size, lo, hi);
		lomuto_sort(array, size, lo, p - 1);
		lomuto_sort(array, size, p + 1, hi); 
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
