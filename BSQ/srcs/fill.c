/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 22:51:40 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:52:41 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ_includes.h"
#include "../includes/BSQ.h"

void	fill_logic(t_map *map, t_point *point)
{
	int	i;
	int	j;
	int	count_x;
	int	count_y;

	i = point->y;
	count_y = 0;
	while (count_y < point->size)
	{
		count_x = 0;
		j = point->x;
		while (count_x < point->size)
		{
			map->matrix[i][j] = map->full_ch - '0';
			j--;
			count_x++;
		}
		i--;
		count_y++;
	}
}
