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
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @lo: The starting index of left side of the pivot.
 * @hi: The ending index of right side of the pivot.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the driver.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int lo, int hi)
{
	int  i, j, pivot;

	pivot = array[hi];
	for (i = lo - 1, j = hi + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(array + i, array + j);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lo: The starting index of left side of the pivot.
 * @hi: The ending index of right side of the pivot.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int lo, int hi)
{
int p;
if (lo >= 0 && hi >= 0 && lo < hi)
{
p = hoare_partition(array, size, lo, hi);
hoare_sort(array, size, lo, p - 1);
hoare_sort(array, size, p, hi);
}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size)
		return;

	hoare_sort(array, size, 0, size - 1);
}
