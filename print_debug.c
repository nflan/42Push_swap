/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:45:18 by nflan             #+#    #+#             */
/*   Updated: 2022/02/09 15:49:06 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_chunk(t_chunk *chunk)
{
	t_chunk	*tmp;

	tmp = chunk;
	while (tmp)
	{
		ft_printf("min %d\n", tmp->min);
		ft_printf("max %d\n", tmp->max);
		ft_printf("index %d\n", tmp->index);
		ft_printf("size %d\n", tmp->size);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	ft_print_pile(t_pile *pile)
{
	while (pile)
	{
		ft_printf("%d\n", pile->num);
		pile = pile->next;
	}
	ft_printf("\n");
}

void	ft_print_begin(t_begin *begin)
{
	if (begin)
	{
		ft_printf("pile_a =\n");
		ft_print_pile(begin->pile_a);
		ft_printf("pile_b =\n");
		ft_print_pile(begin->pile_b);
		ft_printf("moves = %d\n", begin->moves);
		ft_printf("bmoves = %d\n", begin->bmoves);
		ft_printf("\n");
	}
}

void	ft_print_roll(t_roll *roll)
{
	ft_printf("roll->ra = %d\n", roll->ra);
	ft_printf("roll->rra = %d\n", roll->rra);
	ft_printf("roll->rb = %d\n", roll->rb);
	ft_printf("roll->rrb = %d\n", roll->rrb);
}
