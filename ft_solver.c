/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 09:52:38 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/12/09 15:25:26 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_fill_tetri(int *xy, int t, char a, char **square)
{
	int		y2;
	int		limit;

	y2 = 0;
	while (t > 3)
	{
		t -= 4;
		y2++;
	}
	limit = ft_strlen(square[xy[1]]);
	if ((limit > xy[0] + t) && (limit > xy[1] + y2) &&
		square[xy[1] + y2][xy[0] + t] == '.')
	{
		square[xy[1] + y2][xy[0] + t] = a;
		return (1);
	}
	return (0);
}

void	ft_delete_tetri(int *xy, int t, char c, char **square)
{
	int		y2;

	y2 = 0;
	while (t > 3)
	{
		t -= 4;
		y2++;
	}
	if (square[xy[1] + y2][xy[0] + t] == c)
		square[xy[1] + y2][xy[0] + t] = '.';
}

int		ft_fill_main(int *xy, t_list2 *head, char **square)
{
	if (!ft_fill_tetri(xy, head->t1, head->a, square))
	{
		return (0);
	}
	if (!ft_fill_tetri(xy, head->t2, head->a, square))
	{
		ft_delete_tetri(xy, head->t1, head->a, square);
		return (0);
	}
	if (!ft_fill_tetri(xy, head->t3, head->a, square))
	{
		ft_delete_tetri(xy, head->t1, head->a, square);
		ft_delete_tetri(xy, head->t2, head->a, square);
		return (0);
	}
	if (!ft_fill_tetri(xy, head->t4, head->a, square))
	{
		ft_delete_tetri(xy, head->t1, head->a, square);
		ft_delete_tetri(xy, head->t2, head->a, square);
		ft_delete_tetri(xy, head->t3, head->a, square);
		return (0);
	}
	return (1);
}

void	ft_delete_ts(int *xy, t_list2 *head, char **square)
{
	ft_delete_tetri(xy, head->t1, head->a, square);
	ft_delete_tetri(xy, head->t2, head->a, square);
	ft_delete_tetri(xy, head->t3, head->a, square);
	ft_delete_tetri(xy, head->t4, head->a, square);
}

int		ft_backtrack(t_list2 *head, char **square)
{
	int		xy[2];
	int		len;

	len = ft_strlen(square[0]);
	xy[0] = 0;
	xy[1] = 0;
	if (!head)
		return (1);
	while (xy[1] < len)
	{
		while (xy[0] < len)
		{
			if (ft_fill_main(xy, head, square))
			{
				if (ft_backtrack(head->next, square))
					return (1);
				ft_delete_ts(xy, head, square);
			}
			xy[0]++;
		}
		xy[0] = 0;
		xy[1]++;
	}
	return (0);
}
