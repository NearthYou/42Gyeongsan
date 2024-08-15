/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:13:41 by silee2            #+#    #+#             */
/*   Updated: 2024/08/14 13:39:03 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	string_length(const char *ch);
extern void	ft_height(int col, int row);
extern void	ft_width(char c, int col, int row);
extern void	rush(int col, int row);

// 공백 문자를 무시하는 함수
int	skip_whitespace(const char *str, int index)
{
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
	{
		index++;
	}
	return (index);
}

// 부호를 처리하고, 부호 정보와 인덱스를 반환하는 함수
int	process_sign(const char *str, int index, int *sign)
{
	if (str[index] == '-')
	{
		*sign = -1;
		index++;
	}
	else if (str[index] == '+')
	{
		index++;
	}
	return (index);
}

// 문자열에서 숫자를 변환하는 함수
int	convert_to_number(const char *str, int index)
{
	int	result;

	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result);
}

// ASCII코드의 숫자를 값으로 반환해주는 함수.
int	my_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	i = skip_whitespace(str, i);
	i = process_sign(str, i, &sign);
	result = convert_to_number(str, i);
	return (sign * result);
}

int	main(int argc, char *argvs[])
{
	int		x;
	int		y;
	char	*c;

	x = 5;
	y = 1;
	c = "사용법: 두 가지의 숫자를 입력해주세요.\n";
	if (argc >= 2)
	{
		if (argc == 2 || argc > 3)
		{
			write(1, c, string_length(c));
			return (-1);
		}
		x = my_atoi(argvs[1]);
		y = my_atoi(argvs[2]);
	}
	if (x > 9999 || y > 9999)
	{
		c = "출력 가능한 라인의 수는 9999 입니다. 그 밑의 숫자를 입력해주세요.\n";
		write(1, c, string_length(c));
		return (-1);
	}
	rush(x, y);
	return (0);
}
