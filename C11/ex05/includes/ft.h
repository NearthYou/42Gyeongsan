/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:44:14 by silee2            #+#    #+#             */
/*   Updated: 2024/09/01 23:33:46 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>

int		add(int n1, int n2);
int		sub(int n1, int n2);
int		div(int n1, int n2);
int		mul(int n1, int n2);
int		mod(int n1, int n2);
int		ft_atoi(char *str);
int		get_operation(char *op);
int		is_dm_zero(char *num, int ope);
void	ft_calc(char *n1, char *op, char *n2);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
#endif