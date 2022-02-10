/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:50:46 by nflan             #+#    #+#             */
/*   Updated: 2022/02/10 17:26:05 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finish_rotate_a(t_begin *btmp, t_chunk *chunk, int ind, int ra)
{
	if (ra > 0 && btmp->bmoves > btmp->moves)
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind)
			&& btmp->bmoves > btmp->moves)
			btmp->moves += ft_rotate(btmp, &btmp->pile_a, 1);
	else if (ra < 0 && btmp->bmoves > btmp->moves)
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind)
			&& btmp->bmoves > btmp->moves)
			btmp->moves += ft_reverse_rotate(btmp, &btmp->pile_a, 1);
}

int	ft_find_last(t_pile *pile, t_chunk *chunk, int ind, int nbtmp)
{
	t_pile	*tmp;

	tmp = pile;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp && ft_min_in_max(tmp, chunk, ind) != 0)
				nbtmp = tmp->num;
			tmp = tmp->next;
		}
	}
	return (nbtmp);
}

int	ft_find_rra_rrb(t_pile *pile, t_chunk *chunk, int ind, int nbtmp)
{
	t_pile	*tmp;
	int		y;

	tmp = pile;
	y = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp && ft_min_in_max(tmp, chunk, ind))
			{
				nbtmp = tmp->num;
				y = 0;
			}
			y++;
			tmp = tmp->next;
		}
	}
	return (y);
}

int	ft_nb_next_p(t_begin *btmp, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		nbtmp;
	int		nbr;
	int		i;
	int		y;

	tmp = btmp->pile_a;
	i = 0;
	y = 0;
	if (!tmp)
		return (0);
	if (ft_lstsize(tmp) == 1)
		return (tmp->num);
	while (++i && tmp && !ft_min_in_max(tmp, chunk, ind))
		tmp = tmp->next;
	nbr = tmp->num;
	nbtmp = nbr;
	if (tmp)
	{
		nbtmp = ft_find_last(tmp, chunk, ind, nbtmp);
		y = ft_find_rra_rrb(tmp, chunk, ind, nbtmp);
	}
	if (i <= y)
		return (nbr);
	return (nbtmp);
}

int	ft_nb_ra_rra(t_begin *btmp, int nbr, t_roll *roll)
{
	t_pile	*tmp;
	int		ra;
	int		rra;

	tmp = btmp->pile_a;
	ra = 0;
	rra = -1;
	if (!tmp)
		return (0);
	while (tmp && tmp->num != nbr)
	{
		ra++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		rra--;
		tmp = tmp->next;
	}
	ft_fill_roll_a(roll, ra, rra + 1);
	if (ra <= (rra * -1))
		return (ra);
	return (rra);
}
