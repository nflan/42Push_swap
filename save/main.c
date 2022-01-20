/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/01/20 11:27:10 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_begin *begin, int last)
{
	while (ft_is_sort(begin) != 3)
	{
		if (ft_do_swap(begin))
			last = ft_swappy(begin, last);
		if (ft_do_rotate(begin))
			last = ft_rotaty(begin, last);
		if (ft_do_reverse_rotate(begin))
			last = ft_reverse_rotaty(begin, last);
	}
}

int	main(int ac, char **av)
{
	char	**tab;
	t_begin	*begin;

	begin = NULL;
	tab = NULL;
	begin = ft_calloc(sizeof(t_begin), 1);
	begin->pile_b = NULL;
	if (ac == 1)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin->pile_a = ft_fill_pile(tab);
	ft_fill_pile_b(begin);
	ft_sort(begin, 0);
	ft_push_all_to_a(begin);
	ft_print_pile(begin->pile_a);
	//	ft_print_pile(begin->pile_b);
	//	free(pa);
	//	while (1){}
	return (0);
}
