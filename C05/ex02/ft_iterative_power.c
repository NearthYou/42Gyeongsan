/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:20:58 by silee2            #+#    #+#             */
/*   Updated: 2024/08/27 01:07:45 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = -1;
	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (++i < power)
		result *= nb;
	return (result);
}
