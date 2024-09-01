/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:58:49 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:53:40 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/BSQ_includes.h"
#include "../../includes/BSQ.h"

int	error_check(t_map *map)
{
	if (map->y_line <= 0
		|| map->x_line <= 0
		|| map->empty_ch == map->obstacle_ch
		|| map->empty_ch == map->full_ch
		|| map->obstacle_ch == map->full_ch)
		return (1);
	if (32 <= map-> empty_ch && map->empty_ch > 126)
		return (1);
	if (32 <= map-> full_ch && map->full_ch > 126)
		return (1);
	if (32 <= map-> obstacle_ch && map->obstacle_ch > 126)
		return (1);
	return (0);
}

int	setting_map(t_map *map, char *first_line, int len)
{
	map->full_ch = first_line[len - 1];
	map->obstacle_ch = first_line[len - 2];
	map->empty_ch = first_line[len - 3];
	first_line[len - 3] = '\0';
	map->y_line = ft_atoi(first_line);
	if (map->y_line == -1)
		return (-1);
	return (1);
}

int	read_firstline(int fd, t_map *map)
{
	char	first_line[20];
	char	buf;
	int		i;

	i = 0;
	while (i < 20)
		first_line[i++] = '\0';
	i = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			break ;
		first_line[i] = buf;
		i++;
	}
	if (setting_map(map, first_line, i) == -1)
		return (-1);
	i = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			break ;
		i++;
	}
	map->x_line = i;
	return (1);
}

t_map	*setting_matrix(int fd, t_map *map)
{
	int		i;
	int		j;
	char	buf;
	char	is_end;

	map->matrix = (int **)malloc(sizeof(int *) * map->y_line);
	i = 0;
	while (i < map->y_line)
	{
		map->matrix[i] = (int *)malloc(sizeof(int) * (map->x_line + 1));
		j = 0;
		while (1)
		{
			is_end = read(fd, &buf, 1);
			if (is_end == 0)
			{
				if (i == map->y_line)
					return (map);
				else
				{
					error("map yline error");
					return (NULL);
				}
			}

			if (buf == '\n')
				break ;
			if (buf != map->empty_ch && buf != map->obstacle_ch)
			{
				error("map charcter error");
				return (NULL);
			}
			map->matrix[i][j] = buf - '0';
			j++;
		}
		if (j != map->x_line)
		{
			printf("%d\n", map->y_line);
			printf("%d\n", i);
			printf("%d\n", j);
			error("map xline error");
			return (NULL);
		}
		map->matrix[i][j] = '\n' - '0';
		i++;
	}
	map->matrix[i - 1][j] = '\n' - '0';
	return (map);
}

int	read_file(char *basename, t_map *map)
{
	char	buf;
	int		i;
	int		j;
	int		k;
	int		fd;

	fd = open(basename, O_RDONLY);
	if (fd <= 0)
	{
		error("Can't open file\n");
		return (-1);
	}
	if (read_firstline(fd, map) == -1)
	{
		error("format error");
		return (-2);
	}
	if (error_check(map))
	{
		error("format error");
		return (-2);
	}
	close(fd);
	fd = open(basename, O_RDONLY);
	if (fd <= 0)
	{
		error("Can't open file");
		return (-1);
	}
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			break ;
	}
	map = setting_matrix(fd, map);
	if (map == NULL)
	{
		return (-2);
	}
	return (1);
}

