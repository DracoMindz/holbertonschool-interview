#include "sort.h"
#include <stdint.h>


/**
 * radix_sort - sort array of integers in ascending
 * @array: contains numbers to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t count[10], idx, flag;
	int *output, exp = 1;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	output = malloc(size * sizeof(int));

	/*for (num = 0; num < 10; num++)*/
	while (flag != 0)
	{
		flag = 0;

		for (idx = 0; idx < size; idx++)
			{
			count[(array[idx] / exp) % 10]++;
			/* flag counter */
			flag += (array[idx] / exp % 10) % 10 == 0 ? 0 : 1;
			}
		if (flag == 0)
			continue; /* go to the next arr[i] */

		for (idx = 1; idx < 10; idx++)
			count[idx] += count[idx - 1];
		for (idx = size - 1; idx != SIZE_MAX; idx--)
			{
			output[count[(array[idx] / exp) % 10] - 1] = array[idx];
			count[(array[idx] / exp) % 10]--;
			}
		for (idx = 0; idx < size; idx++)
			array[idx] = output[idx];
		exp *= 10;
		print_array(array, size);
	}
	free(output);
}
