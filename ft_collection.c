/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 04:53:09 by silee2            #+#    #+#             */
/*   Updated: 2024/08/12 10:44:27 by silee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(const char *str) 
{
       	while (*str) 
	{
		ft_putchar(*str);
		str++;
	}
}

void	set_string(char *dest, const char *src) 
{
	while (*src) 
	{
	    *dest = *src;
	    dest++;
	    src++;
	}
	*dest = '\0';
}

void	my_strcat(char *dest, char *src)
{
	while (*dest) 
		dest++;
	while (*src) 
		*dest++ = *src++;
	*dest = '\0';
}

int main() {
    char str[50];
    char str2[50];

    set_string(str, "Hello, World");
    set_string(str2, "42gyeongsan");

    my_strcat(str, str2);
    ft_putstr(str);      // "Hello, World!" 출력

    return 0;
}
