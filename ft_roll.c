/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:01:01 by nflan             #+#    #+#             */
/*   Updated: 2022/02/09 16:01:25 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_roll_a(t_roll *roll, int ra, int rra)
{
	roll->ra = ra;
	roll->rra = rra;
}

void	ft_fill_roll_b(t_roll *roll, int rb, int rrb)
{
	roll->rb = rb;
	roll->rrb = rrb;
}
