#include "sort.h"

int find_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int digit, int *output);
void radix_sort(int *array, size_t size);

/**
 * find_max - find the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int find_max(int *array, int size)
{
/* Function to find the maximum element in the array*/
int max, i;

for (max = array[0], i = 1; i < size; ++i)
{
if (array[i] > max)
	max = array[i];
}

return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @digit: The significant digit to sort on.
 * @output: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int digit, int *output)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
/* Perform radix-counting sort for each digit place */
int max, digit, *output;

if (array == NULL || size < 2)
return;

output = malloc(sizeof(int) * size);
if (output == NULL)
return;

max = find_max(array, size);
for (digit = 1; max / digit > 0; digit *= 10)
{
radix_counting_sort(array, size, digit, output);
print_array(array, size);
}
free(output);
}
