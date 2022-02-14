/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:07 by nflan             #+#    #+#             */
/*   Updated: 2022/02/10 15:22:30 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_double(t_pile *ptr)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		check;

	tmp = ptr;
	check = 1;
	if (tmp)
	{
		while (tmp && check)
		{
			tmp2 = tmp->next;
			while (tmp2 && check)
			{
				if (tmp->num == tmp2->num)
				{
					ft_printf("tmp->num = %i & tmp2->num = %i\n", tmp->num, tmp2->num);
					check = 0;
				}
				tmp2 = tmp2->next;
			}
			tmp = tmp->next;
		}
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
		if (ft_atoi(tab[i]) < -2147483648 || ft_atoi(tab[i]) > 2147483647)
			check = 0;
		if (tab[i][0] == '-')
			j = 0;
		while (tab[i][++j] && check)
			if (!ft_isdigit(tab[i][j]))
				check = 0;
	}
	if (check)
		return (1);
	ft_putstr_fd("Error\n", 2);
	exit (0);
}

t_chunk	*ft_chunknew(int min, int max, int index, int i)
{
	t_chunk	*new;

	new = ft_calloc(sizeof(t_chunk), 1);
	new->min = min;
	new->max = max;
	new->index = index;
	new->size = i;
	new->next = NULL;
	return (new);
}

t_pile	*ft_pilenew(int n)
{
	t_pile	*new;

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
