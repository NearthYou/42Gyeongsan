/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee2 <silee2@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:49:53 by silee2            #+#    #+#             */
/*   Updated: 2024/08/28 23:40:18 by jaewjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RUSH_includes.h"
#include "../includes/RUSH.h"

int	check_dict_error(char *buffer)
{
	int		i;

	i = 0;
	if (!buffer[i])
		return(0);
	while(buffer[i])
	{
		if (!(buffer[i] >= '0' && buffer[i] <= '9'))
			return (0);
		while (buffer[i] >= '0' && buffer[i] <= '9')
			i++;
		if (!(buffer[i] >= 9 && buffer[i] <= 13) && (buffer[i] != ' ' && buffer[i] != ':'))
			return (0);
		while (buffer[i] == ' ' || (buffer[i] >= 9 && buffer[i] <= 13))
			i++;
		if (buffer[i] != ':')
			return (0);
		i++;
		while (buffer[i] == ' ' || (buffer[i] >= 9 && buffer[i] <= 13))
			i++;
		while (buffer[i] != '\n')
		{
			if ((buffer[i] < 32 || buffer[i] > 126) && buffer[i] != '\n')
				return(0);
			i++;
		}
		i++;
	}
	return (1);
}

t_dict *parse_dict(char *dict_file)
{
	int		fd;
	int		ret;
	int		i;
	int		k;
	char	buffer[10000];
	t_dict	*dict;

	fd = open(dict_file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}

	ret = read(fd, buffer, 9999);
	buffer[ret] = '\0';
	close(fd);

	if (!check_dict_error(buffer))
	{
		dict = malloc(sizeof(t_dict) * 100);
		dict[0].num = 0;
		return (dict);
	}
	i = 0;
	k = 0;
	dict = malloc(sizeof(t_dict) * 100);
	while (buffer[i])
	{
		dict[k].num = &buffer[i];
		while (buffer[i] >= '0' && buffer[i] <= '9')
			i++;
		buffer[i++] = '\0';
		while (buffer[i] == ' ' || buffer[i] == '\t')
			i++;
		dict[k].word = &buffer[i];
		while (buffer[i] != '\n')
			i++;
		buffer[i++] = '\0';
		k++;
	}
	dict[k].num = NULL;
	return (dict);
}

char	*find_word(t_dict *dict, char *num)
{
	int	i;

	i = 0;
	while (dict[i].num)
	{
		if (ft_strcmp(dict[i].num, num) == 0)
			return (dict[i].word);
		i++;
	}
	return (NULL);
}

void	get_pos(int quotient, t_dict *dict, char *output)
{
	char	*result;
	char	*result2;

	if (quotient <= 0)
		return ;
	result = (char *)malloc(sizeof(char) * (quotient * 3 + 2));
	result[0] = '1';
	result[1] = '\0';
	while (quotient)
	{
		ft_strcat(result, "000");
		quotient--;
	}
	result2 = find_word(dict, result);
	ft_strcat(output, " ");
	ft_strcat(output, result2);
	free(result);
	return ;
}

void	reset_null(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

char	*make_output(int len, char *num, t_dict *dict)
{

	char	temp[4];
	int	i;
	char	*output;
	int	flag;

	flag = 0;
	reset_null(temp, 4);
	output = (char *)malloc(sizeof(char) * 1024);
	reset_null(output, 1024);
	i = 0;
	while (i < len)
	{
		if (len - i > 2 && (len - i) % 3 == 0 && num[i] != '0')
		{
			temp[0] = num[i];
			ft_strcat(output, " ");
			ft_strcat(output, find_word(dict, temp));
			ft_strcat(output, " ");
			ft_strcat(output, find_word(dict, "100"));
			flag = 1;
		}
		else if ((len - i) % 3 == 2 && num[i] == '1')
		{
			temp[0] = num[i];
			temp[1] = num[i + 1];
			ft_strcat(output, " ");
			ft_strcat(output, find_word(dict, temp));
			i++;
			flag = 1;
			if (num[i + 1] != 0)
				get_pos((len - i) / 3, dict, output);
		}
		else if ((len - i) % 3 == 2 && num[i] != '0')
		{
			temp[0] = num[i];
			temp[1] = '0';
			ft_strcat(output, " ");
			ft_strcat(output, find_word(dict, temp));
			flag = 1;
		}
		else if (num[i] != '0')
		{
			temp[0] = num[i];
			ft_strcat(output, " ");
			ft_strcat(output, find_word(dict, temp));
			flag = 0;
			if (num[i + 1] != 0)
				get_pos((len - i) / 3, dict, output);
		}
		else if (num[i] == '0' && (len - i) % 3 == 1)
		{
			if (flag)
				get_pos((len - i) / 3, dict, output);
			flag = 0;
		}
		reset_null(temp, 4);
		i++;
	}
	return (output);
}

void convert_to_words(char *num, t_dict *dict)
{
	char	*output;
	int		len;
	int		len_out;
	int		i;

	i = 0;
	len = ft_strlen(num);
	len_out = 1024;
	if (len == 1 && *num == '0')
	{
		output = find_word(dict, num);
		write(1, output, ft_strlen(output));
		write(1, "\n", 1);
		return ;
	}
	output = make_output(len, num, dict);
	if (output[len_out - 1] == ' ')
		output[len_out - 1] = '\0';
	write(1, output + 1, ft_strlen(output + 1));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	int		i;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	dict = parse_dict("numbers.dict");
	if (dict[0].num == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	convert_to_words(argv[1], dict);

	free(dict);
	return (0);
}
