/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:34:44 by silee2            #+#    #+#             */
/*   Updated: 2024/09/01 19:29:19 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_dm_zero(char *num, int op)
{
	if (ft_atoi(num) == 0 && (op == 2 || op == 4))
	{
		if (op == 2)
			ft_putstr("Stop : division by zero");
		else
			ft_putstr("Stop : modulo by zero");
		return (1);
	}
	else
		return (0);
}

int	get_operation(char *op)
{
	int		i;
	char	*ops;

	ops = "+-/*%";
	i = -1;
	while (ops[++i])
		if (ops[i] == op[0] && op[1] == '\0')
			return (i);
	return (-1);
}

void	ft_calc(char *n1, char *op, char *n2)
{
	int		(*tab[5])(int, int);
	int		operation;

	tab[0] = add;
	tab[1] = sub;
	tab[2] = div;
	tab[3] = mul;
	tab[4] = mod;
	operation = get_operation(op);
	if (operation != -1)
	{
		if (!is_dm_zero(n2, operation))
			ft_putnbr(tab[operation](ft_atoi(n1), ft_atoi(n2)));
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(0);
		ft_putchar('\n');
	}
}
