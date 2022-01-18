#include "push_swap.h"

/*
   if (ft_swap(&begin->pile_a))
   ft_printf("sa\n");
   ft_push(&begin->pile_a, &begin->pile_b);
   ft_printf("pb\n");
   ft_push(&begin->pile_a, &begin->pile_b);
   ft_printf("pb\n");
   ft_push(&begin->pile_a, &begin->pile_b);
   ft_printf("pb\n");
   ft_rotate(&begin->pile_a);
   ft_printf("ra\n");
   ft_rotate(&begin->pile_b);
   ft_printf("rb\n");
   ft_reverse_rotate(&begin->pile_a);
   ft_printf("rra\n");
   ft_reverse_rotate(&begin->pile_b);
   ft_printf("rrb\n");
   if (ft_swap(&begin->pile_a))
   ft_printf("sa\n");
   ft_push(&begin->pile_b, &begin->pile_a);
   ft_printf("pa\n");
   ft_push(&begin->pile_b, &begin->pile_a);
   ft_printf("pa\n");
   ft_push(&begin->pile_b, &begin->pile_a);
   ft_printf("pa\n");
   */

int		ft_is_sort(t_begin *begin)
{
	t_pile	*tmp;
	int		b;

	b = 0;
	tmp = begin->pile_a;
	if (tmp)
	{
		while (tmp->next && tmp->num < tmp->next->num)
			tmp = tmp->next;
		if (!tmp->next)
			b = 2;
	}
	tmp = begin->pile_b;
	if (tmp)
	{
		while (tmp->next && tmp->num > tmp->next->num)
			tmp = tmp->next;
		if (!tmp->next)
			b++;
	}
	else
		b++;
	return (b);
}

void	ft_push_all_to_a(t_begin *begin)
{
	while (begin->pile_b)
		if (ft_push(&begin->pile_b, &begin->pile_a))
			ft_printf("pa\n");
}

int		ft_median(t_begin *begin)
{
	t_pile	*tmp;
	int		psize;
	int		pnbr;

	tmp = begin->pile_a;
	psize = ft_lstsize(begin->pile_a);
	pnbr = 0;
	if (tmp)
	{
		while (tmp)
		{
			pnbr+= tmp->num;
			tmp = tmp->next;
		}
		pnbr /= psize;
		return (pnbr);
	}
	return (0);
}
/*
void	ft_sort(t_begin *begin)
{
	t_pile	*tmp;
	int		nbr;
	int		count;
	int		n;

	tmp = begin->pile_a;
	nbr = 0;
	n = 0;
	count = 0;
	if (tmp)
	{
		nbr = tmp->num;
		while (tmp)
		{
			if (nbr > tmp->num)
			{
				nbr = tmp->num;
				if (count == 1)
				{
					if (ft_swap(&begin->pile_a))
						ft_printf("sa\n");
				}
				else
					n = count;
				count = 0;
				tmp = begin->pile_a;
			}
			else
			{
				count++;
				tmp = tmp->next;
			}
		}
		if (ft_lstsize(begin->pile_a) / 2 >= n)
		{
			while (n--)
			{
				ft_rotate(&begin->pile_a);
				ft_printf("ra\n");
			}
		}
		else
		{
			n = ft_lstsize(begin->pile_a) - n;
			while (n--)
			{
				ft_reverse_rotate(&begin->pile_a);
				ft_printf("rra\n");
			}
		}
		if (ft_is_sort(begin) != 3)
			if (ft_push(&begin->pile_a, &begin->pile_b))
				ft_printf("pb\n");
	}
}
*/

int		ft_need_rotate(t_begin *begin, int pnb)
{
	t_pile	*tmpa;
	t_pile	*tmpb;

	tmpa = begin->pile_a;
	tmpb = begin->pile_b;
	if (tmpa && tmpb)
	{
		while (tmpa->next)
			tmpa = tmpa->next;
		while (tmpb->next)
			tmpb = tmpb->next;
		if (pnb == 1)
			if (begin->pile_a->next->num < tmpa->num)
				return (1);
		if (pnb == 2)
			if (begin->pile_b->next->num > tmpb->num)
				return (1);
		if (pnb == 3)
			if (begin->pile_a->next->num < tmpa->num && begin->pile_b->next->num > tmpb->num)
				return (1);
	}
	return (0);
}

int		ft_need_reverse_rotate(t_begin *begin, int pnb)
{
	t_pile	*tmpa;
	t_pile	*tmpb;

	tmpa = begin->pile_a;
	tmpb = begin->pile_b;
	if (tmpa && tmpb)
	{
		while (tmpa->next)
			tmpa = tmpa->next;
		while (tmpb->next)
			tmpb = tmpb->next;
		if (pnb == 1)
			if (begin->pile_a->next->num < tmpa->num)
				return (1);
		if (pnb == 2)
			if (begin->pile_b->next->num < tmpb->num)
				return (1);
		if (pnb == 3)
			if (begin->pile_a->next->num < tmpa->num && begin->pile_b->next->num > tmpb->num)
				return (1);
	}
	return (0);
}


void	ft_call_swap(t_begin *begin, int nb)
{
	if (nb == 1)
	{
		ft_swap(&begin->pile_a);
		ft_printf("sa\n");
	}
	if (nb == 2)
	{
		ft_swap(&begin->pile_b);
		ft_printf("sb\n");
	}
	if (nb == 3)
	{
		ft_swap(&begin->pile_a);
		ft_swap(&begin->pile_b);
		ft_printf("ss\n");
	}
}

