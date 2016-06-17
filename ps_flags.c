/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:32:53 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 16:50:01 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ps_add_flags(t_ps *list, char **args)
{
	int		ret;
	int		i;

	ret = 0;
	list->list_a = NULL;
	list->list_b = NULL;
	list->v = 0;
	list->c = 0;
	list->d = 0;
	list->o = 0;
	list->h = 0;
	while (args[ret])
	{
		i = 0;
		if (args[ret][i] == '-' && ps_is_number(args[ret]) == 0)
		{
			ps_get_flags(list, args, &ret, &i);
			ret++;
		}
		else
			break ;
	}
	return (ret);
}

void			ps_get_flags(t_ps *list, char **args, int *ret, int *i)
{
	while (args[*ret][*i + 1])
	{
		if (args[*ret][*i + 1] == 'v')
			list->v = 1;
		else if (args[*ret][*i + 1] == 'c')
			list->c = 1;
		else if (args[*ret][*i + 1] == 'd')
			list->d = 1;
		else if (args[*ret][*i + 1] == 'o')
			list->o = 1;
		else if (args[*ret][*i + 1] == 'h')
		{
			ft_putendl("usage: ./push_swap [-vcdoh] [...]");
			exit(0);
		}
		else
		{
			ft_putstr("./push_swap: illegal option -- ");
			ft_putchar(args[*ret][*i + 1]);
			ft_putendl("");
			ft_putendl("usage: ./push_swap [-vcdoh] [...]");
			exit(0);
		}
		*i += 1;
	}
}

void			ps_special_flags(t_ps *list, int *i)
{
	if (list->c == 1 && list->o == 0)
		ps_setcolor(-1);
	if (list->o == 0 && list->v == 1)
	{
		ft_putendl(":");
	}
	else if (list->o == 1 && list->v == 1 && list->c == 0)
	{
		ft_putnbr(*i);
		ft_putendl(":");
	}
	if (list->c == 1 && list->o == 1 & list->v == 1)
	{
	}
	else if (list->v == 1)
	{
		ft_putstr("Pile A: ");
		ps_printf_list(list->list_a);
		ft_putstr("Pile b: ");
		ps_printf_list(list->list_b);
	}
}

void			ps_exit(t_ps *list, int *i)
{
	t_pslist		*ptr;

	if (list->o == 0)
		ft_putendl("");
	if (list->d == 1)
	{
		ft_putstr("Iterations: ");
		ft_putnbr(*i);
		ft_putendl(".");
	}
	if (list->v == 1 && ps_is_sorted_a(list->list_a) == 1)
	{
		ft_putstr("Sorted list: ");
		ps_printf_list(list->list_a);
	}
	while (list->list_a)
	{
		ptr = list->list_a;
		list->list_a = list->list_a->next;
		free(ptr);
	}
	free(list);
}
