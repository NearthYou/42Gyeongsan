/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:54:56 by silee2            #+#    #+#             */
/*   Updated: 2024/08/21 22:27:53 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define SIZE 4

void	print_char(char c);
void	display_grid(int **grid, int rows, int cols);
int		**allocate_grid(int rows, int cols);
void	initialize_grid(int **grid, int rows, int cols);
int		parse_clues(const char *input, int clues[]);
void	free_grid(int **grid, int rows);
void	solve_puzzle(int **grid, const int *clues);

int	main(int argc, char *argv[])
{
	int	**grid;
	int	clues[SIZE * 4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	grid = allocate_grid(SIZE, SIZE);
	if (!grid)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	initialize_grid(grid, SIZE, SIZE);
	if (!parse_clues(argv[1], clues))
	{
		write(1, "Error\n", 6);
		free_grid(grid, SIZE);
		return (1);
	}
	solve_puzzle(grid, clues);
	free_grid(grid, SIZE);
	return (0);
}

void	print_char(char c)
{
	write(1, &c, 1);
}

void	display_grid(int **grid, int rows, int cols)
{
	int	row;
	int	col;

	col = -1;
	while (++col < cols)
	{
		row = -1;
		while (++row < rows)
		{
			if (grid[row][col] > 9)
			{
				print_char('0' + grid[row][col] / 10);
			}
			print_char('0' + grid[row][col] % 10);
			if (row < rows - 1)
			{
				print_char(' ');
			}
		}
		print_char('\n');
	}
}
