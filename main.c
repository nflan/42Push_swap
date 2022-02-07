/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:29:49 by nflan             #+#    #+#             */
/*   Updated: 2022/02/04 15:09:23 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_begin(t_begin *begin)
{
	t_begin	*tmp;

	tmp = begin;
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

void	ft_sort(t_begin *begin)
{
	if (ft_lstsize(begin->pile_a) == 2)
		ft_double(begin, 1);
	else if (ft_lstsize(begin->pile_a) == 3)
		ft_triple(begin, 1);
	else
		ft_five(begin);
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
	new->bmoves = bmoves;
	new->print = 0;
	return (new);
}

/*t_begin	*ft_fill_begin(t_begin *begin)
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
  }*/

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
	int		size;

	i = 0;
	nb = 2147483647;
	size = 0;
	if (ft_lstsize(begin->pile_a) < 10)
		ft_sort(begin);
	else
	{
		tmp = ft_pile_chunk(begin);
		while (i++ < 50 && (ft_lstsize(tmp) - i) > -1)
		{
				btmp = ft_begin_cpy(begin, nb - ft_lstsize(begin->pile_a));
		//	if (ft_nb_chunk(btmp, size, i))
		//	{
		//		size = ft_nb_chunk(btmp, size, i);
				//	ft_print_begin(begin);
	//				ft_print_begin(btmp);
				chunk = ft_fill_chunks(tmp, i, 1);
				//		ft_print_chunk(chunk);
				ft_fill_b(btmp, chunk);
				//	ft_print_begin(btmp);
				if (btmp->moves < nb && btmp->moves > 0 && !(btmp->pile_b))
				{
					nb = btmp->moves;
					index = i;
				}
					//	ft_printf("nb chunks = %i\n", size);
	//				ft_print_begin(btmp);
				//		ft_print_chunk(chunk);
						ft_printf("best moves / nb = %i\n", nb);
			//			ft_printf("moves / nb = %i\n", btmp->moves);
						ft_printf("best index / chunks = %i\n", index);
//				tofree = btmp;
//				free(tofree);
	//		}
		}
		begin->bmoves = nb;
		chunk = ft_fill_chunks(tmp, index, 1);
		ft_fill_b(begin, chunk);
		ft_print_chunk(chunk);
		ft_printf("moves begin = %i\n", begin->moves);
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
