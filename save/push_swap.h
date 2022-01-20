/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:14:10 by nflan             #+#    #+#             */
/*   Updated: 2022/01/20 11:26:09 by nflan            ###   ########.fr       */
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

// MAIN

// CHECK
int		ft_check_double(char **tab, int check);
int		ft_check_tab(char **tab);
t_pile	*ft_pilenew(int n);
int		ft_count_line(char **tab);

// FILL
t_pile	*ft_fill_pile(char **tab);
void	ft_fill_pile_b(t_begin *begin);
char	ft_next_to_move(t_pile **pile, int med);
void	ft_print_pile(t_pile *pile);
char	**ft_fill_argv(char **tab, int ac, char **av);

// OP
int		ft_swap(t_pile **pile, int p);
int		ft_push(t_pile **pstart, t_pile **pend, int p);
int		ft_reverse_rotate(t_pile **pstart, int p);
int		ft_rotate(t_pile **pstart, int p);

// UTILS
int		ft_is_sort(t_begin *begin);
void	ft_push_all_to_a(t_begin *begin);
int		ft_is_median(t_begin *begin);
int		ft_nb_rr(t_pile *pile, int med);
int		ft_nb_r(t_pile *pile, int med);

// SWAP
int		ft_do_swap(t_begin *begin);
int		ft_swappy(t_begin *begin, int last);

// ROTATE
int		ft_do_rotate(t_begin *begin);
int		ft_rotaty(t_begin *begin, int last);

// REVERSE ROTATE
int		ft_do_reverse_rotate(t_begin *begin);
int		ft_reverse_rotaty(t_begin *begin, int last);

#endif
