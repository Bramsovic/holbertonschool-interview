#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - Print a 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (col)
				printf(" ");
			printf("%d", grid[row][col]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Check whether a 3x3 grid is unstable
 * @grid: 3x3 grid
 *
 * Return: 1 if unstable, otherwise 0
 */
static int is_unstable(int grid[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid[row][col] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple - Topple all unstable cells in a 3x3 grid once
 * @grid: 3x3 grid
 */
static void topple(int grid[3][3])
{
	int row, col;
	int fallen[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid[row][col] > 3)
				fallen[row][col] = 1;
		}
	}

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (fallen[row][col])
			{
				grid[row][col] -= 4;
				if (row > 0)
					grid[row - 1][col] += 1;
				if (row < 2)
					grid[row + 1][col] += 1;
				if (col > 0)
					grid[row][col - 1] += 1;
				if (col < 2)
					grid[row][col + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
			grid1[row][col] += grid2[row][col];
	}

	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
