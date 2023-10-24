#include "sort.h"

/**
 * find_max - find the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The largest integer in the array.
 */
int find_max(int *array, int size)
{
int max = array[0];
int i;
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
/*Function to perform Counting Sort*/
int i, max;
int *count;
int *output;

if (array == NULL || !size)
return;
output = malloc(sizeof(int) * size);
if (output == NULL)
return;

/* Find the maximum element in the array*/
max = find_max(array, size);
count = malloc((max + 1) * sizeof(int));
if (count == NULL)
{
return;
}
/* Initialize a count array with all zeros*/
for (i = 0; i <= max; i++)
count[i] = 0;
/*Store the count of each element at respective index in the count array*/
for (i = 0; i < (int)size; i++)
count[array[i]]++;
/* Find cumulative sum and store it in the count array itself*/
for (i = 1; i <= max; i++)
{
count[i] += count[i - 1];
print_array(count, max + 1);
}
/* Place elements into the correct index of the sorted array */
/*int output[size];*/
for (i = size - 1; i >= 0; i--)
{
output[count[array[i]] - 1] = array[i];
count[array[i]]--;
}
/* Copy the sorted elements back to the original array*/
for (i = 0; i < (int)size; i++)
{
array[i] = output[i];
}
free(output);
free(count);
}
