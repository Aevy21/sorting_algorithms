#include <stddef.h>
#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Sorts an int array in ascending order using bubble sort
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Flag to check if any swaps were made */

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /* Set the flag to true */

				/* Print the array after each swap */
				print_array(array, size);
			}
		}

		/* If no swaps were made, the array is already sorted */
		if (!swapped)
		{
			break;
		}
	}
}