/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/02/10 17:20:59 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort(t_begin *begin)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin);
}

void	ft_choose_sort(t_begin *begin, t_chunk *chunk)
{
	t_pile	*tmp;
	t_begin	*btmp;
//	t_begin	*tofree;
	int		i;
	int		index;
	int		nb;

	if (ft_lstsize(begin->pile_a) > 239)
		i = 30;
	else
		i = 0;
	nb = 2147483646;
//	ft_print_begin(begin);
	if (ft_lstsize(begin->pile_a) < 10)
		ft_sort(begin);
	else
	{
		tmp = ft_pile_chunk(begin);
		while (i++ < 55 && (ft_lstsize(tmp) - i) > -1)
		{
			btmp = ft_begin_cpy(begin, nb + 1);
			chunk = ft_fill_chunks(tmp, i, 1);
		//	ft_print_chunk(chunk);
			ft_fill_b(btmp, chunk);
		//	ft_print_begin(btmp);
			if (btmp->moves < nb && btmp->moves > 0 && pile_is_incr(btmp->pile_a) && !(btmp->pile_b))
			{
				nb = btmp->moves;
			//	ft_printf("best moves / nb = %i\n", nb);
				index = i;
			//	ft_printf("best index / chunks = %i\n", index);
	//			ft_print_begin(btmp);
			}
		//	ft_printf("nb chunks = %i\n", size);
		//	ft_print_begin(btmp);
//			ft_print_chunk(chunk);
//			ft_printf("moves / nb = %i\n", btmp->moves);
		//	tofree = btmp;
		//	free(tofree);
		}
//		ft_printf("best moves / nb = %i\n", nb);
		begin->bmoves = nb;
		chunk = ft_fill_chunks(tmp, index, 1);
		ft_fill_b(begin, chunk);
//		ft_print_chunk(chunk);
	//	ft_printf("moves begin = %i\n", begin->moves);
	//	ft_print_begin(begin);
	}
}

int	main(int ac, char **av)
{
	char	**tab;
	t_begin	*begin;
	t_chunk	*chunk;

	begin = NULL;
	tab = NULL;
	chunk = NULL;
	if (ac < 2)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin = ft_create_begin(begin);
	begin->pile_a = ft_fill_pile(tab);
	ft_choose_sort(begin, chunk);
	//	ft_print_pile(begin->pile_a);
	//	ft_print_pile(begin->pile_b);
	//	ft_pileclear(&begin->pile_a);
//	ft_print_pile(begin->pile_a);
//	ft_print_chunk(chunk);
/*	while (begin->pile_a)
	{
		free(begin->pile_a);
		begin->pile_a = begin->pile_a->next;
	}*/
	free(begin->pile_a);
//	free(begin->pile_b);
	free(begin);
//	free(chunk);
		while (1){}
	return (0);
}
