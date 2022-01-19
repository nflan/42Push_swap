/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:14 by nflan             #+#    #+#             */
/*   Updated: 2022/01/19 17:29:37 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*ft_fill_pile(char **tab)
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
		ptr = ft_pilenew(nbr);
		ptr->next = pile;
		pile = ptr;
		free(tab[i]);
	}
	return (ptr);
}

void	ft_fill_pile_b(t_begin *begin)
{
	t_pile	*tmp;
	int		med;
	int		mid;

	tmp = begin->pile_a;
	med = ft_is_median(begin);
	mid = ft_lstsize(begin->pile_a) / 2;
	if (tmp && ft_is_sort(begin) != 3)
	{
		while (ft_lstsize(begin->pile_a) > mid)
		{
			while (begin->pile_a->num > med || (begin->pile_a->num == med
					&& !ft_lstsize(begin->pile_a) % 2))
			{
				if (ft_next_to_move(&begin->pile_a, med) == 'a')
					ft_rotate(&begin->pile_a, 1);
				else
					ft_reverse_rotate(&begin->pile_a, 1);
			}
			ft_push(&begin->pile_a, &begin->pile_b, 1);
		}
	}
}

char	ft_next_to_move(t_pile **pile, int med)
{
	t_pile	*tmp;
	int		ra;
	int		rra;

	tmp = *pile;
	ra = 0;
	rra = 0;
	if (!tmp)
		return (0);
	ra = ft_nb_r(tmp, med);
	tmp = *pile;
	rra = ft_nb_rr(tmp, med);
	if (ra <= rra)
		return ('a');
	else
		return ('b');
}

void	ft_print_pile(t_pile *pile)
{
	while (pile)
	{
		ft_printf("%d\n", pile->num);
		pile = pile->next;
	}
	ft_printf("\n");
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
			return (0);
		while (av[++i])
		{
			k = -1;
			tab[++j] = ft_calloc(sizeof(char), ft_strlen(av[i]) + 1);
			if (!tab[j])
				return (0);
			while (av[i][++k])
				tab[j][k] = av[i][k];
		}
	}
	ft_check_tab(tab);
	return (tab);
}
