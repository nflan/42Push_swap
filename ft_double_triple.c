/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_triple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:36:29 by nflan             #+#    #+#             */
/*   Updated: 2022/02/03 17:38:35 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double(t_begin *begin, int pile)
{
	t_pile	*tmp;

	tmp = NULL;
	if (pile == 1)
		tmp = begin->pile_a;
	if (pile == 2)
		tmp = begin->pile_b;
	if (ft_lstsize(tmp) == 2 && ft_is_sort(begin) != 3)
	{
		if (pile == 1)
			ft_swap(&begin->pile_a, pile);
		if (pile == 2)
			ft_swap(&begin->pile_b, pile);
	}
}

void	ft_triple(t_begin *begin, int pile)
{
	t_pile	*tmp;

	tmp = NULL;
	if (pile == 1)
		tmp = begin->pile_a;
	if (pile == 2)
		tmp = begin->pile_b;
	if ((ft_lstsize(tmp) == 3) && ft_is_sort(begin) != 3)
	{
		if (pile == 1 && ft_is_sort(begin) != 2)
			ft_do_triple(&begin->pile_a, pile);
		if (pile == 2)
			ft_do_triple(&begin->pile_b, pile);
	}
}

void	ft_do_triple(t_pile **pile, int p)
{
	t_pile	*tmp;
	int		first;
	int		second;
	int		third;

	tmp = *pile;
	first = tmp->num;
	second = tmp->next->num;
	third = tmp->next->next->num;
	if (first > second && first < third)
		ft_swap(pile, p);
	else if (first > second && second > third)
	{
		ft_swap(pile, p);
		ft_reverse_rotate(pile, p);
	}
	else if (first > second && second < third)
		ft_rotate(pile, p);
	else if (first < second && first < third)
	{
		ft_swap(pile, p);
		ft_rotate(pile, p);
	}
	else if (second > first && second > third)
		ft_reverse_rotate(pile, p);
}
