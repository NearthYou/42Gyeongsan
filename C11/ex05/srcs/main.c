/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:07 by silee2            #+#    #+#             */
/*   Updated: 2024/09/01 19:44:32 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char*argvs[])
{
	if (argc == 4)
	{
		ft_calc(argvs[1], argvs[2], argvs[3]);
	}
	return (0);
}
