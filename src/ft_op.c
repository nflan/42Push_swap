/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:19 by nflan             #+#    #+#             */
/*   Updated: 2022/02/16 14:07:03 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_swap(t_begin *begin, t_pile **pile, int p)
{
	t_pile	*elem1;
	t_pile	*elem2;
	int		tmp;

	elem1 = *pile;
	elem2 = elem1->next;
	tmp = elem1->num;
	if (elem1 && elem2)
	{
		elem1->num = elem2->num;
		elem2->num = tmp;
		if (begin->print)
		{
			if (p == 1)
				ft_printf("sa\n");
			else if (p == 2)
				ft_printf("sb\n");
		}
		return (1);
	}
	return (0);
}

int	ft_push_a(t_begin *begin, t_global *global)
{
	t_pile	*tmpstart;
	t_pile	*tmpend;
	int		nbr;

	nbr = 0;
	tmpstart = begin->pile_a;
	tmpend = begin->pile_b;
	if (!tmpstart)
		return (0);
	nbr = tmpstart->num;
	tmpend = ft_pilenew(nbr, global);
	tmpend->next = begin->pile_b;
	begin->pile_b = tmpend;
	begin->pile_a = tmpstart->next;
	free(tmpstart);
	if (begin->print)
		ft_printf("pb\n");
	return (1);
}

int	ft_push(t_begin *begin, int p, t_global *global)
{
	t_pile	*tmpstart;
	t_pile	*tmpend;
	int		i;
	int		nbr;

	i = 1;
	nbr = 0;
	if (p == 1)
		i = ft_push_a(begin, global);
	else
	{
		tmpstart = begin->pile_b;
		tmpend = begin->pile_a;
		if (!tmpstart)
			return (0);
		nbr = tmpstart->num;
		tmpend = ft_pilenew(nbr, global);
		tmpend->next = begin->pile_a;
		begin->pile_a = tmpend;
		begin->pile_b = tmpstart->next;
		free(tmpstart);
		if (begin->print)
			ft_printf("pa\n");
	}
	return (i);
}

int	ft_reverse_rotate(t_begin *begin, t_pile **pstart, int p)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *pstart;
	tmp2 = *pstart;
	if (*pstart)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = tmp2;
		*pstart = tmp->next;
		tmp->next = NULL;
		if (begin->print)
		{
			if (p == 1)
				ft_printf("rra\n");
			else if (p == 2)
				ft_printf("rrb\n");
			else if (p == 3)
				ft_printf("rrr\n");
		}
		return (1);
	}
	return (0);
}

int	ft_rotate(t_begin *begin, t_pile **pstart, int p)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *pstart;
	tmp2 = *pstart;
	if (tmp->next)
	{
		*pstart = tmp->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tmp2;
		tmp2->next = NULL;
		if (begin->print)
		{
			if (p == 1)
				ft_printf("ra\n");
			else if (p == 2)
				ft_printf("rb\n");
			else if (p == 3)
				ft_printf("rr\n");
		}
		return (1);
	}
	return (0);
}
