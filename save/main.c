/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/02/03 10:38:29 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_lstsize(begin->pile_a) < 10)
		ft_sort(begin);
	else
	{
		chunk = ft_chunks(begin);
		//ft_print_chunk(chunk);
		ft_fill_b(begin, chunk);
		ft_push_all_to_a(begin);
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
	begin = ft_calloc(sizeof(t_begin), 1);
	begin->pile_b = ft_calloc(sizeof(t_pile), 1);
	begin->pile_b = NULL;
	if (ac < 3)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin->pile_a = ft_fill_pile(tab);
	ft_choose_sort(begin, chunk);
//	ft_print_pile(begin->pile_a);
//	ft_print_pile(begin->pile_b);
//	ft_pileclear(&begin->pile_a);
	free(begin->pile_b);
	free(begin);
	free(chunk);
	//	while (1){}
	return (0);
}
