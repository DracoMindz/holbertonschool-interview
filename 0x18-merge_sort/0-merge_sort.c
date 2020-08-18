#include "sort.h"

/**
 * merge_array - merge array after split
 *
 * @array: The array to be merged
 * @left: left side of array
 * @right: right side of array
 * @size: size of array
 */
void merge_array(int *array, int *left, int *right, size_t size)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int rcount, lcount;

	lcount = size / 2;
	rcount = size - lcount;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, lcount);
	printf("[right]: ");
	print_array(right, rcount);

	while (i < lcount && j < rcount)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < lcount)
		array[k++] = left[i++];
	while (j < rcount)
		array[k++] = right[j++];
	printf("[Done]: ");
	print_array(array, size);
}


/**
 * merge_sort - sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	size_t midarr = 0;
	size_t idx;
	int left[1000]; /* instead of malloc, temp array */
	int right[1000]; /* instead of malloc, temp array */

	/* Null cases */
	if (size < 2)
		return;
	if (!array)
		return;

	midarr = size / 2;
	/* creating leftside and right side sub arrays*/
	for (idx = 0; idx < midarr; idx++)
		left[idx] = array[idx];
	for (idx = midarr;  idx < size; idx++)
		right[idx - midarr] = array[idx];
	merge_sort(left, midarr);
	merge_sort(right, size - midarr);
	merge_array(array, left, right, size);
}
