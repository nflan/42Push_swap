/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:50:46 by nflan             #+#    #+#             */
/*   Updated: 2022/02/02 17:51:18 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nb_next_p(t_begin *begin, t_chunk *chunk, int ind)
{
	t_pile	*tmp;
	int		nbtmp;
	int		nbr;
	int		i;
	int		y;

	tmp = begin->pile_a;
	//ft_print_pile(begin->pile_a);
	i = 0;
	y = 0;
	if (!tmp)
		return (0);
	if (ft_lstsize(tmp) == 1)
		return (tmp->num);
	while (++i && tmp && !ft_min_in_max(tmp, chunk, ind))
		tmp = tmp->next;
//	ft_printf("Index = %i\n", ind);
//	ft_printf("I = %i\n", i);
//	ft_printf("size A = %i\n", ft_lstsize(begin->pile_a));
	nbr = tmp->num;
	nbtmp = nbr;
	if (tmp)
	{
		while (y++ && tmp)
		{
			if (tmp && ft_min_in_max(tmp, chunk, ind))
			{
				nbtmp = tmp->num;
				y = 1;
			}
			tmp = tmp->next;
		}
	}
//	ft_printf("nbr = %d & nbtmp = %d & y = %d\n", nbr, nbtmp, y);
//	ft_print_pile(begin->pile_a);
	if (i <= y)
		return (nbr);
	return (nbtmp);
}

int	ft_nb_ra_rra(t_begin *begin, int nbr)
{
	t_pile	*tmp;
	int		ra;
	int		rra;

	tmp = begin->pile_a;
	ra = 0;
	rra = -1;
	if (!tmp)
		return (0);
	while (tmp && tmp->num != nbr)
	{
		ra++;
		tmp = tmp->next;
	}
	while (tmp && tmp->next)
	{
		rra--;
		tmp = tmp->next;
	}
//	ft_printf("\nrra = %i\n", rra);
	if (ra <= (rra * -1))
		return (ra);
	else
		return (rra);
}
