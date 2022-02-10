/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:08 by nflan             #+#    #+#             */
/*   Updated: 2022/02/10 11:49:01 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_five_clean_a(t_pile *tmp, int ra, int pile_min)
{
	while (tmp && tmp->num != pile_min)
	{
		ra++;
		tmp = tmp->next;
	}
	return (ra);
}

int	ft_five_next_a(t_begin *begin, int numb, int pile_min, int pile_max)
{
	t_pile	*tmp;
	int		next;

	tmp = begin->pile_a;
	if (!tmp)
		return (0);
	if (numb >= pile_max || numb <= pile_min)
		return (pile_min);
	while (tmp->next && !(tmp->num < numb && tmp->next->num > numb))
		tmp = tmp->next;
//	ft_printf("numb = %d\n", numb);
	if (!tmp->next && begin->pile_a->num > numb)
		next = begin->pile_a->num;
	else
		next = tmp->next->num;
	return (next);
}

int	ft_five_ra_rra(t_begin *begin, int next)
{
	t_pile	*tmp;
	int		ra;
	int		rra;

	tmp = begin->pile_a;
	ra = 0;
	rra = ft_lstsize(begin->pile_a) * -1;
	if (!tmp)
		return (0);
//	if (numb == pile_min)
//		ra = ft_five_clean_a(tmp, ra, pile_min);
//	else
//	{
	//	ft_printf("next = %i\n", next);
		while (tmp && tmp->num != next)
		{
			ra++;
			tmp = tmp->next;
		}
//	}
	rra += ra;
	if (ra <= (rra * -1))
		return (ra);
	return (rra);
}

void	ft_back_to_a(t_begin *begin)
{
	int	pile_max;
	int	pile_min;
	int	numb;
	int	ra;
	int	next;

	if (begin->pile_b)
	{
		while (begin->pile_b)
		{
			pile_max = ft_pile_max(begin, 1);
			pile_min = ft_pile_min(begin, 1);
			numb = begin->pile_b->num;
			next = ft_five_next_a(begin, numb, pile_min, pile_max);
			ra = ft_five_ra_rra(begin, next);
		//	ft_printf("ra = %d\n", ra);
			if (ra > 0)
			{
				while (ra--)
					ft_rotate(begin, &begin->pile_a, 1);
			}
			else if (ra < 0)
			{
				while (ra++)
					ft_reverse_rotate(begin, &begin->pile_a, 1);
			}
			ft_push(begin, &begin->pile_b, &begin->pile_a, 2);
	//		ft_print_pile(begin->pile_a);
		}
	}
}

void	ft_five(t_begin *begin)
{
	int	ra;

	if (ft_is_sort(begin) != 3)
	{
		while (ft_lstsize(begin->pile_a) > 3)
			ft_push(begin, &begin->pile_a, &begin->pile_b, 1);
		ft_triple(begin, 1);
		ft_back_to_a(begin);
		ra = ft_five_ra_rra(begin, ft_pile_min(begin, 1));
		if (ra > 0)
		{
			while (ra--)
				ft_rotate(begin, &begin->pile_a, 1);
		}
		else if (ra < 0)
		{
			while (ra++)
				ft_reverse_rotate(begin, &begin->pile_a, 1);
		}
	}
//	ft_print_pile(begin->pile_a);
}
