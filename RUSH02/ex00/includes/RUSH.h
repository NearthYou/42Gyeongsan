/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:00:18 by takwak            #+#    #+#             */
/*   Updated: 2024/08/28 17:00:06 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct s_dict
{
	char	*num;
	char	*word;
}	t_dict;

char	*ft_strncpy(char *dest, char *src, int n);
int	ft_atoi(char *str);
char	*ft_strdup(char *src);
int	ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
int	check_dict_error(char *buffer);
t_dict *parse_dict(char *dict_file);
char	*find_word(t_dict *dict, char *num);
void	get_pos(int quotient, t_dict *dict, char *output);
void	init_array(char *str);
void	convert_to_words(char *num, t_dict *dict);
int	ft_strcmp(char *s1, char *s2);

#endif
