/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:27:07 by silee2            #+#    #+#             */
/*   Updated: 2024/08/29 04:33:33 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstring(int argc, char **argvs)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		write(1, argvs[i], ft_len(argvs[i]));
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argvs[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			j = 0;
			while (++j < argc)
			{
				if (ft_strcmp(argvs[i], argvs[j]) < 0)
				{
					tmp = argvs[i];
					argvs[i] = argvs[j];
					argvs[j] = tmp;
				}
			}
		}
		ft_putstring(argc, argvs);
	}
	return (0);
}
