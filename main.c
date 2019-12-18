/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:38:08 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/12/16 10:19:55 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_del_square(char **square)
{
	int	i;

	i = 0;
	while (square[i] != '\0')
	{
		free(square[i]);
		i++;
	}
	free(square);
}

void	ft_print_square(char **square)
{
	int		i1;

	i1 = 0;
	while (square[i1])
	{
		ft_putendl(square[i1]);
		i1++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_list2	*head;
	char	**square;

	head = NULL;
	if (argc != 2)
		ft_putendl("usage: fillit source_file");
	if (argc != 2 || !(fd = open(argv[1], O_RDONLY)))
		return (0);
	if ((i = ft_check_n_form(fd, &head)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	square = ft_build_empty_map(i);
	while (!ft_backtrack(head, square))
	{
		ft_del_square(square);
		square = ft_build_empty_map(++i);
	}
	ft_print_square(square);
	close(fd);
	return (0);
}
