/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 03:41:11 by silee2            #+#    #+#             */
/*   Updated: 2024/08/25 04:12:14 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_duplicate(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		if (count == 2)
			return (1);
		str++;
	}
	return (0);
}

int	ft_check(char *str)
{
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (1);
		if (ft_is_duplicate(str, *str))
			return (1);
		str++;
	}
	return (0);
}

void	ft_recursive(int nbr, int len, char *base)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_recursive(-(nbr / len), len, base);
		ft_putchar(base[-(nbr % len)]);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= len)
		ft_recursive(nbr / len, len, base);
	ft_putchar(base[nbr % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (len == 1 || len == 0)
		return ;
	if (ft_check(base))
		return ;
	ft_recursive(nbr, len, base);
}
