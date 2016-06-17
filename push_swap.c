/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:25:25 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 15:58:29 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_last_heuristic(t_ps *list, int *i)
{
	t_pslist	*ptr;
	t_pslist	*last;
	int			u;

	u = 0;
	ptr = list->list_a;
	while (ptr && ptr->next && ptr->next->next)
	{
		if (ptr->nbr > ptr->next->nbr)
			return (0);
		ptr = ptr->next;
		u++;
	}
	last = ptr;
	ptr = ptr->next;
	if (u >= 2 && last->nbr > ptr->nbr)
	{
		ps_push_rra(list, i);
		ps_push_rra(list, i);
		ps_push_sa(list, i);
		ps_push_ra(list, i);
		ps_push_ra(list, i);
		return (1);
	}
	return (0);
}

int		ps_first_heuristic(t_ps *list, int *i)
{
	t_pslist	*ptr;

	ptr = list->list_a;
	if (ptr->nbr > ptr->next->nbr)
	{
		ptr = ptr->next;
		while (ptr->next)
		{
			if (ptr->nbr > ptr->next->nbr)
				return (0);
			ptr = ptr->next;
		}
		ps_push_sa(list, i);
		return (1);
	}
	return (0);
}

int		ps_heuristic(t_ps *list, int *i)
{
	if (ps_last_heuristic(list, i) == 1)
		return (1);
	if (ps_first_heuristic(list, i) == 1)
		return (1);
	return (0);
}

int		ps_sort_list(t_ps *list)
{
	int		i;
	int		len;

	i = 0;
	if (ps_is_sorted_a(list->list_a) == 1)
	{
	}
	else if (ps_heuristic(list, &i) == 1)
	{
	}
	else if ((len = ps_list_len(list->list_a)) == 3)
		ps_special_3(list, &i);
	else if (len == 2 && list->list_a->nbr > list->list_a->next->nbr)
		ps_push_sa(list, &i);
	else if (len == 5)
		ps_special_5(list, &i);
	else
	{
		ps_dumb_sort(list, &i);
		while (list->list_b)
			ps_push_pa(list, &i);
	}
	ps_exit(list, &i);
	return (0);
}
