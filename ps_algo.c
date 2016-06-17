/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:50:30 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 15:38:01 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_dumb_sort(t_ps *list, int *i)
{
	int		min;

	while (ps_is_sorted_a(list->list_a) == 0 && list->list_a)
	{
		if ((min = ps_is_minimum(list, list->list_a->nbr)) == list->list_a->nbr)
			ps_push_pb(list, i);
		else if (list->list_a->nbr > list->list_a->next->nbr &&
				list->list_a->next->nbr == min)
			ps_push_sa(list, i);
		else
		{
			if (ps_good_way(list, min) == 1)
			{
				while (list->list_a->nbr != min)
					ps_push_rra(list, i);
			}
			else
			{
				while (list->list_a->nbr != min)
					ps_push_ra(list, i);
			}
		}
	}
}

int			ps_is_mimi(t_ps *list, int mimi)
{
	t_pslist		*ptr;

	ptr = list->list_a;
	while (ptr)
	{
		if (ptr->nbr < mimi)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void		ps_special_3(t_ps *list, int *i)
{
	if (list->list_a->nbr > list->list_a->next->next->nbr)
	{
		ps_push_ra(list, i);
		if (list->list_a->nbr > list->list_a->next->next->nbr)
			ps_push_ra(list, i);
		else if (list->list_a->nbr > list->list_a->next->nbr)
			ps_push_sa(list, i);
	}
	else if (list->list_a->nbr > list->list_a->next->nbr)
		ps_push_sa(list, i);
	else if (list->list_a->nbr < list->list_a->next->nbr &&
			list->list_a->next->nbr > list->list_a->next->next->nbr)
	{
		ps_push_pb(list, i);
		ps_push_sa(list, i);
		ps_push_pa(list, i);
	}
}

void		ps_get_mini(t_ps *list, int *i)
{
	int		j;
	int		k;

	k = 2;
	while (k)
	{
		j = ps_list_len(list->list_a);
		while (j)
		{
			if (list->list_b && list->list_b->next)
				break ;
			if (ps_is_mimi(list, list->list_a->nbr) == 1)
			{
				ps_push_pb(list, i);
				break ;
			}
			else if (ps_is_mimi(list, list->list_a->next->nbr) == 1)
				ps_push_ra(list, i);
			else
				ps_push_rra(list, i);
			j--;
		}
		k--;
	}
}

void		ps_special_5(t_ps *list, int *i)
{
	ps_get_mini(list, i);
	ps_special_3(list, i);
	ps_push_pa(list, i);
	ps_push_pa(list, i);
}
