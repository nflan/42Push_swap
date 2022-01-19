/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:35:02 by nflan             #+#    #+#             */
/*   Updated: 2022/01/19 17:53:31 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_swap(t_begin *begin)
{
	int	nb;

	nb = 0;
	if (begin->pile_a)
		if (begin->pile_a->num > begin->pile_a->next->num)
			nb = 2;
	if (begin->pile_b)
	{
		if (begin->pile_b->num < begin->pile_b->next->num)
			nb++;
	}
	return (nb);
}

void	ft_swappy(t_begin *begin)
{
	if (ft_do_swap(begin) == 3)
	{
		ft_swap(&begin->pile_b, 3);
		ft_swap(&begin->pile_a, 3);
		ft_printf("ss\n");
	}
	else if (ft_do_swap(begin) == 1)
		ft_swap(&begin->pile_b, 2);
	else if (ft_do_swap(begin) == 2)
		ft_swap(&begin->pile_a, 1);
}
