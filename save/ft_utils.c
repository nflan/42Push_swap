/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:06 by nflan             #+#    #+#             */
/*   Updated: 2022/01/18 15:37:52 by nflan            ###   ########.fr       */
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
		if (ft_push(&begin->pile_b, &begin->pile_a))
			ft_printf("pa\n");
}

int	ft_median(t_begin *begin)
{
	t_pile	*tmp;
	int		psize;
	int		pnbr;

	tmp = begin->pile_a;
	psize = ft_lstsize(begin->pile_a);
	pnbr = 0;
	if (tmp)
	{
		while (tmp)
		{
			pnbr += tmp->num;
			tmp = tmp->next;
		}
		pnbr /= psize;
		return (pnbr);
	}
	return (0);
}
