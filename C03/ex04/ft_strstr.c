/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:14:17 by silee2            #+#    #+#             */
/*   Updated: 2024/08/24 17:15:06 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*dest;
	char	*src;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			dest = str;
			src = to_find;
			while (*dest && *src && *dest++ == *src)
				src++;
			if (*src == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
