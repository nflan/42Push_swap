/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/01/19 18:01:41 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_begin *begin)
{
	while (ft_is_sort(begin) != 3)
	{
		if (ft_do_swap(begin))
			ft_swappy(begin);
		else if (ft_do_rotate(begin))
			ft_rotaty(begin);
		else if (ft_do_reverse_rotate(begin))
			ft_reverse_rotaty(begin);
		ft_printf("sort = %d\n", ft_is_sort(begin));
		ft_printf("swap = %d\n", ft_do_swap(begin));
		ft_printf("rotate = %d\n", ft_do_rotate(begin));
		ft_printf("reverse rotate = %d\n", ft_do_reverse_rotate(begin));
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
	ft_sort(begin);
	ft_push_all_to_a(begin);
	ft_print_pile(begin->pile_a);
//	ft_print_pile(begin->pile_b);
	//	free(pa);
	//	while (1){}
	return (0);
}
