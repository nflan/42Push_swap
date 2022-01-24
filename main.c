/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/01/21 13:29:44 by nflan            ###   ########.fr       */
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
		if (i == 4 || !pile->next)
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

/*t_chunk	*ft_chunks(t_begin *begin)
{
	static t_chunk	*chunk;
	t_pile			*pile;
	int				i;

	i = 0;
	pile = begin->pile_a;
	sort_pile(&pile);
	if (!chunk)
	{
		chunk = ft_calloc(sizeof(t_chunk), 1);
		chunk->min = pile->num;
		if (ft_lstsize(pile) > 18)
			while (i++ < 19)
				pile = pile->next;
		chunk->max = pile->num;
		chunk->index = 1;
		chunk->next = NULL;
		ft_print_chunk(chunk);
	}
	else
	{
		chunk = ft_more_chunks(chunk, begin);
	}
	return (chunk);
}*/

void	ft_sort(t_begin *begin)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin);
}

void	ft_fill_b(t_begin *begin, t_chunk *chunk)
{
	int	ind;
	int	ra;
	int	rra;

	ind = 1;
//	ft_printf("ra = %d\n", ra);
//	ft_printf("rra = %d\n", rra);
	while (ft_lstsize(begin->pile_b) != 5)
	{
		ra = ft_nb_r(begin->pile_a, chunk, ind);
		rra = ft_nb_rr(begin->pile_a, chunk, ind);
		if (ra >= rra)
			while (ra--)
				ft_rotate(&begin->pile_a, 1);
		else
			while (rra--)
				ft_reverse_rotate(&begin->pile_a, 1);
		ft_push(&begin->pile_a, &begin->pile_b, 1);
	} 
}

int	main(int ac, char **av)
{
	char	**tab;
	t_begin	*begin;
	t_chunk	*chunk;

	begin = NULL;
	tab = NULL;
	begin = ft_calloc(sizeof(t_begin), 1);
	begin->pile_b = ft_calloc(sizeof(t_pile), 1);
	if (ac == 1)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin->pile_a = ft_fill_pile(tab);
//	ft_sort(begin);
	chunk = ft_chunks(begin);
	ft_print_chunk(chunk);
	ft_fill_b(begin, chunk);
	//	ft_fill_pile_b(begin);
	//	ft_sort(begin, 0);
	//	ft_push_all_to_a(begin);
	ft_print_pile(begin->pile_a);
	ft_print_pile(begin->pile_b);
	free(begin);
	free(chunk);
	//	while (1){}
	return (0);
}
