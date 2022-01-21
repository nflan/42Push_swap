/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:08 by nflan             #+#    #+#             */
/*   Updated: 2022/01/21 11:45:19 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_pile_min(t_begin *begin, int pile)
{
	t_pile	*tmp;
	int		min;

	tmp = NULL;
	min = 2147483647;
	if (pile == 1 && begin->pile_a)
		tmp = begin->pile_a;
	else if (pile == 2 && begin->pile_b)
		tmp = begin->pile_b;
	if (tmp)
	{
		while (tmp)
		{
			if (min > tmp->num)
				min = tmp->num;
			tmp = tmp->next;
		}
	}
	return (min);
}

int		ft_pile_max(t_begin *begin, int pile)
{
	t_pile	*tmp;
	int		max;

	tmp = NULL;
	max = 0;
	if (pile == 1 && begin->pile_a)
		tmp = begin->pile_a;
	else if (pile == 2 && begin->pile_b)
		tmp = begin->pile_b;
	if (tmp)
	{
		while (tmp)
		{
			if (max < tmp->num)
				max = tmp->num;
			tmp = tmp->next;
		}
	}
	return (max);
}

void	ft_back_to_a(t_begin *begin)
{
	int	pile_max;
	int	pile_min;
	int	numb;
	int pilesize;
	int	ra;

	pile_max = ft_pile_max(begin, 1);
	pile_min = ft_pile_min(begin, 1);
	numb = begin->pile_b->num;
	pilesize = ft_lstsize(begin->pile_a);
	ra = 0;
	while (pilesize == ft_lstsize(begin->pile_a))
	{
		if (numb > pile_max || numb < pile_min)
		{
			if (begin->pile_a->num == pile_min)
			{
				ft_push(&begin->pile_b, &begin->pile_a, 2);
				if (begin->pile_a->num > begin->pile_a->next->num)
					ft_rotate(&begin->pile_a, 1);
			}
		}
		else if (numb > begin->pile_a->num && numb < begin->pile_a->next->num)
		{
			ft_rotate(&begin->pile_a, 1);
			ft_push(&begin->pile_b, &begin->pile_a, 2);
			ft_reverse_rotate(&begin->pile_a, 1);
			while (ra-- > 0)
				ft_reverse_rotate(&begin->pile_a, 1);
		}
		else
		{
			ft_rotate(&begin->pile_a, 1);
			ra++;
		}
	}
}

void	ft_five(t_begin *begin)
{
	if (ft_is_sort(begin) != 3)
	{
		while (ft_lstsize(begin->pile_a) > 3)
			ft_push(&begin->pile_a, &begin->pile_b, 1);
		ft_triple(begin, 1);
		while (ft_lstsize(begin->pile_b))
			ft_back_to_a(begin);
	}
}
