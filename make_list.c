/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:41:43 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 16:53:12 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps		*ps_make_list(char **args)
{
	t_ps		*n_list;
	int			u;

	if ((n_list = (t_ps*)malloc(sizeof(t_ps))) == NULL)
		return (NULL);
	u = 0;
	u = ps_add_flags(n_list, args);
	while (args[u])
	{
		if (ps_is_number(args[u]) == 0 || ps_is_long(args[u]) == 1 ||
			ps_is_dupl(ft_atoi(args[u]), n_list->list_a) == 1)
		{
			ft_putendl("Exit");
			exit(0);
		}
		if (n_list->list_a == NULL)
		{
			if (ps_create_first_list(n_list, ft_atoi(args[u])) == NULL)
				return (NULL);
		}
		else if (ps_create_tail(n_list, ft_atoi(args[u])) == NULL)
			return (NULL);
		u++;
	}
	return (n_list);
}

t_ps		*ps_create_first_list(t_ps *list, int n)
{
	if ((list->list_a = (t_pslist*)malloc(sizeof(t_pslist))) == NULL)
		return (NULL);
	list->list_a->nbr = n;
	list->list_a->next = NULL;
	return (list);
}

t_ps		*ps_create_tail(t_ps *list, int n)
{
	t_pslist		*ptr;

	ptr = list->list_a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	if ((ptr->next = (t_pslist*)malloc(sizeof(t_pslist))) == NULL)
		return (NULL);
	ptr = ptr->next;
	ptr->nbr = n;
	ptr->next = NULL;
	return (list);
}
