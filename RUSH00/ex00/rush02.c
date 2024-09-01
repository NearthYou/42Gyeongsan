/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:34:33 by silee2            #+#    #+#             */
/*   Updated: 2024/08/13 18:55:39 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_putchar(char c);

// 문자열의 크기를 반환하는 함수.
int	string_length(const char *ch)
{
	int	length;

	length = 0;
	while (ch[length] != '\0')
	{
		length++;
	}
	return (length);
}

// 행과 열의 수를 입력받고 조건에 맞게 행을 출력하는 함수.
void	ft_height(int row, int col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row - 2)
	{
		ft_putchar('B');
		while (j < col - 2)
		{
			ft_putchar(' ');
			j++;
		}
		if (col > 1)
			ft_putchar('B');
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

// 출력할 문자와 열을 입력받고 조건에 따라 열을 출력하는 함수.
void	ft_width(char c, int col)
{
	int	i;

	ft_putchar(c);
	if (col > 1)
	{
		i = 0;
		while (i < col - 2)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar(c);
	}
	ft_putchar('\n');
}

void	rush(int col, int row)
{
	char	*ch;

	ch = "자연수의 값을 넣어주십시오.\n";
	if (row <= 0 || col <= 0)
	{
		write(1, ch, string_length(ch));
		return ;
	}
	ft_width('A', col);
	ft_height(row, col);
	if (row > 1)
		ft_width('C', col);
}
