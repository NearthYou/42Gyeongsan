/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:53:11 by silee2            #+#    #+#             */
/*   Updated: 2024/08/31 09:51:33 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

int	ft_str_len(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
		if (!is_charset(*str++, charset))
			count++;
	return (count);
}

char	*str_dup(char *src, char *charset)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (src[len] && !is_charset(src[len], charset))
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (++i < len)
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		len;
	int		i;
	char	**result;

	len = ft_str_len(str, charset);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			result[i++] = str_dup(str, charset);
			while (!is_charset(*str, charset) && *str)
				str++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
