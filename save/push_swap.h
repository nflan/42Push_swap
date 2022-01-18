/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:14:10 by nflan             #+#    #+#             */
/*   Updated: 2022/01/18 15:47:22 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pile
{
	int				num;
	struct s_pile	*next;
}	t_pile;

typedef struct s_begin
{
	t_pile	*pile_a;
	t_pile	*pile_b;
}	t_begin;

# include "libft/libft.h"

// CHECK
int		ft_check_double(char **tab, int check);
int		ft_check_tab(char **tab);
t_pile	*ft_pilenew(int n);
int		ft_count_line(char **tab);

// FILL
t_pile	*ft_fill_pile(char **tab);
void	ft_print_pile(t_pile *pile);
char	**ft_fill_argv(char **tab, int ac, char **av);

// OP
int		ft_swap(t_pile **pile);
int		ft_push(t_pile **pstart, t_pile **pend);
int		ft_reverse_rotate(t_pile **pstart);
int		ft_rotate(t_pile **pstart);

// UTILS
int		ft_is_sort(t_begin *begin);
void	ft_push_all_to_a(t_begin *begin);
int		ft_median(t_begin *begin);

#endif
