/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:59:09 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:51:28 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/BSQ_includes.h"
#include "./includes/BSQ.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		flag;
	t_map	*map;
	t_map	*dp_map;

	map = (t_map *)malloc(sizeof(t_map) * (argc - 1));
	dp_map = (t_map *)malloc(sizeof(t_map));
	i = 0;
	while (i + 1 < argc)
	{
		flag = read_file(argv[i + 1], &map[i]);
		if (flag == -1)
			return (0);
		else if (flag == -2)
		{
			i++;
			continue ;
		}
		init_dp(&map[i], dp_map);
		soulution_bsq(&map[i], dp_map);
		put_matrix(&map[i]);
		i++;
	}
	free_all(map, dp_map);
}
