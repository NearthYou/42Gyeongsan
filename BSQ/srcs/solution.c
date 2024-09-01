/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:15:30 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:47:59 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ_includes.h"
#include "../includes/BSQ.h"

int	init_dp_set(t_map *map, t_map *dp_map)
{
	dp_map->y_line = map->y_line;
	dp_map->x_line = map->x_line;
	dp_map->empty_ch = map->empty_ch;
	dp_map->obstacle_ch = map->obstacle_ch;
	dp_map->full_ch = map->full_ch;
	return (1);
}

t_map	*init_dp(t_map *map, t_map *dp_map)
{
	int	i;
	int	j;

	init_dp_set(map, dp_map);
	dp_map->matrix = (int **)malloc(sizeof(int *) * map->y_line);
	i = 0;
	while (i < map->y_line)
		dp_map->matrix[i++] = (int *)malloc(sizeof(int) * (map->x_line + 1));
	i = 0;
	while (i < map->y_line)
	{
		j = 0;
		while (j < map->x_line)
		{
			if (map->matrix[i][j] + '0' == map->obstacle_ch)
				dp_map->matrix[i][j] = 0;
			else
				dp_map->matrix[i][j] = 1;
			j++;
		}
		dp_map->matrix[i][j] = 10 - '0';
		i++;
	}
	return (dp_map);
}

int	is_placeable(int **matrix, int x, int y)
{
	int	min;

	min = matrix[y][x - 1];
	if (matrix[y][x - 1] == 0
		|| matrix[y - 1][x] == 0
		|| matrix[y - 1][x - 1] == 0)
		return (0);
	else if (matrix[y][x - 1] == matrix[y - 1][x]
		&& matrix[y][x - 1] == matrix[y - 1][x]
		&& matrix[y - 1][x] == matrix[y - 1][x - 1])
		return (-1);
	else
	{
		if (matrix[y - 1][x] < min)
			min = matrix[y - 1][x];
		if (matrix[y - 1][x - 1] < min)
			min = matrix[y - 1][x - 1];
		return (min + 1);
	}
	return (0);
}

void	modify_dp(t_map *dp_map, int x, int y, t_point *max)
{
	int	i;
	int	j;
	int	check;

	j = x;
	i = y;
	check = is_placeable(dp_map->matrix, j, i);
	if (check == -1)
	{
		if (dp_map->matrix[i][j - 1] + 1 > max->size)
		{
			max->size = dp_map->matrix[i][j - 1] + 1;
			dp_map->matrix[i][j] = dp_map->matrix[i][j - 1] + 1;
			max->x = j;
			max->y = i;
		}
		else
		{
			dp_map->matrix[i][j] = dp_map->matrix[i][j - 1] + 1;
		}
	}
	if (check != -1 && check != 0)
		dp_map->matrix[i][j] = check;
}

t_map	*soulution_bsq(t_map *map, t_map *dp_map)
{
	int		i;
	int		j;
	int		check;
	t_point	*max;

	max = init_point(max);
	i = 1;
	while (i < map->y_line)
	{
		j = 1;
		while (j < map->x_line)
		{
			if (dp_map->matrix[i][j] == 0)
			{
				j++;
				continue ;
			}
			modify_dp(dp_map, j, i, max);
			j++;
		}
		i++;
	}
	fill_logic(map, max);
	free(max);
	return (dp_map);
}
