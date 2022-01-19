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
			if (begin->pile_a->next->num > tmpa->num)
				return (1);
		if (pnb == 2)
			if (begin->pile_b->next->num < tmpb->num)
				return (1);
		if (pnb == 3)
			if (begin->pile_a->next->num > tmpa->num && begin->pile_b->next->num < tmpb->num)
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
			if (begin->pile_b->next->num > tmpb->num)
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
		if (!ft_need_rotate(begin, nb) && !ft_need_reverse_rotate(begin, nb))
			return (1);
	if (nb == 2)
		if (!ft_need_rotate(begin, nb) && !ft_need_reverse_rotate(begin, nb))
			return (1);
	if (nb == 3)
		if (!ft_need_rotate(begin, nb) && !ft_need_reverse_rotate(begin, nb))
			return (1);
	return (0);
}

int	ft_do_swap(t_begin *begin)
{
	t_pile	*tmpa;
	t_pile	*tmpb;
	int		nb;

	nb = 0;
	tmpa = begin->pile_a;
	tmpb = begin->pile_b;
	if (tmpa && tmpb)
	{
		if (ft_need_swap(begin, 1) && ft_is_sort(begin) != 2)
			nb = 1;
		if (ft_need_swap(begin, 2) && ft_is_sort(begin) != 1)
			nb = 2;
		if (ft_need_swap(begin, 3) && !ft_is_sort(begin))
			nb = 3;
	}
	if (nb)
		ft_call_swap(begin, nb);
	return (nb);
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

int	ft_do_rotate(t_begin *begin)
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
		if (begin->pile_a->num > tmpa->num && ft_need_rotate(begin, 1) && ft_is_sort(begin) != 2)
			nb = 1;
		if (begin->pile_b->num < tmpb->num && ft_need_rotate(begin, 2) && ft_is_sort(begin) != 1)
			nb = 2;
		if (begin->pile_a->num > tmpa->num && begin->pile_b->num < tmpb->num && ft_need_rotate(begin, 3) && ft_is_sort(begin) != 3)
			nb = 3;
	}
//	ft_printf("nb %i\n", nb);
	if (nb)
		ft_call_rotate(begin, nb);
	return (nb);
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

int	ft_do_reverse_rotate(t_begin *begin)
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
		if (begin->pile_a->num > tmpa->num && ft_need_reverse_rotate(begin, 1) && ft_is_sort(begin) != 2)
			nb = 1;
		if (begin->pile_b->num < tmpb->num && ft_need_reverse_rotate(begin, 2) && ft_is_sort(begin) != 1)
			nb = 2;
		if (begin->pile_a->num > tmpa->num && begin->pile_b->num < tmpb->num && ft_need_reverse_rotate(begin, 3) && ft_is_sort(begin) != 3)
			nb = 3;
	}
	if (nb)
		ft_call_reverse_rotate(begin, nb);
	return (nb);
}

int	ft_p_max(t_pile **pile)
{
	t_pile	*tmp;
	int		max;

	tmp = *pile;
	max = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (max < tmp->num)
				max = tmp->num;
			tmp = tmp->next;
		}
	}
	ft_printf("max = %d\n", max);
	return (max);
}

void	ft_other_sort(t_begin *begin)
{
	t_pile	*tmp;
	int		median;
	int		mid;

	tmp = begin->pile_a;
	median = ft_is_median(begin);
	ft_printf("median = %d\n", median);
	mid = ft_lstsize(begin->pile_a) / 2;
	if (tmp && ft_is_sort(begin) != 3)
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
		while (ft_is_sort(begin) != 3)
		{
			if (ft_do_rotate(begin))
			{}
			else if (ft_do_swap(begin))
			{}
			else if (ft_do_reverse_rotate(begin))
			{}
			ft_printf("begin->pile_b->num = %d\n", begin->pile_b->num);
			if (ft_is_sort(begin) == 2 && begin->pile_b->num == ft_p_max(&begin->pile_b))
			{
				ft_push(&begin->pile_b, &begin->pile_a);
				ft_printf("pa\n");
			}
		}
	}
}

/*void	ft_choose_order(t_begin *begin)
{
	while (ft_is_sort(begin) != 3)
	{
	//	ft_sort(begin);
	}
//	ft_push_all_to_a(begin);
}*/
