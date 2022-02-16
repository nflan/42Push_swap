/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:54:39 by nflan             #+#    #+#             */
/*   Updated: 2022/02/16 16:04:28 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_chunk	*ft_big_sort2(t_begin *begin, t_chunk *chunk, int i, t_global *global)
{
	t_pile	*tmp;
	t_begin	*btmp;
	int		index;
	int		nb;

	nb = 2147483646;
	tmp = ft_pile_chunk(begin, global);
	while (i++ < 55 && (ft_lstsize(tmp) - i) > -1)
	{
		btmp = ft_begin_cpy(begin, nb + 1, global);
		chunk = ft_fill_chunks(tmp, i, 1, global);
		ft_fill_b(btmp, chunk, global, 2);
		if (btmp->moves < nb && btmp->moves > 0 && pile_incr(btmp->pile_a))
		{
			nb = btmp->moves;
			index = i;
		}
		ft_clear_begin(btmp);
		ft_clear_chunk(chunk);
	}
	begin->bmoves = nb;
	chunk = ft_fill_chunks(tmp, index, 1, global);
	ft_pileclear(tmp);
	return (chunk);
}

int	ft_nb_next_p_rra(t_begin *btmp, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		nbtmp;
	int		i;
	int		y;

	tmp = btmp->pile_a;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp && !ft_min_in_max(tmp, chunk, ind))
	{
		i++;
		tmp = tmp->next;
	}
	nbtmp = ft_find_last(tmp, chunk, ind, tmp->num);
	y = ft_find_rra_rrb(tmp, chunk, ind);
	if (i <= y)
		return (tmp->num);
	return (nbtmp);
}

void	ft_move_both_rra(t_begin *btmp, t_chunk *chunk, int ind, t_roll *roll)
{
	int		rolling;
	int		ra;
	int		rb;

	ra = ft_nb_ra_rra(btmp, ft_nb_next_p_rra(btmp, chunk, ind), roll);
	rb = ft_nb_rb_rrb(btmp, ft_nb_next_p_rra(btmp, chunk, ind), roll);
	rolling = ft_rr_rrr(roll);
	if (ra && rb)
	{
		if (rolling > 0 && ra > 0 && btmp->bmoves > btmp->moves
			&& ft_biggest(roll->ra, roll->rb) < (roll->ra - roll->rrb))
			while (btmp->pile_a->num != ft_nb_next_p_rra(btmp, chunk, ind)
				&& rb-- && rolling-- && btmp->bmoves > btmp->moves)
				ft_do_rr_rrr(btmp, 1);
		else if (rolling < 0 && ra < 0 && btmp->bmoves > btmp->moves
			&& ft_biggest(roll->rra, roll->rrb) > (roll->rra - roll->rb))
			while (btmp->pile_a->num != ft_nb_next_p_rra(btmp, chunk, ind)
				&& rb++ && rolling++ && btmp->bmoves > btmp->moves)
				ft_do_rr_rrr(btmp, -1);
	}
	ft_finish_rotate_a(btmp, chunk, ind, ra);
}
