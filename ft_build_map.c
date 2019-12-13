/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:22:06 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/12/12 10:44:09 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_sqr_root(int size)
{
	int		i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

char		**ft_build_empty_map(int xy)
{
	int		i;
	int		rt;
	char	**square;

	rt = 1;
	while (rt)
	{
		i = 0;
		square = (char**)malloc(sizeof(char *) * (xy + 1));
		while (i < xy)
		{
			square[i] = (char *)malloc(sizeof(char) * (xy + 1));
			ft_memset(square[i], '.', xy);
			square[i][xy] = '\0';
			i++;
			if (i == xy)
			{
				square[i] = NULL;
			}
		}
		rt = 0;
	}
	return (square);
}
