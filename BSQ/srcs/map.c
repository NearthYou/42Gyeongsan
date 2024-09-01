/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:25:49 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:40:39 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ_includes.h"
#include "../includes/BSQ.h"

void	put_matrix(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->y_line)
	{
		j = 0;
		while (j < map->x_line + 1)
		{
			c = map->matrix[i][j] + '0';
			write(1, &c, 1);
			j++;
		}
		i++;
	}
}
