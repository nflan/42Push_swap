#include "push_swap.h"

int	ft_swap(i_list *elem1, i_list *elem2)
{
	int	tmp;

	tmp = elem1->num;
	if (elem1 && elem2)
	{
		elem1->num = elem2->num;;
		elem2->num = tmp;
		return (1);
	}
	return (0);
}

int	ft_push(i_list *pstart, i_list *pend, int i)
{
	i_list		*tmp;

	tmp = NULL;
	if (pstart)
	{
		if (i == 0 && pend->num == -1)
		{
			*pend = *pstart;
			pend->next = NULL;
		}
		else
		{
			tmp = ft_calloc(sizeof(i_list), 1);
			*tmp = *pend;
			*pend = *pstart;
			pend->next = tmp;
		}
		*pstart = *pstart->next;
		return (1);
	}
	return (0);
}

int	ft_rotate(i_list *pstart)
{
	i_list	*tmp;
	i_list	*save;

	tmp = NULL;
	save = NULL;
	if (pstart)
	{
		tmp = ft_calloc(sizeof(i_list), 1);
		save = ft_calloc(sizeof(i_list), 1);
		*tmp = *pstart;
		save->num = pstart->num;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = save;
		*pstart = *pstart->next;
		return (1);
	}
	return (0);
}

int	ft_reverse_rotate(i_list *pstart)
{
	i_list	*tmp;
	i_list	*save;

	tmp = NULL;
	save = NULL;
	if (pstart)
	{
		tmp = ft_calloc(sizeof(i_list), 1);
		save = ft_calloc(sizeof(i_list), 1);
		*save = *pstart;
		ft_printf("save->num = %i \n", save->num);
		save = save->next;
		ft_printf("save->num = %i \n", save->num);
		while (pstart->next)
		{
			tmp = pstart->next;
			if (!tmp->next)
			{
				ft_printf("pstart->num = %i \n", pstart->num);
				pstart->next = NULL;
				ft_printf("tmp->num = %i \n", tmp->num);
				tmp->next = save;
			}
			else
				pstart = pstart->next;
		}
		*pstart = *tmp;
		ft_printf("pstart->num = %i \n", pstart->num);
		pstart = pstart->next;
		ft_printf("pstart->num = %i \n", pstart->num);
		pstart = pstart->next;
		ft_printf("pstart->num = %i \n", pstart->num);
		return (1);
	}
	return (0);
}

//	ft_printf("OK\n\n");
void	ft_choose_order(i_list *pa, i_list *pb)
{
	pb = ft_calloc(sizeof(i_list), 1);
	pb->num = -1;
	if (ft_swap(pa, pa->next))
		ft_printf("sa\n");
	/*	if (ft_push(pa, pb))
		{
		ft_print_pile(pb);
		ft_printf("pb\n");
		}*/
/*	ft_push(pa, pb, ft_lstsize(pb));
	ft_printf("pb\n");
	ft_push(pa, pb, ft_lstsize(pb));
	ft_printf("pb\n");
	ft_push(pa, pb, ft_lstsize(pb));
	ft_printf("pb\n");
	ft_rotate(pa);
	ft_printf("ra\n");
	ft_rotate(pb);
	ft_printf("rb\n");
	ft_reverse_rotate(pa);
	ft_printf("rra\n");
	ft_reverse_rotate(pb);
	ft_printf("rrb\n");
*/	//	ft_print_pile(pb);
}

int	main(int ac, char **av)
{
	char	**tab;
	i_list	*pa;
	i_list	*pb;

	pa = NULL;
	pb = NULL;
	tab = NULL;
	if (ac == 1)
		return (0);
	tab = ft_fill_argv(tab, ac, av);
	ft_check_tab(tab);
	pa = ft_fill_pile(tab, pa);
	ft_choose_order(pa, pb);
	ft_print_pile(pa);
	free(pa);
	//	while (1){}
	return (0);
}