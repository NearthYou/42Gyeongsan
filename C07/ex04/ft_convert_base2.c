/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:03:52 by silee2            #+#    #+#             */
/*   Updated: 2024/08/30 13:52:13 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char src)
{
	char	*start;

	start = dest;
	while (*dest)
		dest++;
	*dest = src;
	dest++;
	*dest = '\0';
	return (start);
}

int	ft_contains_index(char *base, char c)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	while (*base)
	{
		if (*base == c)
			return (index);
		base++;
		index++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base, int len)
{
	int	sign;
	int	result;
	int	contain;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		contain = ft_contains_index(base, *str);
		if (contain == -1)
			break ;
		result = result * len + contain;
		str++;
	}
	return (sign * result);
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || base[i] == '\t' || base[i] == '\n'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r'
			|| base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	return (ft_atoi(str, base, base_len));
}
