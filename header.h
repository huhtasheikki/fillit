/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:43:47 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/12/16 10:14:57 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define BUFF_SIZE 20
# define MAX_FD 4864

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef	struct		s_list2
{
	char			a;
	int				t1;
	int				t2;
	int				t3;
	int				t4;
	struct s_list2	*next;
}					t_list2;

int					ft_sqr_root(int size);
int					ft_index(char *str, int x);
int					ft_fill_tetri(int *xy, int t, char a, char **square);
int					ft_fill_main(int *xy, t_list2 *head, char **square);
int					ft_backtrack(t_list2 *head, char **square);
int					ft_check_tetri(char *str);
int					ft_form_tetrostr(int fd, char *ptr, char **str);
int					ft_check_n_form(int fd, t_list2 **head);
int					get_next_line(const int fd, char **line);
int					ft_free_line(char *line);

void				ft_print_square(char **square);
void				ft_move_list(t_list2 *new);
void				ft_list(t_list2 **head, char *str, int count);
void				ft_delete_tetri(int *xy, int t, char c, char **square);
void				ft_delete_ts(int *xy, t_list2 *head, char **square);
void				ft_del_square(char **square);

char				**ft_build_empty_map(int xy);
#endif
