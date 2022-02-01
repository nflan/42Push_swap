/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/02/01 18:13:41 by nflan            ###   ########.fr       */
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

int		ft_is_b_sort(t_begin *begin)
{
	t_pile	*tmp;

	tmp = begin->pile_b;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_min_or_max(t_begin *begin, t_chunk *chunk, int ind)
{
	t_chunk	*ctmp;

	ctmp = chunk;
	if (ctmp)
	{
		while (ctmp->index != ind)
			ctmp = ctmp->next;
		if (begin->pile_a->num == ctmp->min)
			return (-1);
		else if (begin->pile_a->num == ctmp->max)
			return (1);
	}
	return (0);
}

int		ft_min_max_chunk(t_chunk *chunk, int ind, int ext)
{
	t_chunk	*ctmp;

	ctmp = chunk;
	if (ctmp)
	{
		while (ctmp->index != ind)
			ctmp = ctmp->next;
		if (ext == -1)
			return (ctmp->min);
		else if (ext == 1)
			return (ctmp->max);
	}
	return (0);
}

int		ft_nb_rb(t_begin *begin)
{
	t_pile	*tmp;
	int		top;
	int		nb;

	tmp = begin->pile_b;
	nb = 0;
	if (!tmp || !begin->pile_a)
		return (0);
	if (begin->pile_a->num > ft_pile_max(begin, 2) || begin->pile_a->num < ft_pile_min(begin, 2))
		top = ft_pile_max(begin, 2);
	else
	{
		top = ft_pile_min(begin, 2);
		while (tmp)
		{
			if (begin->pile_a->num > top && top < tmp->num && begin->pile_a->num > tmp->num)
				top = tmp->num;
			tmp = tmp->next;
		}
	}
	tmp = begin->pile_b;
	while (tmp && tmp->num != top)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

/*int		ft_nb_rb(t_begin *begin, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		rb;
	int		nb;
	int		n;

	tmp = begin->pile_b;
	rb = 0;
	n = 0;
	if (!tmp || ft_lstsize(tmp) == 1 || !begin->pile_a)
		return (0);
	else
	{
		nb = begin->pile_a->num;
		while (tmp)
		{
			if (begin->pile_a->num < tmp->num)
				nb = tmp->num;
			else
				n++;
			tmp = tmp->next;
		}
		if (n == ft_lstsize(begin->pile_b) && !ft_is_b_sort(begin))
			rb++;
		if (begin->pile_a->num == ft_min_max_chunk(chunk, ind, -1))
			nb = ft_pile_max(begin, 2);
		tmp = begin->pile_b;
		if (begin->pile_a->num > ft_max_pile(begin))
			return (rb);
		else if (tmp->num < nb)
		{
			while (tmp && tmp->num != nb)
			{
				rb++;
				tmp = tmp->next;
				if (tmp && tmp->num == nb && nb != ft_pile_max(begin, 2))
					rb++;
			}
		}
		else if (tmp->num > nb)
		{
			while (tmp && tmp->num != nb)
			{
				rb++;
				tmp = tmp->next;
				if (tmp && tmp->num == nb && nb != ft_pile_max(begin, 2))
					rb++;
			}
		}
		else
			rb++;
		ft_printf("\nb size = %d\n", ft_lstsize(begin->pile_b));
		ft_printf("a = %d", begin->pile_a->num);
		ft_printf("\nrb = %d", rb);
		ft_printf("\ntmp->num = %d\n", tmp->num);
		if (rb <= ft_lstsize(begin->pile_b) / 2)
			return (rb);
		else
			return (rb - ft_lstsize(begin->pile_b));
	}
}*/

/*int		ft_nb_rrb(t_begin *begin)
{
	t_pile	*tmp;
	int		rrb;
	int		nb;

	tmp = begin->pile_b;
	rrb = 0;
	if (!tmp || ft_lstsize(tmp) == 1)
		return (0);
	else
	{
		while (tmp)
		{
			if (tmp && begin->pile_a->num > tmp->num)
				nb = tmp->num;
			tmp = tmp->next;
		}
		tmp = begin->pile_b;
		while (tmp && tmp->num != nb)
		{
			rrb++;
			tmp = tmp->next;
		}
		return (ft_lstsize(begin->pile_b) - rrb);
	}
}*/

/*int		ft_is_between(t_begin *begin)
{
	t_pile	*tmp;
	int		min;
	int		max;

	tmp = begin->pile_b;
	if (!tmp)
		return (0);
	else
	{
		while (tmp)
			if (begin->pile_a) 
		return (0);
		return (1);
	}
}*/

void	ft_next_to_b(t_begin *begin)
{
	t_pile	*tmp;
	int		rb;

	tmp = begin->pile_b;
	rb = ft_nb_rb(begin);
//	ft_printf("num a = %d\n", begin->pile_a->num);
//	ft_printf("rb = %d\n", rb);
	if (tmp && rb)
	{
		if (rb <= ft_lstsize(begin->pile_b) / 2)
			while (rb--)
				ft_rotate(&begin->pile_b, 2);
		else
		{
			rb = ft_lstsize(begin->pile_b) - rb;
//			ft_printf("rb reverse = %d\n", rb);
			if (ft_lstsize(begin->pile_b) > 1)
				while (rb--)
					ft_reverse_rotate(&begin->pile_b, 2);
		}
	}
}

void	ft_b_clean(t_begin *begin)
{
	t_pile	*tmp;
	int		max;
	int		i;

	tmp = begin->pile_b;
	max = ft_pile_max(begin, 2);
	i = 0;
	if (tmp)
	{
		while (tmp->num != max)
		{
			i++;
			tmp = tmp->next;
		}
		if (i <= ft_lstsize(begin->pile_b) / 2)
			while (i--)
				ft_rotate(&begin->pile_b, 2);
		else
		{
			i = ft_lstsize(begin->pile_b) - i;
			if (ft_lstsize(begin->pile_b) > 1)
				while (i--)
					ft_reverse_rotate(&begin->pile_b, 2);
		}
	}
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
		if (ra <= rra && ra && rra)
			while (ra--)
				ft_rotate(&begin->pile_a, 1);
		else if (ra > rra && ra && rra)
			while (rra--)
				ft_reverse_rotate(&begin->pile_a, 1);
		ft_next_to_b(begin);
		ft_push(&begin->pile_a, &begin->pile_b, 1);
//		ft_print_pile(begin->pile_b);
		if (!(ft_lstsize(begin->pile_b) % 46))
		{
			ind++;
			ft_b_clean(begin);
		}
	}
	ft_b_clean(begin);
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
	if (ac == 1)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin->pile_a = ft_fill_pile(tab);
//	ft_print_pile(begin->pile_a);
	if (ft_lstsize(begin->pile_a) < 15)
		ft_sort(begin);
	else
	{
		chunk = ft_chunks(begin);
	//	ft_print_chunk(chunk);
		ft_fill_b(begin, chunk);
	}
	//	ft_fill_pile_b(begin);
	//	ft_sort(begin, 0);
	ft_push_all_to_a(begin);
//	ft_print_pile(begin->pile_a);
//	ft_print_pile(begin->pile_b);
//	ft_pileclear(&begin->pile_a);
//	ft_print_chunk(chunk);
	free(begin->pile_b);
	free(begin);
	free(chunk);
	//	while (1){}
	return (0);
}
