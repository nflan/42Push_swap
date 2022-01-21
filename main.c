/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/01/21 13:29:44 by nflan            ###   ########.fr       */
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
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int		pile_is_sort(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next)
	{
		if (tmp->num < tmp->next->num)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	sort_pile(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*begin;
	int		vtmp;

	tmp = *pile;
	begin = *pile;
	while (!pile_is_sort(*pile) && begin)
	{
		while (tmp)
		{
			if (tmp->num > begin->num)
			{
				vtmp = begin->num;
				begin->num = tmp->num;
				tmp->num = vtmp;
			}
			tmp = tmp->next;
		}
		tmp = *pile;
		begin = begin->next;
	}
}

t_chunk	*ft_chunks(t_begin *begin)
{
	static t_chunk	*chunk;
	t_pile			*pile;

	pile = begin->pile_a;
	sort_pile(&pile);
	if (!chunk)
	{
		chunk = ft_calloc(sizeof(t_chunk), 1);
		chunk->min = pile->num;
		while (pile->next)
			pile = pile->next;
		chunk->max = pile->num;
		chunk->index = 1;
		chunk->next = NULL;
		ft_print_chunk(chunk);
	}
	return (chunk);
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
int	main(int ac, char **av)
{
	char	**tab;
	t_begin	*begin;

	begin = NULL;
	tab = NULL;
	begin = ft_calloc(sizeof(t_begin), 1);
	begin->pile_b = NULL;
	if (ac == 1)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	begin->pile_a = ft_fill_pile(tab);
//	ft_sort(begin);
	ft_chunks(begin);
	//	ft_fill_pile_b(begin);
	//	ft_sort(begin, 0);
	//	ft_push_all_to_a(begin);
	//	ft_print_pile(begin->pile_a);
	//	ft_print_pile(begin->pile_b);
	free(begin);
	//	while (1){}
	return (0);
}
