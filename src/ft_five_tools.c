/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:43:24 by nflan             #+#    #+#             */
/*   Updated: 2022/02/09 17:48:58 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_pile_min(t_begin *begin, int pile)
{
	t_pile	*tmp;
	int		min;

	tmp = NULL;
	if (pile == 1 && begin->pile_a)
		tmp = begin->pile_a;
	else if (pile == 2 && begin->pile_b)
		tmp = begin->pile_b;
	min = tmp->num;
	if (tmp)
	{
		while (tmp)
		{
			if (min > tmp->num)
				min = tmp->num;
			tmp = tmp->next;
		}
	}
	return (min);
}

int	ft_pile_max(t_begin *begin, int pile)
{
	t_pile	*tmp;
	int		max;

	tmp = NULL;
	if (pile == 1 && begin->pile_a)
		tmp = begin->pile_a;
	else if (pile == 2 && begin->pile_b)
		tmp = begin->pile_b;
	max = tmp->num;
	if (tmp)
	{
		while (tmp)
		{
			if (max < tmp->num)
				max = tmp->num;
			tmp = tmp->next;
		}
	}
	return (max);
}
