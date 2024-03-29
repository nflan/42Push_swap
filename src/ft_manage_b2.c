/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:41:17 by nflan             #+#    #+#             */
/*   Updated: 2022/02/16 15:56:51 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_next_to_b(t_begin *btmp, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		rb;

	tmp = btmp->pile_b;
	rb = ft_nb_rb_rrb_bis(btmp, ft_nb_next_p(btmp, chunk, ind));
	if (tmp && rb)
	{
		if (rb > 0)
			while (rb--)
				btmp->moves += ft_rotate(btmp, &btmp->pile_b, 2);
		else
		{
			if (ft_lstsize(btmp->pile_b) > 1)
				while (rb++)
					btmp->moves += ft_reverse_rotate(btmp, &btmp->pile_b, 2);
		}
	}
}

void	ft_do_rr_rrr(t_begin *btmp, int rr_rrr)
{
	if (rr_rrr == 1)
	{
		btmp->moves += ft_rotate(btmp, &btmp->pile_a, 3);
		ft_rotate(btmp, &btmp->pile_b, 0);
	}
	else
	{
		btmp->moves += ft_reverse_rotate(btmp, &btmp->pile_a, 3);
		ft_reverse_rotate(btmp, &btmp->pile_b, 0);
	}
}

void	ft_move_both(t_begin *btmp, t_chunk *chunk, int ind, t_roll *roll)
{
	int		rolling;
	int		ra;
	int		rb;

	ra = ft_nb_ra_rra(btmp, ft_nb_next_p(btmp, chunk, ind), roll);
	rb = ft_nb_rb_rrb(btmp, ft_nb_next_p(btmp, chunk, ind), roll);
	rolling = ft_rr_rrr(roll);
	if (ra && rb)
	{
		if (rolling > 0 && ra > 0 && btmp->bmoves > btmp->moves
			&& ft_biggest(roll->ra, roll->rb) < (roll->ra - roll->rrb))
			while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && rb--
				&& rolling-- && btmp->bmoves > btmp->moves)
				ft_do_rr_rrr(btmp, 1);
		else if (rolling < 0 && ra < 0 && btmp->bmoves > btmp->moves
			&& ft_biggest(roll->rra, roll->rrb) > (roll->rra - roll->rb))
			while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && rb++
				&& rolling++ && btmp->bmoves > btmp->moves)
				ft_do_rr_rrr(btmp, -1);
	}
	ft_finish_rotate_a(btmp, chunk, ind, ra);
}

void	ft_fill_b(t_begin *btmp, t_chunk *chunk, t_global *global, int r)
{
	t_roll	*roll;
	int		ind;

	ind = 1;
	while (btmp->pile_a && btmp->bmoves > btmp->moves)
	{
		roll = ft_calloc(sizeof(t_roll), 1);
		if (!roll)
			ft_exit(global);
		if (r == 1)
			ft_move_both(btmp, chunk, ind, roll);
		else
			ft_move_both_rra(btmp, chunk, ind, roll);
		ft_next_to_b(btmp, chunk, ind);
		free(roll);
		btmp->moves += ft_push(btmp, 1, global);
		if (!(ft_lstsize(btmp->pile_b) % chunk->size))
			ind++;
	}
	if (btmp->bmoves > btmp->moves)
	{
		ft_b_clean(btmp);
		ft_push_all_to_a(btmp, global);
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
			while (i-- && begin->bmoves > begin->moves)
				begin->moves += ft_rotate(begin, &begin->pile_b, 2);
		else
		{
			i = ft_lstsize(begin->pile_b) - i;
			if (ft_lstsize(begin->pile_b) > 1)
				while (i-- && begin->bmoves > begin->moves)
					begin->moves += ft_reverse_rotate(begin, &begin->pile_b, 2);
		}
	}
}
