#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - printd grid
 * @grid: 3 by 3 grid, stable
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * sandpiles_sum - computes sum of two grids
 * @grid1: 3 by 3 grid, stable
 * @grid2: 3 by 3 grid, stable
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, m;
	int flag = 1;

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	printf("=\n");
	print_grid(grid1);
	while (flag == 1)
	{
		flag = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				m = grid1[i][j];
				if (m >= 4)
				{
					flag = 1;
					printf("=\n");
					print_grid(grid1);
					grid1[i][j] = m - 4;
					if (i > 0)
						grid1[i - 1][j] = grid1[i - 1][j] + 1;
					if (i < 2)
						grid1[i + 1][j] = grid1[i + 1][j] + 1;
					if (j > 0)
						grid1[i][j - 1] = grid1[i][j - 1] + 1;
					if (j < 2)
						grid1[i][j + 1] = grid1[i][j + 1] + 1;
				}
			}
		}
	}
}
