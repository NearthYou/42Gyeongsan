/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 05:29:23 by silee2            #+#    #+#             */
/*   Updated: 2024/08/28 05:02:19 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}	
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar('0' + (nb % 10));
}

int	validate(int i, int *col)
{
	int	j;
	int	flag;
	int	abs_row;
	int	abs_col;

	j = 1;
	flag = 1;
	while (j < i)
	{
		abs_row = col[i] - col[j];
		abs_col = i - j;
		if (abs_row < 0)
			abs_row *= -1;
		if (abs_col < 0)
			abs_col *= -1;
		if (col[i] == col[j] || abs_row == abs_col)
			flag = 0;
		j++;
	}
	return (flag);
}

void	ten_queens(int num, int size, int *col, int *count)
{
	int	i;

	if (validate(num, col))
	{
		if (num == size)
		{
			i = 0;
			while (++i <= size)
				ft_putnbr(col[i]);
			ft_putchar('\n');
			*count += 1;
			return ;
		}
		else
		{
			i = 1;
			while (i <= size)
			{
				col[num + 1] = i - 1;
				ten_queens(num + 1, size, col, count);
				i++;
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count[1];
	int	col[10];

	ten_queens(0, 10, col, count);
	return (*count);
}
