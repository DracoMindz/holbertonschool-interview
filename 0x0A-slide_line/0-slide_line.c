#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"


/**
 * slide_line - function thst slides & merges array of integers
 *
 * @line: pointer to array of ints
 * @size: elements contained in array
 * @direction: directioni the elements must be slid
 * Return: 1 = success; or 0 = failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (!line || size < 1)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		dirLeft(line, size);
		/* printf("%d\n", *line); */
		comLeft(line, size);
		/* printf("%d\n", *line);*/
		dirLeft(line, size);
		/*printf("%d\n", *line);*/
	}
	else if (direction == SLIDE_RIGHT)
	{
		dirRight(line, size);
		comRight(line, size);
		dirRight(line, size);
	}
	return (1);
	(void)line;
	(void)size;
	(void)direction;
}

/**
 * comRight- function combines right
 * @line: pointer to array of ints
 * @size: elements contained in array
 * Return: void
 */
int comRight(int *line, size_t size)
{
	ssize_t r = 0, merg = 0;

	for (r = size - 2; r >= 0; r--)
	{
		if (line[r] == line[r + 1])
		{
			merg++;
			line[r + 1] *= 2;
			line[r] = 0;
		}
	}
	return (1);
}
/**
 * comLeft- function combines right
 * @line: pointer to array of ints
 * @size: elements contained in array
 * Return: void
 */
int comLeft(int *line, size_t size)
{
	size_t left = 0, mergs = 0;

	for (left = 1; left < size; left++)
	{
		if (line[left] == line[left - 1])
		{
			mergs++;
			line[left - 1] *= 2;
			line[left] = 0;
		}
	}
	return (1);
}
/**
 * dirLeft- function thst slides right
 * @line: pointer to array of ints
 * @size: elements contained in array
 * Return: void
 */
int dirLeft(int *line, size_t size)
{
	size_t left = 0, zero = 0;

	for  (left = 0; left < size; left++)
	{
		if (!line[left])
			zero++;
		else if (zero)
			line[left - zero] = line[left];
	}
	for (left = size - zero; left < size; left++)
		line[left] = 0;
	return (1);
}

/**
 * dirRight- function thst slides right
 *
 * @line: pointer to array of ints
 * @size: elements contained in array
 * Return: void
 */
int dirRight(int *line, size_t size)
{
	ssize_t right = 0, zero = 0;

	for  (right = size - 1; right >= 0; right--)
	{
		if (!line[right])
			zero++;
		else if (zero)
			line[right + zero] = line[right];
	}
	for (right = zero - 1; right >= 0; right--)
		line[right] = 0;
	return (1);
}
