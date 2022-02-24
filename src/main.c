/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/02/24 11:23:10 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_exit(t_global *global)
{
	if (global->pile)
		ft_pileclear(global->pile);
	if (global->begin)
		ft_clear_begin(global->begin);
	if (global->btmp)
		ft_clear_begin(global->btmp);
	if (global->chunk)
		ft_clear_chunk(global->chunk);
	free(global);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

int	main(int ac, char **av)
{
	char		**tab;
	t_begin		*begin;
	t_chunk		*chunk;
	t_global	*global;

	begin = NULL;
	tab = NULL;
	chunk = NULL;
	global = NULL;
	if (ac < 2)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	global = ft_calloc(sizeof(t_global), 1);
	if (!global)
		ft_exit(global);
	begin = ft_create_begin(begin, global, tab);
	begin->pile_a = ft_fill_pile(tab, global);
	ft_choose_sort(chunk, global);
	ft_clear_begin(begin);
	free(global);
	return (0);
}
