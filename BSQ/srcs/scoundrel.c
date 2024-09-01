/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoundrel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:57:47 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 22:47:42 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BSQ_includes.h"
#include "../includes/BSQ.h"

void	error(char *str)
{
	while (*str != '\0')
	{
		write(2, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

t_point	*init_point(t_point *p)
{
	p = (t_point *)malloc(sizeof(t_point));
	p->size = 1;
	p->x = 0;
	p->y = 0;
	return (p);
}
