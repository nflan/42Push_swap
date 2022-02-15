/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:11:22 by nflan             #+#    #+#             */
/*   Updated: 2022/02/15 20:58:54 by nflan            ###   ########.fr       */
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

void	ft_sort(t_begin *begin)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin);
}

void	ft_big_sort(t_begin *begin, t_chunk *chunk, int i, int nb)
{
	t_pile	*tmp;
	t_begin	*btmp;
	int		index;

	tmp = ft_pile_chunk(begin);
	while (i++ < 55 && (ft_lstsize(tmp) - i) > -1)
	{
		btmp = ft_begin_cpy(begin, nb + 1);
		chunk = ft_fill_chunks(tmp, i, 1);
		ft_fill_b(btmp, chunk);
		if (btmp->moves < nb && btmp->moves > 0 && pile_incr(btmp->pile_a))
		{
			nb = btmp->moves;
			index = i;
		}
		ft_clear_begin(btmp);
		ft_clear_chunk(chunk);
	}
	begin->bmoves = nb;
	chunk = ft_fill_chunks(tmp, index, 1);
	ft_fill_b(begin, chunk);
	ft_pileclear(tmp);
	ft_clear_begin(begin);
	ft_clear_chunk(chunk);
}

void	ft_choose_sort(t_begin *begin, t_chunk *chunk)
{
	int		i;
	int		nb;

	if (ft_lstsize(begin->pile_a) > 239)
		i = 30;
	else
		i = 0;
	nb = 2147483646;
	if (ft_lstsize(begin->pile_a) < 10)
		ft_sort(begin);
	else
		ft_big_sort(begin, chunk, i, nb);
}
