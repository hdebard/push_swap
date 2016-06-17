/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:06:26 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 15:35:45 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct		s_pslist
{
	int					nbr;
	struct s_pslist		*next;
	struct s_pslist		*prev;
}					t_pslist;

typedef struct		s_ps
{
	t_pslist			*list_a;
	t_pslist			*list_b;
	int					v;
	int					c;
	int					d;
	int					o;
	int					h;
}					t_ps;

int					ps_last_heuristic(t_ps *list, int *i);
int					ps_first_heuristic(t_ps *list, int *i);
int					ps_heuristic(t_ps *list, int *i);
int					ps_sort_list(t_ps *list);
t_ps				*ps_make_list(char **args);
t_ps				*ps_create_first_list(t_ps *list, int n);
t_ps				*ps_create_tail(t_ps *list, int n);
int					ps_is_sorted_a(t_pslist *list);
int					ps_is_sorted_b(t_pslist *list);
void				ps_printf_list(t_pslist *list);
int					ps_list_len(t_pslist *list);
int					ps_good_way(t_ps *list, int min);
int					ps_is_number(char *str);
int					ps_is_dupl(int i, t_pslist *list);
int					ps_is_long(char *str);
int					ps_is_minimum(t_ps *list, int mini);
int					ps_is_maximum(t_ps *list, int mini);
void				ps_push_ra(t_ps *list, int *i);
void				ps_push_pb(t_ps *list, int *i);
void				ps_push_pa(t_ps *list, int *i);
void				ps_push_rb(t_ps *list, int *i);
void				ps_push_rra(t_ps *list, int *i);
void				ps_push_rrb(t_ps *list, int *i);
void				ps_push_sa(t_ps *list, int *i);
void				ps_push_sb(t_ps *list, int *i);
void				ps_print_action(t_ps *list, int a, int *i);
void				ps_setcolor(int i);
void				ps_dumb_sort(t_ps *list, int *i);
int					ps_is_mimi(t_ps *list, int mimi);
void				ps_special_3(t_ps *list, int *i);
void				ps_get_mini(t_ps *list, int *i);
void				ps_special_5(t_ps *list, int *i);
int					ps_add_flags(t_ps *list, char **args);
void				ps_get_flags(t_ps *list, char **args, int *ret, int *i);
void				ps_special_flags(t_ps *list, int *i);
void				ps_exit(t_ps *list, int *i);

#endif
