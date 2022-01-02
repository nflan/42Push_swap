#include "push_swap.h"

int	ft_check_double(char **tab, int check)
{
	int	i;
	int	k;

	i = -1;
	while (tab[++i] && check)
	{
		k = i;
		while (tab[++k] && check)
			if (!strcmp(tab[i], tab[k]))
				check = 0;
	}
	return (check);
}

int	ft_check_tab(char **tab)
{
	int	i;
	int j;
	int	check;

	check = 1;
	i = -1;
	while (tab[++i] && check)
	{
		j = -1;
		if ((ft_strlen(tab[i]) > 9 && tab[i][9] > 55) || ft_strlen(tab[i]) > 10)
			check = 0;
		while (tab[i][++j] && check)
			if (!ft_isdigit(tab[i][j]))
				check = 0;
	}
	check = ft_check_double(tab, check);
	if (check)
		return (1);
	ft_putstr_fd("Error\n", 2);
	exit (EXIT_FAILURE);
}

i_list	*ft_fill_pile(char **tab, i_list *pa)
{
	i_list	*ptr;
	int		i;

	i = -1;
	ptr = NULL;
	while (tab[++i])
	{}
	while (i--)
	{
		ptr = ft_calloc(sizeof(i_list), 1);
		ptr->num = ft_atoi(tab[i]);
//		ft_printf("tab[%i] = %i\n", i, ptr->num);
		ptr->next = pa;
		pa = ptr;
		free(tab[i]);
	}
	return (pa);
}

void ft_print_pile(i_list *pile)
{

//	ft_printf("%d\n", pile->num);
	ft_printf("\n");
	while (pile)
	{
		ft_printf("%d\n", pile->num);
        pile = pile->next;
	}
	ft_printf("\n");
}

char	**ft_fill_argv(char **tab, int ac, char **av)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	if (ac == 2)
		tab = ft_split(av[1], ' ');
	else
	{
		tab = ft_calloc(sizeof(char *), ac);
		if (!tab)
			return (0);
		while (av[++i])
		{
			k = -1;
			tab[++j] = ft_calloc(sizeof(char), ft_strlen(av[i]) + 1);
			if (!tab[j])
				return (0);
			while (av[i][++k])
				tab[j][k] = av[i][k];
		}
	}
	return (tab);
}
