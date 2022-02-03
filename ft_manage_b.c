/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:39:31 by nflan             #+#    #+#             */
/*   Updated: 2022/02/03 15:11:27 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_b_sort(t_begin *begin)
{
	t_pile	*tmp;

	tmp = begin->pile_b;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_min_in_max(t_pile *pile, t_chunk *chunk, int ind)
{
	t_chunk	*ctmp;

	ctmp = chunk;
	if (ctmp)
	{
//		ft_printf("ctmp->index == %d && ind == %d\n", ctmp->index, ind);
		while (ctmp->index != ind)
			ctmp = ctmp->next;
		if (pile->num == ctmp->min)
			return (-1);
		else if (pile->num == ctmp->max)
			return (1);
		else if (pile->num > ctmp->min && pile->num < ctmp->max)
			return (2);
	}
	return (0);
}

int	ft_min_max_chunk(t_chunk *chunk, int ind, int ext)
{
	t_chunk	*ctmp;

	ctmp = chunk;
	if (ctmp)
	{
		while (ctmp->index != ind)
			ctmp = ctmp->next;
		if (ext == -1)
			return (ctmp->min);
		else if (ext == 1)
			return (ctmp->max);
	}
	return (0);
}

int	ft_nb_rb(t_begin *begin, int nbr)
{
	t_pile	*tmp;
	int		top;
	int		rb;

	tmp = begin->pile_b;
	rb = 0;
	if (!tmp || !begin->pile_a)
		return (0);
	if (nbr > ft_pile_max(begin, 2) || nbr < ft_pile_min(begin, 2))
		top = ft_pile_max(begin, 2);
	else
	{
		top = ft_pile_min(begin, 2);
		while (tmp)
		{
			if (nbr > top && top < tmp->num && nbr > tmp->num)
				top = tmp->num;
			tmp = tmp->next;
		}
	}
	tmp = begin->pile_b;
	while (tmp && tmp->num != top)
	{
		rb++;
		tmp = tmp->next;
	}
	return (rb);
}
