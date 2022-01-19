/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:07 by nflan             #+#    #+#             */
/*   Updated: 2022/01/19 11:26:50 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	j;
	int	check;

	check = 1;
	i = -1;
	while (tab[++i] && check)
	{
		j = -1;
		if ((ft_strlen(tab[i]) > 9 && tab[i][9] > 55) || ft_strlen(tab[i]) > 10)
			check = 0;
		if (tab[i][0] == '-')
			j = 0;
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

t_pile	*ft_pilenew(int n)
{
	t_pile		*new;

	new = ft_calloc(sizeof(t_pile), 1);
	new->num = n;
	new->next = NULL;
	return (new);
}

int	ft_count_line(char **tab)
{
	int	i;

	i = -1;
	if (tab[++i])
		while (tab[i])
			i++;
	return (i);
}
