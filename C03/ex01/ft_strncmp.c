/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 01:27:55 by silee2            #+#    #+#             */
/*   Updated: 2024/08/24 18:31:25 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < n && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		index++;
		s1++;
		s2++;
	}
	if (index < n)
		return (*s1 - *s2);
	return (0);
}
