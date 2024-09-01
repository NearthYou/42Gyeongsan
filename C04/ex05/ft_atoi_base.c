/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:48:45 by silee2            #+#    #+#             */
/*   Updated: 2024/08/26 01:02:11 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
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
	while (is_space(*str))
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

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (is_space(base[i]) || base[i] == '+' || base[i] == '-')
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
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2 || ft_check(base))
		return (0);
	return (ft_atoi(str, base, base_len));
}
