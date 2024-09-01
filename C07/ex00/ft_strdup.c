/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:41:14 by silee2            #+#    #+#             */
/*   Updated: 2024/08/31 09:39:30 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (src[len++])
		;
	str = (char *)malloc(sizeof(char) * (len + 1));
	while (++i < len)
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
