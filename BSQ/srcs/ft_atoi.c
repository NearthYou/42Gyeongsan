/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 22:03:28 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 18:11:59 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}

int	ft_isnum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	str_toint(char *str)
{
	int	i;
	int	result;
	int	len;
	int	mul;

	len = 0;
	while (*str == '0')
		str++;
	while (str[len] != '\0')
		len++;
	result = 0;
	i = 0;
	mul = 1;
	while (i < len)
	{
		result += (str[len - 1 - i] - '0') * mul;
		mul *= 10;
		i++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int		i;
	int		num;
	char	str_num[101];
	int		fl;

	num = 0;
	i = 0;
	fl = 1;
	while (i < 101)
		str_num[i++] = '\0';
	i = 0;
	if (*str == '-')
	{
		fl = -1;
		str++;
	}
	while (ft_isnum(*str))
		str_num[i++] = *str++;
	if (*str != '\0' && !ft_isnum(*str))
		return (-1);
	num = str_toint(str_num);
	return (num * fl);
}
