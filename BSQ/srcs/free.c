/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:12:23 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:54:07 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ_includes.h"
#include "../includes/BSQ.h"

void	free_matrix(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->y_line)
	{
		free(map->matrix[row]);
		row++;
	}
	free(map->matrix);
}

void	free_all(t_map *map, t_map *dp_map)
{
	free_matrix(map);
	free_matrix(dp_map);
	free(map);
	free(dp_map);
}
