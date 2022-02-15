/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:27:56 by nflan             #+#    #+#             */
/*   Updated: 2022/02/15 12:43:41 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pile_is_incr(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->num < tmp->next->num)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	return (1);
}

int		ft_rr_rrr(t_roll *roll)
{
	int	rolling;
	int oui;
	int rrolling;
	int	non;

	if (roll->ra <= roll->rb)
	{
		rolling = roll->ra;
		oui = roll->rb - roll->ra;
	}
	else
	{
		rolling = roll->rb;
		oui = roll->ra - roll->rb;
	}
	if (roll->rra >= roll->rrb)
	{
		rrolling = roll->rra;
		non = roll->rrb - roll->rra;
	}
	else
	{
		rrolling = roll->rrb;
		non = roll->rra - roll->rrb;
	}
	if (rolling + oui <= ((rrolling + non) * -1))// || ((roll->ra + roll->rb) < ((roll->rra + roll->rrb) * - 1)))
		return (rolling);
	else if	(rolling + oui > ((rrolling - non) * -1))// || ((roll->ra + roll->rb) > ((roll->rra + roll->rrb) * - 1)))
		return (rrolling);
	else
		return (0);
}

t_pile	*ft_fill_cpy(t_pile *pile)
{
	t_pile	*begin;
	t_pile	*ptr;
	t_pile	*new;

	begin = pile;
	ptr = NULL;
	new = NULL;
	while (begin)
	{
		ptr = ft_pilenew(begin->num);
		ft_lstadd_back(&new, ptr);
		begin = begin->next;
	}
	return (new);
}

t_begin	*ft_begin_cpy(t_begin *begin, int bmoves)
{
	t_begin	*new;

	new = ft_calloc(sizeof(t_begin), 1);
	new->pile_a = ft_fill_cpy(begin->pile_a);
	new->pile_b = ft_calloc(sizeof(t_pile), 1);
	new->moves = 0;
	new->bmoves = bmoves;
	new->print = 0;
	return (new);
}

t_begin *ft_create_begin(t_begin *begin, int need_b)
{
	begin = ft_calloc(sizeof(t_begin), 1);
	if (need_b > 3)
		begin->pile_b = ft_calloc(sizeof(t_pile), 1);
	begin->moves = 0;
	begin->bmoves = 0;
	begin->print = 1;
	return (begin);
}
