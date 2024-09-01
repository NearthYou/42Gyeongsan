/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:03:29 by silee2            #+#    #+#             */
/*   Updated: 2024/08/21 22:20:25 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SIZE 4

void	initialize_grid(int **grid, int rows, int cols)
{
	int	row;
	int	col;

	row = 0;
	while (row < rows)
	{
		col = 0;
		while (col < cols)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	**allocate_grid(int rows, int cols)
{
	int	**grid;
	int	row;
	int	col;

	grid = (int **)malloc(rows * sizeof(int *));
	if (!grid)
		return (0);
	row = -1;
	while (++row < rows)
	{
		grid[row] = (int *)malloc(cols * sizeof(int));
		if (!grid[row])
		{
			col = -1;
			while (++col < row)
				free(grid[col]);
			free(grid);
			return (0);
		}
	}
	return (grid);
}

void	free_grid(int **grid, int rows)
{
	int	row;

	row = 0;
	while (row < rows)
	{
		free(grid[row]);
		row++;
	}
	free(grid);
}

int	parse_clues(const char *input, int clues[])
{
	int	index;

	index = 0;
	while (*input)
	{
		while (*input == ' ' || *input == '\t')
			input++;
		if (*input >= '1' && *input <= '4')
			clues[index++] = *input - '0';
		else if (*input == '\0')
			break ;
		else
			return (0);
		input++;
	}
	if (index != SIZE * 4)
		return (0);
	return (1);
}
