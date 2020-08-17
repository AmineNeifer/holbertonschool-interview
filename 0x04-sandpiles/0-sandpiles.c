#include "sandpiles.h"
#include <stdio.h>
/**
 * sandpiles_sum - computes the sum of two sandpiles.
 *
 * @grid1: 3x3 matrix.
 * @grid2: 3x3 matrix.
 *
 * Return: nothing.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int grid[3][3], i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (check_sandpiles(grid))
	{

		printf("=\n");
		print_gridy(grid);
		topple_sandpiles(grid);
		
	}
	copy_grid(grid1, grid);
}
/**
 * topple_sandpiles - topples sandpile.
 *
 * @grid: matrix 3x3.
 *
 * Return: nothing.
 */
void topple_sandpiles(int grid[3][3])
{
	int i, j, new_grid[3][3];

	copy_grid(new_grid, grid);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				new_grid[i][j] -= 4;
				if (i - 1 >= 0)
					new_grid[i - 1][j]++;
				if (i + 1 < 3)
					new_grid[i + 1][j]++;
				if (j - 1 >= 0)
					new_grid[i][j - 1]++;
				if (j + 1 < 3)
					new_grid[i][j + 1]++;
			}
		}
	}
	copy_grid(grid, new_grid);
}
/**
 * check_sandpiles - check if the grid is stable.
 *
 * @grid: 3x3 matrix.
 *
 * Return: 1 if not stable, 0 otherwise.
 */
int check_sandpiles(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (1);
	return (0);
}
/**
 * print_gridy - prints grid.
 *
 * @grid: 3x3 matrix.
 *
 * Return: nothing.
 */
void print_gridy(int grid[3][3])
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
 * copy_grid - copies grid2 to grid1
 *
 * @grid1: 3x3 matrix.
 * @grid2: 3x3 matrix.
 *
 * Return: nothing.
 */
void copy_grid(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid2[i][j];
		}
	}
}
