/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:56:58 by nflan             #+#    #+#             */
/*   Updated: 2022/01/19 18:01:56 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_do_reverse_rotate(t_begin *begin)
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
		if (begin->pile_a->num < tmpa->num)
			nb = 2;
	if (begin->pile_b)
	{
		if (begin->pile_b->num > tmpb->num)
			nb++;
	}
	return (nb);
}

void	ft_reverse_rotaty(t_begin *begin)
{
	if (ft_do_reverse_rotate(begin) == 3)
	{
		ft_reverse_rotate(&begin->pile_b, 3);
		ft_reverse_rotate(&begin->pile_a, 3);
		ft_printf("rrr\n");
	}
	else if (ft_do_reverse_rotate(begin) == 1)
		ft_reverse_rotate(&begin->pile_b, 2);
	else if (ft_do_reverse_rotate(begin) == 2)
		ft_reverse_rotate(&begin->pile_a, 1);
}
