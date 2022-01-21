/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/01/21 10:29:40 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_sort(t_begin *begin, int last)
  {
  }*/

int		ft_pile_min(t_begin *begin, int pile)
{
	t_pile	*tmp;
	int		min;

	tmp = NULL;
	min = 2147483647;
	if (pile == 1 && begin->pile_a)
		tmp = begin->pile_a;
	else if (pile == 2 && begin->pile_b)
		tmp = begin->pile_b;
	if (tmp)
	{
		while (tmp)
		{
			if (min > tmp->num)
				min = tmp->num;
			tmp = tmp->next;
		}
	}
	return (min);
}

int		ft_pile_max(t_begin *begin, int pile)
{
	t_pile	*tmp;
	int		max;

	tmp = NULL;
	max = 0;
	if (pile == 1 && begin->pile_a)
		tmp = begin->pile_a;
	else if (pile == 2 && begin->pile_b)
		tmp = begin->pile_b;
	if (tmp)
	{
		while (tmp)
		{
			if (max < tmp->num)
				max = tmp->num;
			tmp = tmp->next;
		}
	}
	return (max);
}

void	ft_back_to_a(t_begin *begin)
{
	int	pile_max;
	int	pile_min;
	int	numb;
	int pilesize;
	int	ra;

	pile_max = ft_pile_max(begin, 1);
	pile_min = ft_pile_min(begin, 1);
	numb = begin->pile_b->num;
	pilesize = ft_lstsize(begin->pile_a);
	ra = 0;
//	ft_print_pile(begin->pile_a);
//	ft_print_pile(begin->pile_b);
	while (pilesize == ft_lstsize(begin->pile_a))
	{
		if (numb > pile_max || numb < pile_min)
		{
			if (begin->pile_a->num == pile_min)
			{
				ft_push(&begin->pile_b, &begin->pile_a, 2);
				if (begin->pile_a->num > begin->pile_a->next->num)
					ft_rotate(&begin->pile_a, 1);
			}
		}
		else if (numb > begin->pile_a->num && numb < begin->pile_a->next->num)
		{
			ft_rotate(&begin->pile_a, 1);
			ft_push(&begin->pile_b, &begin->pile_a, 2);
			ft_reverse_rotate(&begin->pile_a, 1);
			while (ra-- > 0)
				ft_reverse_rotate(&begin->pile_a, 1);
		}
		else
		{
			ft_rotate(&begin->pile_a, 1);
			ra++;
		}
	}
}

void	ft_five(t_begin *begin)
{
	if (ft_is_sort(begin) != 3)
	{
		while (ft_lstsize(begin->pile_a) > 3)
			ft_push(&begin->pile_a, &begin->pile_b, 1);
		ft_triple(begin, 1);
		while (ft_lstsize(begin->pile_b))
			ft_back_to_a(begin);
	}
}

void	ft_sort(t_begin *begin)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin);
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
	ft_sort(begin);
	//	ft_fill_pile_b(begin);
	//	ft_sort(begin, 0);
	//	ft_push_all_to_a(begin);
//	ft_print_pile(begin->pile_a);
//	ft_print_pile(begin->pile_b);
	free(begin);
	//	while (1){}
	return (0);
}
