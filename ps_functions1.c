/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_functions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:59:36 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 14:25:09 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_push_ra(t_ps *list, int *i)
{
	t_pslist	*ptr;

	if (list->list_a && list->list_a->next)
	{
		ptr = list->list_a;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list->list_a;
		list->list_a = list->list_a->next;
		ptr->next->next = NULL;
		ps_print_action(list, 4, i);
		*i += 1;
	}
}

void			ps_push_pb(t_ps *list, int *i)
{
	t_pslist	*ptr;

	if (list->list_a)
	{
		ptr = list->list_a;
		list->list_a = list->list_a->next;
		ptr->next = list->list_b;
		list->list_b = ptr;
		ps_print_action(list, 3, i);
		*i += 1;
	}
}

void			ps_push_pa(t_ps *list, int *i)
{
	t_pslist	*ptr;

	if (list->list_b)
	{
		ptr = list->list_b;
		list->list_b = list->list_b->next;
		ptr->next = list->list_a;
		list->list_a = ptr;
		ps_print_action(list, 2, i);
		*i += 1;
	}
}

void			ps_push_rb(t_ps *list, int *i)
{
	t_pslist	*ptr;

	if (list->list_b && list->list_b->next)
	{
		ptr = list->list_b;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = list->list_b;
		list->list_b = list->list_b->next;
		ptr->next->next = NULL;
		ps_print_action(list, 6, i);
		*i += 1;
	}
}

void			ps_push_rra(t_ps *list, int *i)
{
	t_pslist		*ptr;

	if (list->list_a && list->list_a->next)
	{
		ptr = list->list_a;
		while (ptr->next->next != NULL)
			ptr = ptr->next;
		ptr->next->next = list->list_a;
		list->list_a = ptr->next;
		ptr->next = NULL;
		ps_print_action(list, 5, i);
		*i += 1;
	}
}
