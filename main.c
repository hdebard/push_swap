/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 17:38:02 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/01 20:05:18 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_ps	*list;

	if (argc > 1)
	{
		if ((list = ps_make_list(argv + 1)) == NULL)
		{
			ft_putendl("Error");
			return (0);
		}
		if (list->list_a == NULL)
		{
			ft_putendl("");
			return (0);
		}
		return (ps_sort_list(list));
	}
	else
		ft_putendl("");
	return (0);
}
