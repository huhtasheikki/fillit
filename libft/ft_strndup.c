/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:56:56 by epalomak          #+#    #+#             */
/*   Updated: 2019/11/06 14:19:38 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*des;

	len = 0;
	while (s1[len] != '\0' && n > len)
		len++;
	if (!(des = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && n > i)
	{
		des[i] = s1[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
