/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:06 by nflan             #+#    #+#             */
/*   Updated: 2022/02/03 15:22:16 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_begin *begin)
{
	t_pile	*tmp;
	int		b;

	b = 0;
	tmp = begin->pile_a;
	if (tmp)
	{
		while (tmp->next && tmp->num < tmp->next->num)
			tmp = tmp->next;
		if (!tmp->next)
			b = 2;
	}
	else
		b = 2;
	tmp = begin->pile_b;
	if (tmp)
	{
		while (tmp->next && tmp->num > tmp->next->num)
			tmp = tmp->next;
		if (!tmp->next)
			b++;
	}
	else
		b++;
	return (b);
}

void	ft_push_all_to_a(t_begin *begin)
{
	while (begin->pile_b)
		begin->moves += ft_push(&begin->pile_b, &begin->pile_a, 2);
}

int	ft_nb_rra(t_pile *pile, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	t_chunk	*ctmp;
	int		rra;
	int		nb;

	tmp = pile;
	ctmp = chunk;
	rra = 0;
	if (!ctmp || !tmp)
		return (0);
	else
	{
		while (ctmp && ctmp->index != ind)
			ctmp = ctmp->next;
		while (tmp)
		{
			if (tmp && tmp->num >= ctmp->min && tmp->num <= ctmp->max)
				nb = tmp->num;
			tmp = tmp->next;
		}
		tmp = pile;
		while (tmp && tmp->num != nb)
		{
			rra++;
			tmp = tmp->next;
		}
		return (ft_lstsize(pile) - rra);
	}
}

int	ft_nb_ra(t_pile *pile, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	t_chunk	*ctmp;
	int		ra;

	tmp = pile;
	ctmp = chunk;
	ra = 0;
	if (!ctmp || !tmp)
		return (0);
	else
	{
		while (ctmp && ctmp->index != ind)
			ctmp = ctmp->next;
		while (tmp && !(tmp->num >= ctmp->min && tmp->num <= ctmp->max))
		{
			ra++;
			tmp = tmp->next;
		}
		return (ra);
	}
}
