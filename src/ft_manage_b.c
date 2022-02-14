/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:39:31 by nflan             #+#    #+#             */
/*   Updated: 2022/02/10 16:10:21 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_b_sort(t_begin *btmp)
{
	t_pile	*tmp;

	tmp = btmp->pile_b;
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

int	ft_find_top(t_begin *btmp, int nbr)
{
	t_pile	*tmp;
	int		top;

	tmp = btmp->pile_b;
	top = 0;
	if (tmp)
	{
		if (nbr > ft_pile_max(btmp, 2) || nbr < ft_pile_min(btmp, 2))
			top = ft_pile_max(btmp, 2);
		else
		{
			top = ft_pile_min(btmp, 2);
			while (tmp)
			{
				if (nbr > top && top < tmp->num && nbr > tmp->num)
					top = tmp->num;
				tmp = tmp->next;
			}
		}
	}
	return (top);
}

int	ft_nb_rb_rrb(t_begin *btmp, int nbr, t_roll *roll)
{
	t_pile	*tmp;
	int		top;
	int		rb;
	int		rrb;

	tmp = btmp->pile_b;
	rb = 0;
	rrb = -1;
	top = ft_find_top(btmp, nbr);
	if (!tmp || !btmp->pile_a)
		return (0);
	while (tmp && tmp->num != top)
	{
		rb++;
		tmp = tmp->next;
	}
	while (tmp && tmp->next)
	{
		rrb--;
		tmp = tmp->next;
	}
	ft_fill_roll_b(roll, rb, rrb);
	if (rb <= (rrb * -1))
		return (rb);
	return (rrb);
}

int	ft_nb_rb_rrb_bis(t_begin *btmp, int nbr)
{
	t_pile	*tmp;
	int		top;
	int		rb;
	int		rrb;

	tmp = btmp->pile_b;
	rb = 0;
	rrb = -1;
	top = ft_find_top(btmp, nbr);
	if (!tmp || !btmp->pile_a)
		return (0);
	while (tmp && tmp->num != top)
	{
		rb++;
		tmp = tmp->next;
	}
	while (tmp && tmp->next)
	{
		rrb--;
		tmp = tmp->next;
	}
	if (rb <= (rrb * -1))
		return (rb);
	return (rrb);
}
