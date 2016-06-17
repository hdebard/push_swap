/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:02:03 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 15:35:39 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_push_rrb(t_ps *list, int *i)
{
	t_pslist	*ptr;

	if (list->list_b && list->list_b->next)
	{
		ptr = list->list_b;
		while (ptr->next->next != NULL)
			ptr = ptr->next;
		ptr->next->next = list->list_b;
		list->list_b = ptr->next;
		ptr->next = NULL;
		ps_print_action(list, 7, i);
		*i += 1;
	}
}

void			ps_push_sa(t_ps *list, int *i)
{
	int		swap;

	if (list->list_a && list->list_a->next)
	{
		swap = list->list_a->nbr;
		list->list_a->nbr = list->list_a->next->nbr;
		list->list_a->next->nbr = swap;
		ps_print_action(list, 1, i);
		*i += 1;
	}
}

void			ps_push_sb(t_ps *list, int *i)
{
	int		swap;

	if (list->list_b && list->list_b->next)
	{
		swap = list->list_b->nbr;
		list->list_b->nbr = list->list_b->next->nbr;
		list->list_b->next->nbr = swap;
		ps_print_action(list, 0, i);
		*i += 1;
	}
}

void			ps_print_action(t_ps *list, int a, int *i)
{
	if (list->o == 0)
	{
		if (list->c == 1)
			ps_setcolor(a);
		if (*i != 0 && list->v == 0)
			ft_putchar(' ');
		if (a == 0)
			ft_putstr("sb");
		else if (a == 1)
			ft_putstr("sa");
		else if (a == 2)
			ft_putstr("pa");
		else if (a == 3)
			ft_putstr("pb");
		else if (a == 4)
			ft_putstr("ra");
		else if (a == 5)
			ft_putstr("rra");
		else if (a == 6)
			ft_putstr("rb");
		else if (a == 7)
			ft_putstr("rrb");
	}
	ps_special_flags(list, i);
}

void			ps_setcolor(int i)
{
	if (i == -1)
		ft_putstr("\033[37m");
	else if (i == 0)
		ft_putstr("\033[36m");
	else if (i == 1)
		ft_putstr("\033[35m");
	else if (i == 2)
		ft_putstr("\033[34m");
	else if (i == 3)
		ft_putstr("\033[33m");
	else if (i == 4)
		ft_putstr("\033[32m");
	else if (i == 5)
		ft_putstr("\033[31m");
	else if (i == 6)
		ft_putstr("\033[30m");
	else if (i == 7)
		ft_putstr("\033[29m");
}
