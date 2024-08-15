/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:23:31 by silee2            #+#    #+#             */
/*   Updated: 2024/08/15 20:29:38 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_string(char *str, int origin)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	if (str[-(10 - origin)] != ('0' + origin))
		write(1, ", ", 2);
}

void	ft_recursion(int count, int origin, char *str)
{
	int	i;

	if (str[count + 1] != '\0')
	{
		str[count + 1] = str[count] + 1;
		ft_recursion(count + 1, origin, str);
	}
	else
	{
		i = -1;
		while (i++ < origin + 1 && str[count] <= '9')
		{
			ft_print_string(str, origin);
			str[count] += 1;
		}
		i = 0;
		while (i++ < count)
		{
			if (str[count - i] != ('0' + count - i + origin))
			{
				str[count - i]++;
				ft_recursion(count - i, origin, str);
			}
		}
	}
}

void	ft_print_combn(int n)
{
	char	str[10];
	int		i;

	i = 0;
	while (i < n)
	{
		str[i] = '0';
		i++;
	}
	str[n] = '\0';
	ft_recursion(0, 10 - n, str);
}

int	main(void)
{
	return (0);
}
