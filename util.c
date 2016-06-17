/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:08:12 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 15:34:26 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_is_sorted_a(t_pslist *list)
{
	t_pslist		*ptr;

	ptr = list;
	if (!ptr)
		return (1);
	while (ptr)
	{
		if (ptr->next && ptr->nbr > ptr->next->nbr)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		ps_is_sorted_b(t_pslist *list)
{
	t_pslist		*ptr;

	ptr = list;
	if (!ptr)
		return (1);
	while (ptr)
	{
		if (ptr->next && ptr->nbr < ptr->next->nbr)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	ps_printf_list(t_pslist *list)
{
	while (list)
	{
		ft_putnbr(list->nbr);
		if (list->next)
			ft_putchar(' ');
		list = list->next;
	}
	ft_putendl("");
}

int		ps_list_len(t_pslist *list)
{
	int		len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

int		ps_good_way(t_ps *list, int min)
{
	int			nb;
	int			tok;
	t_pslist	*ptr;

	nb = 0;
	tok = 0;
	ptr = list->list_a;
	while (ptr->next)
	{
		if (ptr->nbr == min)
			tok = 1;
		if (tok == 0)
			nb++;
		else
			nb--;
		ptr = ptr->next;
	}
	if (nb <= 0)
		return (0);
	return (1);
}
