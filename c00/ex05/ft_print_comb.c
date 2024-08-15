/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 02:45:48 by silee2            #+#    #+#             */
/*   Updated: 2024/08/14 14:29:31 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_string(char *ch)
{
	while (*ch)
	{
		write(1, ch, 1);
		ch++;
	}
}

void	set_string(char *dest, const char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

void	ft_print_comb(void)
{
	char	c[3];

	set_string(c, "012");
	while (c[0] <= '7')
	{
		if (c[2] > c[1] && c[1] > c[0])
		{
			ft_print_string(c);
			if (c[0] != '7')
				ft_print_string(", ");
		}
		c[2]++;
		if (c[2] > '9')
		{
			c[2] = '0';
			c[1]++;
			if (c[1] > '9')
			{
				c[1] = '0';
				c[0]++;
			}
			continue ;
		}
	}
}
