/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:41:17 by nflan             #+#    #+#             */
/*   Updated: 2022/02/08 17:34:21 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_finish_rotate_a(t_begin *btmp, t_chunk *chunk, int ind, int ra)
{
	if (ra > 0 && btmp->bmoves > btmp->moves)
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && btmp->bmoves > btmp->moves)
			btmp->moves += ft_rotate(btmp, &btmp->pile_a, 1);
	else if (ra < 0 && btmp->bmoves > btmp->moves)
		while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && btmp->bmoves > btmp->moves)
			btmp->moves += ft_reverse_rotate(btmp, &btmp->pile_a, 1);
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

void	ft_print_roll(t_roll *roll)
{
	ft_printf("roll->ra = %d\n", roll->ra);
	ft_printf("roll->rra = %d\n", roll->rra);
	ft_printf("roll->rb = %d\n", roll->rb);
	ft_printf("roll->rrb = %d\n", roll->rrb);
}

void	ft_move_both(t_begin *btmp, t_chunk *chunk, int ind)
{
	t_roll	*roll;
	int		rolling;
	int		ra;
	int		rb;

	roll = ft_calloc(sizeof(roll), 1);
	ra = ft_nb_ra_rra(btmp, ft_nb_next_p(btmp, chunk, ind), roll);
	rb = ft_nb_rb_rrb(btmp, ft_nb_next_p(btmp, chunk, ind), roll);
	rolling = ft_rr_rrr(roll);
//	ft_print_roll(roll);
//	ft_printf("%d\n", rolling);
	if (ra && rb)
	{
	//	if (ra > 0 && rb > 0 && btmp->bmoves > btmp->moves)
		if (rolling > 0 && ra > 0 && btmp->bmoves > btmp->moves)
			while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && rb-- && btmp->bmoves > btmp->moves)
				ft_do_rr_rrr(btmp, 1);
	//	else if (ra < 0 && rb < 0 && btmp->bmoves > btmp->moves)
		else if (rolling < 0 && ra < 0 && btmp->bmoves > btmp->moves)
			while (btmp->pile_a->num != ft_nb_next_p(btmp, chunk, ind) && rb++ && btmp->bmoves > btmp->moves)
				ft_do_rr_rrr(btmp, -1);
	}
	ft_finish_rotate_a(btmp, chunk, ind, ra);
	free(roll);
}

void	ft_fill_b(t_begin *btmp, t_chunk *chunk)
{
	int		ind;

	ind = 1;
	while (btmp->pile_a && btmp->bmoves > btmp->moves)
	{
		ft_move_both(btmp, chunk, ind);
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
	if (btmp->bmoves > btmp->moves)
	{
		ft_b_clean(btmp);
		ft_push_all_to_a(btmp);
	}
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
