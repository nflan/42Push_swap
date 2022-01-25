/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/01/25 12:58:16 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
//	t_pile	*tmp;

	ind = 1;
//	tmp = begin->pile_a;
	while (begin->pile_a)
	{
		ra = ft_nb_r(begin->pile_a, chunk, ind);
		rra = ft_nb_rr(begin->pile_a, chunk, ind);
		if (ra >= rra && ra && rra)
			while (ra--)
				ft_rotate(&begin->pile_a, 1);
		else if (ra < rra && ra && rra)
			while (rra--)
				ft_reverse_rotate(&begin->pile_a, 1);
	//	while (begin->pile_b->num && tmp->num > begin->pile_b->num)
	//		ft_rotate(&begin->pile_b, 2);
		ft_push(&begin->pile_a, &begin->pile_b, 1);
		if (!(ft_lstsize(begin->pile_b) % 5))
			ind++;
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
	begin->pile_b = NULL;
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
	ft_pileclear(&begin->pile_a);
	free(begin->pile_b);
	free(begin);
	free(chunk);
	//	while (1){}
	return (0);
}
