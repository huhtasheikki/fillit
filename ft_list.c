/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:25:22 by epalomak          #+#    #+#             */
/*   Updated: 2019/12/13 10:26:48 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_index(char *str, int x)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (str[i] && x > 0)
	{
		if (str[i] == '#')
			x--;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			a = i;
			return (a);
		}
		i++;
	}
	return (0);
}

void	ft_move_list(t_list2 *new)
{
	while (new->t1 > 3)
	{
		new->t1 -= 4;
		new->t2 -= 4;
		new->t3 -= 4;
		new->t4 -= 4;
	}
	while (new->t1 != 0 && new->t2 != 4 && new->t3 != 4 && new->t3 != 8 &&
		new->t4 != 4 && new->t4 != 8 && new->t4 != 12)
	{
		new->t1 -= 1;
		new->t2 -= 1;
		new->t3 -= 1;
		new->t4 -= 1;
	}
}

void	ft_list(t_list2 **head, char *str, int count)
{
	t_list2	*new;
	t_list2	*last;

	last = *head;
	new = (t_list2*)malloc(sizeof(t_list2));
	new->a = 'A' + count;
	new->t1 = ft_index(str, 0);
	new->t2 = ft_index(str, 1);
	new->t3 = ft_index(str, 2);
	new->t4 = ft_index(str, 3);
	new->next = NULL;
	ft_move_list(new);
	if (*head == 0)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
