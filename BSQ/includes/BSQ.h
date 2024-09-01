/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:18 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:50:58 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		x_line;
	int		y_line;
	char	empty_ch;
	char	obstacle_ch;
	char	full_ch;
	int		**matrix;
}	t_map;
typedef struct s_point
{
	int	x;
	int	y;
	int	size;
}	t_point;
void	error(char *str);
int		ft_atoi(char *str);
int		read_file(char *basename, t_map *map);
void	put_matrix(t_map *map);
t_map	*init_dp(t_map *map, t_map *dp_map);
t_map	*soulution_bsq(t_map *map, t_map *dp_map);
void	ft_putnbr(int nb);
void	fill_logic(t_map *map, t_point *point);
void	free_matrix(t_map *map);
void	free_all(t_map *map, t_map *dp_map);
t_point	*init_point(t_point *p);

#endif
