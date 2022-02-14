/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:16:04 by nflan             #+#    #+#             */
/*   Updated: 2022/02/09 15:46:25 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_nb_chunk(t_begin *btmp, int nbsize, int i)
{
	int	nbchunk;

	nbchunk = 0;
	if (ft_lstsize(btmp->pile_a) % i)
		nbchunk = ft_lstsize(btmp->pile_a) / i + 1;
	else
		nbchunk = ft_lstsize(btmp->pile_a) / i;
	if (nbchunk == nbsize)
		return (0);
	else
		return (nbchunk);
}

int	ft_min_max_chunk(t_chunk *chunk, int ind, int ext)
{
	t_chunk	*ctmp;

	ctmp = chunk;
	if (ctmp)
	{
		while (ctmp->index != ind)
			ctmp = ctmp->next;
		if (ext == -1)
			return (ctmp->min);
		else if (ext == 1)
			return (ctmp->max);
	}
	return (0);
}

t_pile	*sort_pile(t_pile *pile)
{
	t_pile	*tmp;
	t_pile	*begin;
	int		vtmp;

	tmp = pile;
	begin = pile;
	while (!pile_is_incr(pile) && begin)
	{
		while (tmp)
		{
			if (tmp->num > begin->num)
			{
				vtmp = begin->num;
				begin->num = tmp->num;
				tmp->num = vtmp;
			}
			tmp = tmp->next;
		}
		tmp = pile;
		begin = begin->next;
	}
	return (pile);
}

t_chunk	*ft_fill_chunks(t_pile *pile, int sizec, int index)
{
	t_chunk	*chunk;
	t_chunk	*tmp;
	int		min;
	int		i;

	chunk = NULL;
	tmp = NULL;
	i = 0;
	while (++i && pile)
	{
		if (i == 1)
			min = pile->num;
		if (i == sizec || !pile->next)
		{
			chunk = ft_chunknew(min, pile->num, index, sizec);
			chunk->next = tmp;
			tmp = chunk;
			index++;
			i = 0;
		}
		pile = pile->next;
	}
	return (chunk);
}

t_pile	*ft_pile_chunk(t_begin *begin)
{
	t_pile	*pile;
	t_pile	*tmp;
	t_pile	*ptr;

	pile = NULL;
	ptr = NULL;
	tmp = begin->pile_a;
	while (tmp)
	{
		pile = ft_calloc(sizeof(t_pile), 1);
		pile->num = tmp->num;
		pile->next = ptr;
		ptr = pile;
		tmp = tmp->next;
	}
	pile = sort_pile(pile);
	return (pile);
}
