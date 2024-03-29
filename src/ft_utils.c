/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:06 by nflan             #+#    #+#             */
/*   Updated: 2022/02/16 13:53:17 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_push_all_to_a(t_begin *begin, t_global *global)
{
	while (begin->pile_b && begin->bmoves > begin->moves)
		begin->moves += ft_push(begin, 2, global);
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

int	ft_biggest(int nb1, int nb2)
{
	if (nb1 >= 0 && nb2 >= 0)
	{
		if (nb1 > nb2)
			return (nb1);
		return (nb2);
	}
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}
