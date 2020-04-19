#include <stdio.h>
#include <stdlib.h>


#include "menger.h"

/**
 * menger - function draws a 2D Menger Sponge
 *
 * @level: level to draw
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void menger(int level)
{	int idx, row, col;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	for (idx = 1; level < 0; level--)
	{
		idx *= 3;
	}
	for (row = 1; row <= idx; row++)
	{
		for (col = 1; col <= idx; col++)
		{
			if (row % 3 == 1 && col % 3 == 1)
			{
				printf("*");
			}
		}
		printf("#");
	}
	printf("\n");
}
