#include "push_swap.h"

t_pile	*ft_fill_pile(char **tab)
{
	t_pile	*pile;
	t_pile	*ptr;
	int		i;
	int		nbr;

	pile = NULL;
	ptr = NULL;
	i = ft_count_line(tab);
	while (i--)
	{
		nbr = ft_atoi(tab[i]);
		ptr = ft_pilenew(nbr);
		ptr->next = pile;
		pile = ptr;
		free(tab[i]);
	}
	return (ptr);
}

void ft_print_pile(t_pile *pile)
{

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
	ft_check_tab(tab);
	return (tab);
}