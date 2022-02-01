/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:16:04 by nflan             #+#    #+#             */
/*   Updated: 2022/02/01 18:12:42 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_chunk(t_chunk *chunk)
{
	t_chunk	*tmp;

	tmp = chunk;
	while (tmp)
	{
		ft_printf("min %d\n", tmp->min);
		ft_printf("max %d\n", tmp->max);
		ft_printf("index %d\n", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int		pile_is_sort(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

t_pile	*sort_pile(t_pile *pile)
{
	t_pile	*tmp;
	t_pile	*begin;
	int		vtmp;

	tmp = pile;
	begin = pile;
	while (!pile_is_sort(pile) && begin)
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

int	ft_chsize(t_chunk *chunk)
{
	int	i;

	i = 0;
	if (chunk)
	{
		while (chunk)
		{
			i++;
			chunk = chunk->next;
		}
	}
	return (i);
}

t_chunk	*ft_fill_chunks(t_pile *pile, int i, int index)
{
	t_chunk	*chunk;
	t_chunk	*tmp;
	int		min;

	chunk = NULL;
	tmp = NULL;
	while (++i && pile)
	{
		if (i == 1)
			min = pile->num;
		if (i == 46 || !pile->next)
		{
			chunk = ft_chunknew(min, pile->num, index);
			chunk->next = tmp;
			tmp = chunk;
			index++;
			i = 0;
		}
		pile = pile->next;
	}
	return (chunk);
}

t_chunk	*ft_chunks(t_begin *begin)
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
	if (pile)
		return (ft_fill_chunks(pile, 0, 1));
	return (NULL);
}
