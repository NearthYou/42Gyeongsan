/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:03:52 by silee2            #+#    #+#             */
/*   Updated: 2024/08/30 13:49:36 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c);
int		ft_contains_index(char *base, char c);
int		ft_atoi(char *str, char *base, int len);
int		ft_base_check(char *base);
int		ft_atoi_base(char *str, char *base);
char	*ft_strcat(char *dest, char src);

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

void	ft_recursive(int nbr, int len, char *base, char *ptr)
{
	if (nbr == -2147483648)
	{
		ft_strcat(ptr, '-');
		ft_recursive(-(nbr / len), len, base, ptr);
		ft_strcat(ptr, base[-(nbr % len)]);
		return ;
	}
	if (nbr < 0)
	{
		ft_strcat(ptr, '-');
		nbr *= -1;
	}
	if (nbr >= len)
		ft_recursive(nbr / len, len, base, ptr);
	ft_strcat(ptr, base[nbr % len]);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		len;
	char	*ptr;
	int		num_len;
	int		temp_nbr;

	len = 0;
	num_len = 1;
	temp_nbr = nbr;
	while (base[len])
		len++;
	if (len <= 1 || ft_check(base))
		return (NULL);
	if (nbr < 0)
		num_len++;
	while (temp_nbr != 0)
	{
		temp_nbr /= len;
		num_len++;
	}
	ptr = (char *)malloc(num_len + 1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	ft_recursive(nbr, len, base, ptr);
	return (ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*result;

	if (ft_base_check(base_from) || ft_base_check(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(num, base_to);
	if (!result)
		return (NULL);
	return (result);
}
