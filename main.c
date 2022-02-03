/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/02/03 18:05:56 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_begin(t_begin *begin)
{
	t_begin	*tmp;

	tmp = begin;
	int i = 3;
	if (begin)
	{
		while (i--)
		{
			ft_printf("pile_a =\n");
			ft_print_pile(begin->pile_a);
			ft_printf("pile_b =\n");
			ft_print_pile(begin->pile_b);
			ft_printf("moves = %d\n", begin->moves);
			begin = begin->next;
		}
		ft_printf("\n");
	}
}

void	ft_sort(t_begin *begin)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin);
}

t_begin	*ft_beginnew(t_begin *begin)
{
	t_begin	*new;
		
	new = ft_calloc(sizeof(t_begin), 1);
	new->pile_a = begin->pile_a;
	new->pile_b = begin->pile_b;
	new->moves = begin->moves;
	new->next = NULL;
	return (new);
}

t_begin	*ft_fill_begin(t_begin *begin)
{
	t_begin	*tmp;
	int		i;

	tmp = begin;
	i = 20;
	while (i--)
	{
		begin = ft_beginnew(begin);
		begin->next = tmp;
		tmp = begin;
	}
	return (begin);
}

void	ft_choose_sort(t_begin *begin, t_chunk *chunk)
{
	t_pile	*tmp;
	t_begin	*btmp;
	int		i;
	int		index;
	int		nb;
	int		size;

	i = 0;
	nb = 0;
	if (ft_lstsize(begin->pile_a) < 10)
		ft_sort(begin);
	else
	{
		tmp = ft_pile_chunk(begin);
		begin = ft_fill_begin(begin);
		btmp = begin;
		while (i++ < 20 && (ft_lstsize(tmp) - i) > 1)
		{
			if (ft_lstsize(tmp) % i > 0)
				size = ft_lstsize(tmp) / i + 1;
			else
				size = ft_lstsize(tmp);
			chunk = ft_fill_chunks(tmp, size, 0);
	//		ft_print_chunk(chunk);
			ft_fill_b(begin, chunk);
			ft_printf("JE SUIS SORTI\n");
			ft_print_begin(btmp);
			if (begin->moves < nb || nb == 0)
			{
				nb = begin->moves;
				index = i;
			}
			begin = begin->next;
		}
		//ft_print_chunk(chunk);
	}
}

t_begin *ft_create_begin(t_begin *begin)
{
	begin = ft_calloc(sizeof(t_begin), 1);
	begin->moves = 0;
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
	begin->pile_b = ft_calloc(sizeof(t_pile), 1);
	begin->pile_b = NULL;
	if (ac < 3)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin->pile_a = ft_fill_pile(tab);
	ft_choose_sort(begin, chunk);
//	ft_print_pile(begin->pile_a);
//	ft_print_pile(begin->pile_b);
//	ft_pileclear(&begin->pile_a);
	free(begin->pile_b);
	free(begin);
	free(chunk);
	//	while (1){}
	return (0);
}
