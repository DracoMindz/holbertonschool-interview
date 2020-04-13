#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * stable_pile - check for stable sand piles
 * @grid: 3 by 3 grid, stable
 * Return: void
 */
int stable_pile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * add_piles- add grids
 * @grid1: 3 by 3 grid, stable
 * @grid2: 3 by 3 grid, stable
 * Return: void function
 */
void add_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
}

/**
 * print_grid - printd grid
 * @grid: 3 by 3 grid, stable
 * Return: void
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * dist_sand - tumble sand piles
 * @grid1: 3 by 3 grid, stable
 * @grid2: 3 by 3 grid, stable
 * Return: void
 */
void dist_sand(int grid1[3][3], int grid2[3][3])
{
	int i, j;


	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid2[i][j] = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid2[i][j] -= 4;
				if (i > 0)
					grid2[i - 1][j] += 1;
				if (i < 2)
					grid2[i + 1][j] += 1;
				if (j > 0)
					grid2[i][j - 1] += 1;
				if (j < 2)
					grid2[i][j + 1] += 1;
			}
		}
	}
	add_piles(grid1, grid2);
}

/**
 * sandpiles_sum - computes sum of two grids
 * @grid1: 3 by 3 grid, stable
 * @grid2: 3 by 3 grid, stable
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_piles(grid1, grid2);
	while (stable_pile(grid1))
	{
		print_grid(grid1);
		dist_sand(grid1, grid2);
	}
}
