/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:27:56 by nflan             #+#    #+#             */
/*   Updated: 2022/02/15 21:00:48 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pile_incr(t_pile *pile)
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

int	ft_rr_rrr2(t_roll *roll, int rolling, int nbrr)
{
	int	rrolling;
	int	nbrrr;

	if (roll->rra >= roll->rrb)
	{
		rrolling = roll->rra;
		nbrrr = roll->rrb - roll->rra;
	}
	else
	{
		rrolling = roll->rrb;
		nbrrr = roll->rra - roll->rrb;
	}
	if (rolling + nbrr <= ((rrolling + nbrrr) * -1))
		return (rolling);
	else if (rolling + nbrr > ((rrolling - nbrrr) * -1))
		return (rrolling);
	else
		return (0);
}

int	ft_rr_rrr(t_roll *roll)
{
	int	rolling;
	int	nbrr;

	if (roll->ra <= roll->rb)
	{
		rolling = roll->ra;
		nbrr = roll->rb - roll->ra;
	}
	else
	{
		rolling = roll->rb;
		nbrr = roll->ra - roll->rb;
	}
	return (ft_rr_rrr2(roll, rolling, nbrr));
}

t_begin	*ft_begin_cpy(t_begin *begin, int bmoves)
{
	t_begin	*new;

	new = ft_calloc(sizeof(t_begin), 1);
	new->pile_a = ft_fill_cpy(begin->pile_a);
	new->pile_b = NULL;
	new->moves = 0;
	new->bmoves = bmoves;
	new->print = 0;
	return (new);
}

t_begin	*ft_create_begin(t_begin *begin)
{
	begin = ft_calloc(sizeof(t_begin), 1);
	begin->pile_b = NULL;
	begin->moves = 0;
	begin->bmoves = 0;
	begin->print = 1;
	return (begin);
}
