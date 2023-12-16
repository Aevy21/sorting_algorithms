#include "sort.h"

void swap(int *a, int *b);
int is_sorted(int *array, size_t size);
/**
 * selection_sort - an algorithm that sorts an array through selection
 * @array: pointer to an array
 * @size: size of the array
 * Return: returns nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t k, j;
	size_t m;
	int sorted;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (k = 0; k < size - 1; k++)
	{
		m = k;
		for (j = k + 1; j < size; j++)
		{
			if (array[j] < array[m])
			{
				m = j;
			}
		}
		if (m != k)
		{
			swap(&array[k], &array[m]);
			sorted = is_sorted(array, size);

		}
		if (!sorted)
		{
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps elements an an array
 * @b: an integer
 * @a: an integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * is_sorted - checks if an array has been sorted
 * @array: pointer to an array
 * @size: the size of the array
 * Return: 0 Success, 1 Failure
 */
int is_sorted(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return (0);
		}
	}
	return (1);
}