int		ft_need_swap(t_begin *begin, int nb)
{
	if (nb == 1)
		if (!ft_need_rotate(begin, 1))// && !ft_need_reverse_rotate(begin, 1))
			return (1);
	if (nb == 2)
		if (!ft_need_rotate(begin, 2))// && !ft_need_reverse_rotate(begin, 2))
			return (1);
	if (nb == 3)
		if (!ft_need_rotate(begin, 3))// && !ft_need_reverse_rotate(begin, 3))
			return (1);
	return (0);
}

void	ft_do_swap(t_begin *begin)
{
	t_pile	*tmpa;
	t_pile	*tmpb;
	int		nb;

	nb = 0;
	tmpa = begin->pile_a;
	tmpb = begin->pile_b;
	if (tmpa && tmpb)
	{
		if (tmpa->num > tmpa->next->num && ft_need_swap(begin, 1))
			nb = 1;
		if (tmpb->num < tmpb->next->num && ft_need_swap(begin, 2))
			nb = 2;
		if (tmpa->num > tmpa->next->num && tmpb->num < tmpb->next->num && ft_need_swap(begin, 3))
			nb = 3;
	}
	if (nb)
		ft_call_swap(begin, nb);
}

void	ft_call_rotate(t_begin *begin, int nb)
{
	if (nb == 1)
	{
		ft_rotate(&begin->pile_a);
		ft_printf("ra\n");
	}
	else if (nb == 2)
	{
		ft_rotate(&begin->pile_b);
		ft_printf("rb\n");
	}
	else
	{
		ft_rotate(&begin->pile_a);
		ft_rotate(&begin->pile_b);
		ft_printf("rr\n");
	}
}

void	ft_do_rotate(t_begin *begin)
{
	t_pile	*tmpa;
	t_pile	*tmpb;
	int		nb;

	nb = 0;
	tmpa = begin->pile_a;
	tmpb = begin->pile_b;
	if (tmpa && tmpb)
	{
		while (tmpa->next)
			tmpa = tmpa->next;
		while (tmpb->next)
			tmpb = tmpb->next;
//		ft_printf("begin a = %i\n", begin->pile_a->num);
//		ft_printf("tmpa = %i\n", tmpa->num);
//		ft_printf("begin b = %i\n", begin->pile_b->num);
//		ft_printf("tmpb = %i\n", tmpb->num);
		if (begin->pile_a->num > tmpa->num && ft_need_rotate(begin, 1))
			nb = 1;
		if (begin->pile_b->num < tmpb->num && ft_need_rotate(begin, 2))
			nb = 2;
		if (begin->pile_a->num > tmpa->num && begin->pile_b->num < tmpb->num && ft_need_rotate(begin, 3))
			nb = 3;
	}
//	ft_printf("nb %i\n", nb);
	if (nb)
		ft_call_rotate(begin, nb);
}

void	ft_call_reverse_rotate(t_begin *begin, int nb)
{
	if (nb == 1)
	{
		ft_reverse_rotate(&begin->pile_a);
		ft_printf("rra\n");
	}
	else if (nb == 2)
	{
		ft_reverse_rotate(&begin->pile_b);
		ft_printf("rrb\n");
	}
	else
	{
		ft_reverse_rotate(&begin->pile_a);
		ft_reverse_rotate(&begin->pile_b);
		ft_printf("rrr\n");
	}
}

void	ft_do_reverse_rotate(t_begin *begin)
{
	t_pile	*tmpa;
	t_pile	*tmpb;
	int		nb;

	nb = 0;
	tmpa = begin->pile_a;
	tmpb = begin->pile_b;
	if (tmpa && tmpb)
	{
		while (tmpa->next)
			tmpa = tmpa->next;
		while (tmpb->next)
			tmpb = tmpb->next;
		if (begin->pile_a->num > tmpa->num && ft_need_reverse_rotate(begin, 1))
			nb = 1;
		if (begin->pile_b->num < tmpb->num && ft_need_reverse_rotate(begin, 2))
			nb = 2;
		if (begin->pile_a->num > tmpa->num && begin->pile_b->num < tmpb->num && ft_need_reverse_rotate(begin, 3))
			nb = 3;
	}
	if (nb)
		ft_call_reverse_rotate(begin, nb);
}

void	ft_other_sort(t_begin *begin)
{
	t_pile	*tmp;
	int		median;
	int		mid;

	tmp = begin->pile_a;
	median = ft_median(begin);
	mid = ft_lstsize(begin->pile_a) / 2;
	if (tmp)
	{
		while (ft_lstsize(begin->pile_a) > mid)
		{
			while (begin->pile_a->num > median)
			{
				ft_rotate(&begin->pile_a);
				ft_printf("ra\n");
			}
			ft_push(&begin->pile_a, &begin->pile_b);
			ft_printf("pb\n");
		}
	}
	while (ft_is_sort(begin) != 3)
	{
		ft_do_rotate(begin);
		ft_do_swap(begin);
		ft_do_reverse_rotate(begin);
	}
}

void	ft_choose_order(t_begin *begin)
{
	while (ft_is_sort(begin) != 3)
	{
	//	ft_sort(begin);
	}
//	ft_push_all_to_a(begin);
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
//	ft_choose_order(begin);
	ft_other_sort(begin);
	ft_push_all_to_a(begin);
	ft_print_pile(begin->pile_a);
//	ft_print_pile(begin->pile_b);
	//	free(pa);
	//	while (1){}
	return (0);
}
