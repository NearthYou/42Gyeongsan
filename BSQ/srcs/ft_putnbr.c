/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:23:17 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:32:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ_includes.h"
#include "../includes/BSQ.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

char	*tostring(char *str, int nb)
{
	str = str + 10;
	while (nb > 0)
	{
		str--;
		*str = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

void	ft_putnbr(int nb)
{
	char	str[11];

	str[10] = '\0';
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb > 0)
		ft_putstr(tostring(str, nb));
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		ft_putstr(tostring(str, nb));
	}
	else
		write(1, "0", 1);
}
