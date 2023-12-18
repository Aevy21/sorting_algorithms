#include "sort.h"

int is_sorted(int *array, size_t size);
/**
 * shell_sort - uses the Knuth sequence to sort an array
 * @array: pointer to an array
 * @size: size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	unsigned long int sequence[] = {364, 121, 40, 13, 4, 1};
	size_t seq_len = sizeof(sequence) / sizeof(int);
	size_t i, j, gap;
	size_t k = 0;
	int temp;

	while (k < seq_len && sequence[k] > size)
	{
		k++;
	}
	for (; k < seq_len; k++)
	{
		gap = sequence[k];
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];

			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		if  (is_sorted(array, size))
		{
			break;
		}
	}
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
