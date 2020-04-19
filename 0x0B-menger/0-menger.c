#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "menger.h"

/**
 * menger - function draws a 2D Menger Sponge
 *
 * @level: level to draw
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void menger(int level)
{
	long int idx, row, col, space;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	/* create grid */
	for (idx = 1; level > 0; level--)
		idx *= 3;
	for (row = 1; row <= idx; row++)
	{
		for (col = 1; col <= idx; col++)
		{
			for (space = 1; space <= idx; space *= 3)
			{
				if (row % space * 3 <= space * 2 &&
					row % space * 3 >= space + 1 &&
					/*compare row space check to col */
					col % space * 3 <= space * 2 &&
					col % space * 3 >= space + 1)
				{
					/* print space */
					printf(" ");
					break;
				}
			}
			if (space > idx) /* insert # */
				printf("#");
		}
		printf("\n");
	}
}
