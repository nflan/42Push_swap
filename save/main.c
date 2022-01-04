#include "push_swap.h"

void	ft_choose_order(t_begin *begin)
{
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
	ft_choose_order(begin);
	ft_print_pile(begin->pile_a);
	ft_print_pile(begin->pile_b);
//	free(pa);
//	while (1){}
	return (0);
}
