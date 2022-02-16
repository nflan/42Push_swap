/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:11:22 by nflan             #+#    #+#             */
/*   Updated: 2022/02/16 14:55:19 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_clear_begin(t_begin *begin)
{
	if (begin->pile_a)
		ft_pileclear(begin->pile_a);
	if (begin->pile_b)
		ft_pileclear(begin->pile_b);
	free(begin);
}

void	ft_clear_chunk(t_chunk *chunk)
{
	t_chunk	*tmp;

	if (chunk)
	{
		while (chunk)
		{
			tmp = chunk;
			chunk = tmp->next;
			free(tmp);
		}
	}
	chunk = NULL;
}

void	ft_sort(t_begin *begin, t_global *global)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin, global);
}

t_chunk	*ft_big_sort(t_begin *begin, t_chunk *chunk, int i, t_global *global)
{
	t_pile	*tmp;
	t_begin	*btmp;
	int		index;
	int		nb;

	nb = 2147483646;
	tmp = ft_pile_chunk(begin, global);
	while (i++ < 55 && (ft_lstsize(tmp) - i) > -1)
	{
		btmp = ft_begin_cpy(begin, nb + 1, global);
		chunk = ft_fill_chunks(tmp, i, 1, global);
		ft_fill_b(btmp, chunk, global, 1);
		if (btmp->moves < nb && btmp->moves > 0 && pile_incr(btmp->pile_a))
		{
			nb = btmp->moves;
			index = i;
		}
		ft_clear_begin(btmp);
	}
	begin->bmoves = nb;
	chunk = ft_fill_chunks(tmp, index, 1, global);
	ft_pileclear(tmp);
	return (chunk);
}

void	ft_choose_sort(t_begin *begin, t_chunk *chunk, t_global *global)
{
	t_chunk	*ctmp;
	t_chunk	*ctmp2;
	int		i;
	int		nb;

	ctmp = NULL;
	ctmp2 = NULL;
	if (ft_lstsize(begin->pile_a) > 239)
		i = 30;
	else
		i = 0;
	if (ft_lstsize(begin->pile_a) < 10)
		ft_sort(begin, global);
	else
	{
		ctmp = ft_big_sort(begin, chunk, i, global);
		nb = begin->bmoves;
		ctmp2 = ft_big_sort2(begin, chunk, i, global);
		if (nb <= begin->bmoves)
			ft_fill_b(begin, ctmp, global, 1);
		else
			ft_fill_b(begin, ctmp2, global, 2);
	}
	ft_clear_begin(begin);
}
