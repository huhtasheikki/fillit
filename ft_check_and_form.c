/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_form.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:53:13 by epalomak          #+#    #+#             */
/*   Updated: 2019/12/18 17:30:46 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_count_block(char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#')
			return (-1);
		if (str[i] == '#')
			c++;
		i++;
	}
	if (c != 4 || i != 16)
		return (-1);
	return (0);
}

int		ft_check_tetri(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (ft_count_block(str) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#' && (i != 3 && i != 7 && i != 11)
				&& i + 1 < 16)
			count++;
		if (str[i] == '#' && str[i - 1] == '#' && (i != 4 && i != 8 && i != 12)
				&& i - 1 >= 0)
			count++;
		if (str[i] == '#' && str[i + 4] == '#' && i < 12 && i + 4 < 16)
			count++;
		if (str[i] == '#' && str[i - 4] == '#' && i - 4 >= 0)
			count++;
		i++;
	}
	if (count != 6 && count != 8)
		return (-1);
	return (1);
}

int		ft_form_tetrostr(int fd, char *ptr, char **str)
{
	int		i;
	char	*str2;

	i = -1;
	while (++i <= 4 && get_next_line(fd, &str2) > 0)
	{
		if ((i < 4 && ft_strlen(str2) != 4) || (i == 4 && ft_strlen(str2) != 0))
		{
			free(str2);
			return (-1);
		}
		else if (i == 4)
		{
			free(str2);
			return (1);
		}
		ptr = *str;
		*str = ft_strjoin(*str, str2);
		free(ptr);
		free(str2);
	}
	if (i == 3 || ft_strlen(str2) != 0)
		return (ft_free_line(str2));
	free(str2);
	return (0);
}

int		ft_free_line(char *line)
{
	free(line);
	return (-1);
}

int		ft_check_n_form(int fd, t_list2 **head)
{
	int		rt;
	char	*ptr;
	char	*line;
	int		count;

	rt = 1;
	ptr = NULL;
	count = 0;
	while (rt > 0)
	{
		line = ft_strnew(0);
		if ((rt = ft_form_tetrostr(fd, ptr, &line)) == -1)
			return (ft_free_line(line));
		if (rt == 0 && line[0] == '\0')
			return (-1);
		if (ft_check_tetri(line) == -1 || count > 25)
			return (ft_free_line(line));
		ft_list(head, line, count++);
		free(line);
	}
	return (ft_sqr_root(count));
}
