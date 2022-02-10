/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/02/10 12:17:50 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_begin *begin)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin);
}

int		ft_rr_rrr(t_roll *roll)
{
	int	rolling;
	int oui;
	int rrolling;
	int	non;

	if (roll->ra <= roll->rb)
	{
		rolling = roll->ra;
		oui = roll->rb - roll->ra;
	}
	else
	{
		rolling = roll->rb;
		oui = roll->ra - roll->rb;
	}
	if (roll->rra >= roll->rrb)
	{
		rrolling = roll->rra;
		non = roll->rrb - roll->rra;
	}
	else
	{
		rrolling = roll->rrb;
		non = roll->rra - roll->rrb;
	}
	if (rolling + oui <= ((rrolling + non) * -1))// || ((roll->ra + roll->rb) < ((roll->rra + roll->rrb) * - 1)))
		return (rolling);
	else if	(rolling > ((rrolling - non) * -1))// || ((roll->ra + roll->rb) > ((roll->rra + roll->rrb) * - 1)))
		return (rrolling);
	else
		return (0);
}

t_pile	*ft_fill_cpy(t_pile *pile)
{
	t_pile	*begin;
	t_pile	*ptr;
	t_pile	*new;

	begin = pile;
	ptr = NULL;
	new = NULL;
	while (begin)
	{
		ptr = ft_pilenew(begin->num);
		ft_lstadd_back(&new, ptr);
		begin = begin->next;
	}
	return (new);
}

t_begin	*ft_begin_cpy(t_begin *begin, int bmoves)
{
	t_begin	*new;

	new = ft_calloc(sizeof(t_begin), 1);
	new->pile_a = ft_calloc(sizeof(t_pile), 1);
	new->pile_a = ft_fill_cpy(begin->pile_a);
	new->pile_b = ft_calloc(sizeof(t_pile), 1);
	new->pile_b = NULL;
	new->moves = 0;
	//new->moves = ft_lstsize(begin->pile_a);
	new->bmoves = bmoves;
	new->print = 0;
	return (new);
}

int		ft_nb_chunk(t_begin *btmp, int nbsize, int i)
{
	int	nbchunk;

	nbchunk = 0;
	if (ft_lstsize(btmp->pile_a) % i)
		nbchunk = ft_lstsize(btmp->pile_a) / i + 1;
	else
		nbchunk = ft_lstsize(btmp->pile_a) / i;
	if (nbchunk == nbsize)
		return (0);
	else
		return (nbchunk);
}

void	ft_choose_sort(t_begin *begin, t_chunk *chunk)
{
	t_pile	*tmp;
	t_begin	*btmp;
//	t_begin	*tofree;
	int		i;
	int		index;
	int		nb;

	if (ft_lstsize(begin->pile_a) > 239)
		i = 20;
	else
		i = 0;
	nb = 2147483646;
//	ft_print_begin(begin);
	if (ft_lstsize(begin->pile_a) < 10)
		ft_sort(begin);
	else
	{
		tmp = ft_pile_chunk(begin);
		while (i++ < 75 && (ft_lstsize(tmp) - i) > -1)
		{
			btmp = ft_begin_cpy(begin, nb + 1);
			chunk = ft_fill_chunks(tmp, i, 1);
		//	ft_print_chunk(chunk);
			ft_fill_b(btmp, chunk);
		//	ft_print_begin(btmp);
			if (btmp->moves < nb && btmp->moves > 0 && pile_is_sort(btmp->pile_a) && !(btmp->pile_b))
			{
				nb = btmp->moves;
			//	ft_printf("best moves / nb = %i\n", nb);
				index = i;
			//	ft_printf("best index / chunks = %i\n", index);
	//			ft_print_begin(btmp);
			}
		//	ft_printf("nb chunks = %i\n", size);
		//	ft_print_begin(btmp);
//			ft_print_chunk(chunk);
//			ft_printf("moves / nb = %i\n", btmp->moves);
		//	tofree = btmp;
		//	free(tofree);
		}
//		ft_printf("best moves / nb = %i\n", nb);
		begin->bmoves = nb;
		chunk = ft_fill_chunks(tmp, index, 1);
		ft_fill_b(begin, chunk);
//		ft_print_chunk(chunk);
	//	ft_printf("moves begin = %i\n", begin->moves);
	//	ft_print_begin(begin);
	}
}

t_begin *ft_create_begin(t_begin *begin)
{
	begin = ft_calloc(sizeof(t_begin), 1);
	begin->pile_b = ft_calloc(sizeof(t_pile), 1);
	begin->pile_b = NULL;
	begin->moves = 0;
	begin->bmoves = 0;
	begin->print = 1;
	return (begin);
}

int	main(int ac, char **av)
{
	char	**tab;
	t_begin	*begin;
	t_chunk	*chunk;

	begin = NULL;
	tab = NULL;
	chunk = NULL;
	begin = ft_create_begin(begin);
	if (ac < 2)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin->pile_a = ft_fill_pile(tab);
	ft_choose_sort(begin, chunk);
	//	ft_print_pile(begin->pile_a);
	//	ft_print_pile(begin->pile_b);
	//	ft_pileclear(&begin->pile_a);
//	ft_print_begin(begin);
//	ft_print_chunk(chunk);
	free(begin->pile_b);
	free(begin);
	free(chunk);
	//	while (1){}
	return (0);
}
