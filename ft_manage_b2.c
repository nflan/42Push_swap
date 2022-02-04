/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:41:17 by nflan             #+#    #+#             */
/*   Updated: 2022/02/04 14:39:22 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_next_to_b(t_begin *btmp, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		rb;

	tmp = btmp->pile_b;
	rb = ft_nb_rb(btmp, ft_nb_next_p(btmp, chunk, ind));
	if (tmp && rb)
	{
		if (rb <= ft_lstsize(btmp->pile_b) / 2)
			while (rb--)
				btmp->moves += ft_rotate(btmp, &btmp->pile_b, 2);
		else
		{
			rb = ft_lstsize(btmp->pile_b) - rb;
			if (ft_lstsize(btmp->pile_b) > 1)
				while (rb--)
					btmp->moves += ft_reverse_rotate(btmp, &btmp->pile_b, 2);
		}
	}
}

void	ft_finish_rotate_a(t_begin *btmp, t_chunk *chunk, int ind, int ra)
{
	if (ra > 0)
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind))
			btmp->moves += ft_rotate(btmp, &btmp->pile_a, 1);
	else if (ra < 0)
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind))
			btmp->moves += ft_reverse_rotate(btmp, &btmp->pile_a, 1);
}

void	ft_move_both(t_begin *btmp, t_chunk *chunk, int ind)
{
	int	ra;
	int	rb;

	ra = ft_nb_ra_rra(btmp, ft_nb_next_p(btmp, chunk, ind));
	rb = ft_nb_rb(btmp, ft_nb_next_p(btmp, chunk, ind));
	if (ra > 0 && rb && rb <= ft_lstsize(btmp->pile_b) / 2)
	{
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && rb--)
		{
			btmp->moves += ft_rotate(btmp, &btmp->pile_a, 3);
			ft_rotate(btmp, &btmp->pile_b, 0);
		}
	}
	else if (ra < 0 && rb && rb > ft_lstsize(btmp->pile_b) / 2)
	{
		rb = ft_lstsize(btmp->pile_b) - rb;
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && rb--)
		{
			btmp->moves += ft_reverse_rotate(btmp, &btmp->pile_a, 3);
			ft_reverse_rotate(btmp, &btmp->pile_b, 0);
		}
	}
	ft_finish_rotate_a(btmp, chunk, ind, ra);
}

void	ft_fill_b(t_begin *btmp, t_chunk *chunk)
{
	int		ind;

	ind = 1;
//	ft_printf("ICI c'est le debut \n");
//	ft_print_pile(btmp->pile_a);
	while (btmp->pile_a)
	{
		ft_move_both(btmp, chunk, ind);
	//	ft_printf("ft_nb_next_p = %d\n", ft_nb_next_p(btmp, chunk, ind));
		ft_next_to_b(btmp, chunk, ind);
		btmp->moves += ft_push(btmp, &btmp->pile_a, &btmp->pile_b, 1);
		if (!(ft_lstsize(btmp->pile_b) % chunk->size))
		{
	//		ft_print_btmp(btmp);
		//	ft_printf("ICI c'est la taille du chunk \n");
		//	ft_print_pile(btmp->pile_a);
			ind++;
			ft_b_clean(btmp);
//			ft_print_pile(btmp->pile_b);
		}
	}
	ft_b_clean(btmp);
	ft_push_all_to_a(btmp);
//	ft_print_btmp(btmp);
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
				begin->moves += ft_rotate(begin, &begin->pile_b, 2);
		else
		{
			i = ft_lstsize(begin->pile_b) - i;
			if (ft_lstsize(begin->pile_b) > 1)
				while (i--)
					begin->moves += ft_reverse_rotate(begin, &begin->pile_b, 2);
		}
	}
}
