/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:40:20 by silee2            #+#    #+#             */
/*   Updated: 2024/08/19 02:02:05 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	hex_string(unsigned long long num)
{
	int					i;
	const char			*hex_digits;
	unsigned char		buffer[16];

	hex_digits = "0123456789abcdef";
	i = 16;
	while (i-- > 0)
	{
		buffer[i] = hex_digits[num % 16];
		num /= 16;
	}
	write(1, buffer, 16);
	ft_putchar(':');
	ft_putchar(' ');
}

void	ascii_string(unsigned char *addr, unsigned int num, unsigned int size)
{
	const char		*hex_digits;
	unsigned int	i;

	hex_digits = "0123456789abcdef";
	i = -1;
	while (++i < 16)
	{
		if (i < size)
		{
			ft_putchar(hex_digits[addr[num + i] / 16]);
			ft_putchar(hex_digits[addr[num + i] % 16]);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
	}
}

void	print_string(unsigned char *addr, unsigned int num, unsigned int size)
{
	unsigned int	i;

	i = -1;
	while (++i < size)
	{
		if (addr[num + i] < 32 || addr[num + i] >= 127)
			ft_putchar('.');
		else
			ft_putchar(addr[num + i]);
	}
	if (addr[num + i] == '\0')
		ft_putchar('.');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	index;
	int				rest;
	int				save;

	index = -1;
	rest = 0;
	save = size;
	while (++index * 16 < size)
	{
		if (save > 16)
		{	
			rest = 16;
			save -= 16;
		}
		else
			rest = save;
		hex_string((unsigned long long)addr + index * 16);
		ascii_string((unsigned char *)addr, index * 16, rest);
		print_string((unsigned char *)addr, index * 16, rest);
		ft_putchar('\n');
	}
	return (addr);
}
