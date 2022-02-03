/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:41:17 by nflan             #+#    #+#             */
/*   Updated: 2022/02/03 12:48:06 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_next_to_b(t_begin *begin, t_chunk *chunk, int ind, int moves)
{
	t_pile	*tmp;
	int		rb;

	tmp = begin->pile_b;
	rb = ft_nb_rb(begin, ft_nb_next_p(begin, chunk, ind));
	if (tmp && rb)
	{
		if (rb <= ft_lstsize(begin->pile_b) / 2)
			while (rb--)
				moves += ft_rotate(&begin->pile_b, 2);
		else
		{
			rb = ft_lstsize(begin->pile_b) - rb;
			if (ft_lstsize(begin->pile_b) > 1)
				while (rb--)
					moves += ft_reverse_rotate(&begin->pile_b, 2);
		}
	}
	return (moves);
}

int	ft_finish_rotate_a(t_begin *begin, t_chunk *chunk, int ind, int ra)
{
	int	moves;

	moves = 0;
	if (ra > 0)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind))
			moves += ft_rotate(&begin->pile_a, 1);
	else if (ra < 0)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind))
			moves += ft_reverse_rotate(&begin->pile_a, 1);
	return (moves);
}

int	ft_move_both(t_begin *begin, t_chunk *chunk, int ind, int moves)
{
	int	ra;
	int	rb;

	ra = ft_nb_ra_rra(begin, ft_nb_next_p(begin, chunk, ind));
	rb = ft_nb_rb(begin, ft_nb_next_p(begin, chunk, ind));
	if (ra > 0 && rb && rb <= ft_lstsize(begin->pile_b) / 2)
	{
//		while (ra-- && rb--)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind) && rb--)
		{
			moves += ft_rotate(&begin->pile_a, 3);
			ft_rotate(&begin->pile_b, 0);
		}
	}
	else if (ra < 0 && rb && rb > ft_lstsize(begin->pile_b) / 2)
	{
		rb = ft_lstsize(begin->pile_b) - rb;
	//	while (ra++ && rb--)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind) && rb--)
		{
			moves += ft_reverse_rotate(&begin->pile_a, 3);
			ft_reverse_rotate(&begin->pile_b, 0);
		}
	}
	moves += ft_finish_rotate_a(begin, chunk, ind, ra);
	return (moves);
}

int	ft_fill_b(t_begin *begin, t_chunk *chunk, int moves)
{
	int	ind;

	ind = 0;
	while (begin->pile_a)
	{
		moves = ft_move_both(begin, chunk, ind, moves);
	//	ft_printf("ft_nb_next_p = %d\n", ft_nb_next_p(begin, chunk, ind));
		moves = ft_next_to_b(begin, chunk, ind, moves);
		moves += ft_push(&begin->pile_a, &begin->pile_b, 1);
		if (begin->pile_a && !(ft_lstsize(begin->pile_b) % chunk->size))
		{
			ind++;
			moves = ft_b_clean(begin, moves);
	//		ft_print_pile(begin->pile_b);
		}
	}
	moves = ft_b_clean(begin, moves);
//	ft_print_chunk(chunk);
	return (moves);
}

int ft_b_clean(t_begin *begin, int moves)
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
				moves += ft_rotate(&begin->pile_b, 2);
		else
		{
			i = ft_lstsize(begin->pile_b) - i;
			if (ft_lstsize(begin->pile_b) > 1)
				while (i--)
					moves += ft_reverse_rotate(&begin->pile_b, 2);
		}
	}
	return (moves);
}
