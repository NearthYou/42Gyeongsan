/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:05:36 by silee2            #+#    #+#             */
/*   Updated: 2024/08/21 22:27:00 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SIZE 4

int		check_left_right_constraints(int **grid, const int *clues);
int		check_top_bottom_constraints(int **grid, const int *clues);
int		check_all_constraints(int **grid, const int *clues);
int		solve_recursively(int **grid, const int *clues, int row, int col);
void	solve_puzzle(int **grid, const int *clues);
void	display_grid(int **grid, int rows, int cols);
int		place_numbers(int **grid, const int *clues, int row, int col);
int		check_line_visibility(int *line, int clue, int size, int reverse);

void	solve_puzzle(int **grid, const int *clues)
{
	if (solve_recursively(grid, clues, 0, 0))
		display_grid(grid, SIZE, SIZE);
	else
		display_grid(grid, SIZE, SIZE);
}

int	solve_recursively(int **grid, const int *clues, int row, int col)
{
	if (row == SIZE)
		return (check_all_constraints(grid, clues));
	if (col == SIZE)
		return (solve_recursively(grid, clues, row + 1, 0));
	if (grid[row][col] != 0)
		return (solve_recursively(grid, clues, row, col + 1));
	return (place_numbers(grid, clues, row, col));
}

int	check_all_constraints(int **grid, const int *clues)
{
	return (check_left_right_constraints(grid, clues)
		&& check_top_bottom_constraints(grid, clues));
}

int	check_left_right_constraints(int **grid, const int *clues)
{
	int	row;

	row = 0;
	while (row < SIZE)
	{
		if (!check_line_visibility(grid[row], clues[row], SIZE, 0)
			|| !check_line_visibility(grid[row], clues[SIZE + row], SIZE, 1))
			return (0);
		row++;
	}
	return (1);
}

int	check_top_bottom_constraints(int **grid, const int *clues)
{
	int	col;
	int	row;
	int	column[SIZE];

	col = 0;
	while (col < SIZE)
	{
		row = -1;
		while (++row < SIZE)
			column[row] = grid[row][col];
		if (!check_line_visibility(column, clues[2 * SIZE + col], SIZE, 0)
			|| !check_line_visibility(column, clues[3 * SIZE + col], SIZE, 1))
			return (0);
		col++;
	}
	return (1);
}
