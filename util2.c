/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdebard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 18:10:15 by hdebard           #+#    #+#             */
/*   Updated: 2016/04/02 15:34:50 by hdebard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_is_number(char *str)
{
	if (*str == 43 || *str == 45)
		str++;
	while (*str && *str <= 57 && *str >= 48)
		str++;
	if (*str)
		return (0);
	return (1);
}

int			ps_is_dupl(int i, t_pslist *list)
{
	while (list)
	{
		if (i == list->nbr)
			return (1);
		list = list->next;
	}
	return (0);
}

int			ps_is_long(char *str)
{
	long	sign;
	long	nbr;

	nbr = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (long)(*str - '0');
		str++;
	}
	nbr = sign * nbr;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
	return (0);
}

int			ps_is_minimum(t_ps *list, int mini)
{
	t_pslist *ptr;

	ptr = list->list_a;
	while (ptr)
	{
		if (ptr->nbr < mini)
			mini = ptr->nbr;
		ptr = ptr->next;
	}
	return (mini);
}

int			ps_is_maximum(t_ps *list, int max)
{
	t_pslist *ptr;

	ptr = list->list_a;
	while (ptr)
	{
		if (ptr->nbr > max)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
