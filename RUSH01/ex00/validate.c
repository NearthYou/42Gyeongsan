/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:10:42 by silee2            #+#    #+#             */
/*   Updated: 2024/08/21 22:28:12 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SIZE 4

int		check_line_visibility(int *line, int clue, int size, int reverse);
int		count_visible_buildings(int *line, int size);
int		place_numbers(int **grid, const int *clues, int row, int col);
int		is_number_valid(int **grid, int row, int col, int num);
int		solve_recursively(int **grid, const int *clues, int row, int col);

int	count_visible_buildings(int *line, int size)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < size)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_line_visibility(int *line, int clue, int size, int reverse)
{
	int	count;
	int	reversed_line[SIZE];
	int	i;

	i = -1;
	if (reverse)
	{
		while (++i < size)
			reversed_line[i] = line[size - 1 - i];
		count = count_visible_buildings(reversed_line, size);
	}
	else
		count = count_visible_buildings(line, size);
	return (count == clue);
}

int	is_number_valid(int **grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	place_numbers(int **grid, const int *clues, int row, int col)
{
	int	num;

	num = 1;
	while (num <= SIZE)
	{
		if (is_number_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_recursively(grid, clues, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
