#include "sort.h"

/**
 * merge_array - merge array after split
 *
 * @array: The array to be merged
 * @l_num: lowest number in array
 * @m_num: middle number in array
 * @h_num: highest number in array
 */
void merge_array(int array[], int l_num, int m_num, int h_num)
{
	/* temporary array equal length betw h_num and l_num */
	int *temp_arr =  malloc(sizeof(int[h_num - l_num + 1]));
	/* designate left-hand and right-hand*/
	int left = l_num;
	int right = m_num + 1;
	int k = 0; /* element in temp array */

	while (left <= m_num && right <= h_num)
	{
		if (array[left] <= array[right])
			temp_arr[k++] = array[left++];
		else
			temp_arr[k++] = array[right++];
	}
	/* left-side */
	while (left <= m_num)
		temp_arr[k++] = array[left++];
	/* right-side */
	while (right <= h_num)
		temp_arr[k++] = array[right++];
	/* copy temp array to array */
	for (k = 0, left = l_num; left <= h_num; left++, ++k)
		array[left] = temp_arr[k];
	/* temp array not needed */
	free(temp_arr);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @l_num: lowest number in array
 * @h_num: highest number in array
 */
void split_array(int array[], int l_num, int h_num)
{
	int m_num;

	if (l_num < h_num)
	{
		/* find mid number */
		m_num = (l_num + (h_num - 1)) / 2;
		/* first half */
		split_array(array, l_num, m_num);
		/* second half */
		split_array(array, m_num + 1, h_num);

		/* merger arrays*/
		merge_array(array, l_num, m_num, h_num);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	split_array(array, 0, size - 1);
}
