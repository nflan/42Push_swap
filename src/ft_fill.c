/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:14 by nflan             #+#    #+#             */
/*   Updated: 2022/02/24 12:11:39 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*ft_fill_pile(char **tab, t_global *global)
{
	t_pile	*pile;
	t_pile	*ptr;
	int		i;
	int		nbr;

	pile = NULL;
	ptr = NULL;
	i = ft_count_line(tab);
	while (i--)
	{
		nbr = ft_atoi(tab[i]);
		ptr = ft_pilenew(nbr, global);
		ptr->next = pile;
		pile = ptr;
		tab[i][0] = '\0';
		free(tab[i]);
	}
	free(tab);
	if (!ft_check_double(ptr))
		ft_exit(global);
	return (ptr);
}

void	ft_exit_tab(char **tab)
{
	int	i;

	i = ft_count_line(tab);
	if (i > 0)
	{
		while (i--)
		{
			tab[i][0] = '\0';
			free(tab[i]);
		}
	}
	if (tab)
		free(tab);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

char	**ft_fill_argv(char **tab, int ac, char **av)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
	{
		tab = ft_calloc(sizeof(char *), ac);
		if (!tab)
			ft_exit_tab(tab);
		while (av[++i])
		{
			k = -1;
			tab[++j] = ft_calloc(sizeof(char), ft_strlen(av[i]) + 1);
			if (!tab[j])
				ft_exit_tab(tab);
			while (av[i][++k])
				tab[j][k] = av[i][k];
		}
	}
	ft_check_tab(tab);
	return (tab);
}

t_pile	*ft_fill_cpy(t_global *global)
{
	t_pile	*begin;
	t_pile	*ptr;
	t_pile	*new;

	begin = global->begin->pile_a;
	ptr = NULL;
	new = NULL;
	while (begin)
	{
		ptr = ft_pilenew(begin->num, global);
		ft_lstadd_back(&new, ptr);
		begin = begin->next;
	}
	return (new);
}
