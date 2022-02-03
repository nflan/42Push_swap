/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:41:17 by nflan             #+#    #+#             */
/*   Updated: 2022/02/03 17:54:37 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_next_to_b(t_begin *begin, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		rb;

	if (ind == 0)
	{
		ft_printf("ICI c'est le debut \n");
		ft_print_begin(begin);
//		ft_print_pile(begin->pile_a);
	}
	tmp = begin->pile_b;
	rb = ft_nb_rb(begin, ft_nb_next_p(begin, chunk, ind));
	if (tmp && rb)
	{
		if (rb <= ft_lstsize(begin->pile_b) / 2)
			while (rb--)
				begin->moves += ft_rotate(&begin->pile_b, 2);
		else
		{
			rb = ft_lstsize(begin->pile_b) - rb;
			if (ft_lstsize(begin->pile_b) > 1)
				while (rb--)
					begin->moves += ft_reverse_rotate(&begin->pile_b, 2);
		}
	}
	if (ind == 0)
	{
		ft_printf("ICI c'est la fin \n");
		ft_print_begin(begin);
//	ft_print_pile(begin->pile_a);
	}
}

void	ft_finish_rotate_a(t_begin *begin, t_pile *pile, t_chunk *chunk, int ind, int ra)
{
	t_pile	*tmp;

	tmp = pile;
	if (ra > 0)
		while (tmp->num != ft_nb_next_p(begin, chunk, ind))
			begin->moves += ft_rotate(&tmp, 1);
	else if (ra < 0)
		while (tmp->num != ft_nb_next_p(begin, chunk, ind))
			begin->moves += ft_reverse_rotate(&tmp, 1);
}

void	ft_move_both(t_begin *begin, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int	ra;
	int	rb;

	tmp = begin->pile_a;
	ra = ft_nb_ra_rra(begin, ft_nb_next_p(begin, chunk, ind));
	rb = ft_nb_rb(begin, ft_nb_next_p(begin, chunk, ind));
	if (ra > 0 && rb && rb <= ft_lstsize(begin->pile_b) / 2)
	{
//		while (ra-- && rb--)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind) && rb--)
		{
			begin->moves += ft_rotate(&begin->pile_a, 3);
			ft_rotate(&begin->pile_b, 0);
		}
	}
	else if (ra < 0 && rb && rb > ft_lstsize(begin->pile_b) / 2)
	{
		rb = ft_lstsize(begin->pile_b) - rb;
	//	while (ra++ && rb--)
		while (begin->pile_a->num != ft_nb_next_p(begin, chunk, ind) && rb--)
		{
			begin->moves += ft_reverse_rotate(&begin->pile_a, 3);
			ft_reverse_rotate(&begin->pile_b, 0);
		}
	}
	ft_finish_rotate_a(begin, tmp, chunk, ind, ra);
}

void	ft_fill_b(t_begin *begin, t_chunk *chunk)
{
	t_pile	*tmp;
	int		ind;

	tmp = begin->pile_a;
	ind = 0;
//	ft_printf("ICI c'est le debut \n");
//	ft_print_pile(begin->pile_a);
	while (begin->pile_a)
	{
		ft_move_both(begin, chunk, ind);
	//	ft_printf("ft_nb_next_p = %d\n", ft_nb_next_p(begin, chunk, ind));
		ft_next_to_b(begin, chunk, ind);
		begin->moves += ft_push(&begin->pile_a, &begin->pile_b, 1);
		if (!(ft_lstsize(begin->pile_b) % chunk->size))
		{
	//		ft_print_begin(begin);
		//	ft_printf("ICI c'est la taille du chunk \n");
		//	ft_print_pile(begin->pile_a);
			ind++;
			ft_b_clean(begin);
//			ft_print_pile(begin->pile_b);
		}
	}
	ft_b_clean(begin);
	ft_push_all_to_a(begin);
//	ft_printf("ICI c'est la fin \n");
//	ft_print_pile(begin->pile_a);
//	ft_print_begin(begin);
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
				begin->moves += ft_rotate(&begin->pile_b, 2);
		else
		{
			i = ft_lstsize(begin->pile_b) - i;
			if (ft_lstsize(begin->pile_b) > 1)
				while (i--)
					begin->moves += ft_reverse_rotate(&begin->pile_b, 2);
		}
	}
}
