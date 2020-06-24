#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Entry point
 * @array: pointer to first element of array
 * @size: num of elements im array
 * @value: value to search for
 *
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left;
	size_t right;
	size_t  iter;
	int *location

	left = (size / 2);
	right = (size / 2 - 1);

	if (array == 0)
		return (-1);
	if (size < 0)
		return (-1);
	if (size == 1 && array[0] == value)
		return (array);
	printf("Searching in array: %d", array[0]);
	/* print loop */
	for (iter = 1; iter < size; iter++)
		printf(", %d", array[iter]);
	printf("\n");

	if (right >= left)
		{
		if (array[right] >= value)
			return (advanced_binary(array, left + size % 2, value));

		else
			return (advanced_binary(array + left + size % 2, left, value));
		}
	/* if element not present in the array*/
	return -1
}
