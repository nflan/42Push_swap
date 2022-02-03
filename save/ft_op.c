/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:19 by nflan             #+#    #+#             */
/*   Updated: 2022/02/02 17:47:03 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_pile **pile, int p)
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
		if (p == 1)
			ft_printf("sa\n");
		else if (p == 2)
			ft_printf("sb\n");
		return (1);
	}
	return (0);
}

int	ft_push(t_pile **pstart, t_pile **pend, int p)
{
	t_pile	*tmpstart;
	t_pile	*tmpend;
	int		nbr;

	tmpstart = *pstart;
	tmpend = *pend;
	nbr = 0;
	if (*pstart)
	{
		nbr = tmpstart->num;
		tmpend = ft_pilenew(nbr);
		tmpend->next = *pend;
		*pend = tmpend;
		*pstart = tmpstart->next;
		if (p == 1)
			ft_printf("pb\n");
		else if (p == 2)
			ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	ft_reverse_rotate(t_pile **pstart, int p)
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
		if (p == 1)
			ft_printf("rra\n");
		else if (p == 2)
			ft_printf("rrb\n");
		else if (p == 3)
			ft_printf("rrr\n");
		return (1);
	}
	return (0);
}

int	ft_rotate(t_pile **pstart, int p)
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
		if (p == 1)
			ft_printf("ra\n");
		else if (p == 2)
			ft_printf("rb\n");
		else if (p == 3)
			ft_printf("rr\n");
		return (1);
	}
	return (0);
}
