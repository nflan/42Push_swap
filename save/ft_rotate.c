/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:55:23 by nflan             #+#    #+#             */
/*   Updated: 2022/01/20 10:30:48 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_rotate(t_begin *begin)
{
	t_pile	*tmpa;
	t_pile	*tmpb;
	int		nb;

	tmpa = begin->pile_a;
	while (tmpa->next)
		tmpa = tmpa->next;
	tmpb = begin->pile_b;
	while (tmpb->next)
		tmpb = tmpb->next;
	nb = 0;
	if (begin->pile_a)
		if (begin->pile_a->num > tmpa->num)
			nb = 2;
	if (begin->pile_b)
	{
		if (begin->pile_b->num < tmpb->num)
			nb++;
	}
	return (nb);
}

int	ft_rotaty(t_begin *begin, int last)
{
	if (ft_do_rotate(begin) && last != 10)
	{
		if (ft_do_rotate(begin) == 3 && last != 4)
		{
			ft_rotate(&begin->pile_b, 3);
			ft_rotate(&begin->pile_a, 3);
			ft_printf("rr\n");
			return (1);
		}
		else if (ft_do_rotate(begin) == 1 && last != 5)
		{
			ft_rotate(&begin->pile_b, 2);
			return (2);
		}
		else if (ft_do_rotate(begin) == 2 && last != 6)
		{
			ft_rotate(&begin->pile_a, 1);
			return (3);
		}
		return (10);
	}
	return (0);
}
