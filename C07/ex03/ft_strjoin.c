/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:50:16 by silee2            #+#    #+#             */
/*   Updated: 2024/08/31 11:58:33 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

char	*str_cat(char *str1, char *str2)
{
	char	*start;

	start = str1;
	if (!str1 || !str2)
		return (NULL);
	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = '\0';
	return (start);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = 0;
	while (i < size)
		len += str_len(strs[i++]);
	if (size > 0)
		len += (size - 1) * str_len(sep);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = -1;
	while (++i < size)
	{
		str_cat(result, strs[i]);
		if (i < size - 1)
			str_cat(result, sep);
	}
	return (result);
}
