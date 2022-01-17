#include "push_swap.h"

int	ft_swap(t_pile **pile)
{
	t_pile	*elem1;
	t_pile	*elem2;
	int	tmp;

	elem1 = *pile;
	elem2 = elem1->next;
	tmp = elem1->num;
	if (elem1 && elem2)
	{
		elem1->num = elem2->num;;
		elem2->num = tmp;
		return (1);
	}
	return (0);
}

int	ft_push(t_pile **pstart, t_pile **pend)
{
	t_pile	*tmpstart;
	t_pile	*tmpend;
	int		nbr;

	tmpstart = *pstart;
	tmpend = *pend;
	nbr = 0;
	if (*pstart)
	{
		nbr = tmpstart->num;
		tmpend = ft_pilenew(nbr);
		tmpend->next = *pend;
		*pend = tmpend;
		*pstart = tmpstart->next;
		return (1);
	}
	return (0);
}

int	ft_reverse_rotate(t_pile **pstart)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *pstart;
	tmp2 = *pstart;
	if (*pstart)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = tmp2;
		*pstart = tmp->next;
		tmp->next = NULL;
		return (1);
	}
	return (0);
}

int	ft_rotate(t_pile **pstart)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *pstart;
	tmp2 = *pstart;
	*pstart = tmp->next;
	if (*pstart)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tmp2;
		tmp2->next = NULL;
		return (1);
	}
	return (0);
}
