/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:41:17 by nflan             #+#    #+#             */
/*   Updated: 2022/02/02 17:48:46 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_next_to_b(t_begin *begin, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		rb;

	tmp = begin->pile_b;
	rb = ft_nb_rb(begin, ft_nb_next_p(begin, chunk, ind));
	if (tmp && rb)
	{
		if (rb <= ft_lstsize(begin->pile_b) / 2)
			while (rb--)
				ft_rotate(&begin->pile_b, 2);
		else
		{
			rb = ft_lstsize(begin->pile_b) - rb;
			if (ft_lstsize(begin->pile_b) > 1)
				while (rb--)
					ft_reverse_rotate(&begin->pile_b, 2);
		}
	}
}

void	ft_finish_rotate_a(t_begin *begin, t_chunk *chunk, int ind, int ra)
{
	if (ra > 0)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind))
			ft_rotate(&begin->pile_a, 1);
	else if (ra < 0)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind))
			ft_reverse_rotate(&begin->pile_a, 1);
}

void	ft_move_both(t_begin *begin, t_chunk *chunk, int ind)
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
			ft_rotate(&begin->pile_a, 3);
			ft_rotate(&begin->pile_b, 0);
		}
	}
	else if (ra < 0 && rb && rb > ft_lstsize(begin->pile_b) / 2)
	{
		rb = ft_lstsize(begin->pile_b) - rb;
	//	while (ra++ && rb--)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind) && rb--)
		{
			ft_reverse_rotate(&begin->pile_a, 3);
			ft_reverse_rotate(&begin->pile_b, 0);
		}
	}
	ft_finish_rotate_a(begin, chunk, ind, ra);
}

void	ft_fill_b(t_begin *begin, t_chunk *chunk)
{
	int	ind;

	ind = 1;
	while (begin->pile_a)
	{
		ft_move_both(begin, chunk, ind);
	//	ft_printf("ft_nb_next_p = %d\n", ft_nb_next_p(begin, chunk, ind));
		ft_next_to_b(begin, chunk, ind);
		ft_push(&begin->pile_a, &begin->pile_b, 1);
		if (!(ft_lstsize(begin->pile_b) % chunk->size))
		{
			ind++;
			ft_b_clean(begin);
	//		ft_print_pile(begin->pile_b);
		}
	}
	ft_b_clean(begin);
//	ft_print_chunk(chunk);
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
