/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 02:11:07 by silee2            #+#    #+#             */
/*   Updated: 2024/08/19 02:11:29 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric_or_alphabet(char c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = -1;
	while (str[++i] != '\0')
	{
		first = 0;
		if (!is_numeric_or_alphabet(str[i - 1]))
			first = 1;
		if (str[i] >= 'a' && str[i] <= 'z' && first == 1)
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (first == 1)
				continue ;
			str[i] += 32;
		}
	}
	return (str);
}
