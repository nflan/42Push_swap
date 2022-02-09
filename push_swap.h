/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nflan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:14:10 by nflan             #+#    #+#             */
/*   Updated: 2022/02/09 17:49:07 by nflan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pile
{
	int				num;
	struct s_pile	*next;
}	t_pile;

typedef struct s_roll
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	struct s_roll	*next;
}	t_roll;

typedef struct s_chunk
{
	int				min;
	int				max;
	int				index;
	int				size;
	struct s_chunk	*next;
}	t_chunk;

typedef struct s_begin
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				moves;
	int				bmoves;
	int				print;
}	t_begin;

# include "libft/libft.h"

// MAIN
void	ft_print_begin(t_begin *begin);
int		ft_rr_rrr(t_roll *roll);

// CHECK
int		ft_check_double(char **tab, int check);
int		ft_check_tab(char **tab);
t_chunk	*ft_chunknew(int min, int max, int index, int i);
t_pile	*ft_pilenew(int n);
int		ft_count_line(char **tab);

// FILL
t_pile	*ft_fill_pile(char **tab);
void	ft_fill_pile_b(t_begin *begin);
char	ft_next_to_move(t_pile **pile, int med);
char	**ft_fill_argv(char **tab, int ac, char **av);

// OP
int		ft_swap(t_begin *begin, t_pile **pile, int p);
int		ft_push(t_begin *begin, t_pile **pstart, t_pile **pend, int p);
int		ft_reverse_rotate(t_begin *begin, t_pile **pstart, int p);
int		ft_rotate(t_begin *begin, t_pile **pstart, int p);

// DOUBLE / TRIPLE
void	ft_double(t_begin *begin, int pile);
void	ft_triple(t_begin *begin, int pile);
void	ft_do_triple(t_begin *begin, t_pile **pile, int p);

// FIVE
int		ft_five_clean_a(t_pile *tmp, int ra, int pile_min);
int		ft_five_ra_rra(t_begin *begin, int numb, int pile_min, int pile_max);
void	ft_back_to_a(t_begin *begin, int pile_min, int pile_max);
void	ft_five(t_begin *begin);

// FIVE_TOOLS
int		ft_pile_min(t_begin *begin, int pile);
int		ft_pile_max(t_begin *begin, int pile);

// UTILS
int		ft_is_sort(t_begin *begin);
void	ft_push_all_to_a(t_begin *begin);
int		ft_nb_rra(t_pile *pile, t_chunk *chunk, int ind);
int		ft_nb_ra(t_pile *pile, t_chunk *chunk, int ind);

// CHUNKS
int		pile_is_sort(t_pile *pile);
int		ft_min_max_chunk(t_chunk *chunk, int ind, int ext);
t_pile	*sort_pile(t_pile *pile);
t_chunk	*ft_fill_chunks(t_pile *pile, int i, int index);
t_pile	*ft_pile_chunk(t_begin *begin);

// MANAGE A
void	ft_finish_rotate_a(t_begin *btmp, t_chunk *chunk, int ind, int ra);
int		ft_nb_next_p(t_begin *btmp, t_chunk *chunk, int ind);
int		ft_nb_ra_rra(t_begin *btmp, int nbr, t_roll *roll);

// MANAGE B
int		ft_is_b_sort(t_begin *btmp);
int		ft_min_in_max(t_pile *pile, t_chunk *chunk, int ind);
int		ft_find_top(t_begin *btmp, int nbr);
int		ft_nb_rb_rrb(t_begin *btmp, int nbr, t_roll *roll);
int		ft_nb_rb_rrb_bis(t_begin *btmp, int nbr);

// MABAGE B 2
void	ft_next_to_b(t_begin *btmp, t_chunk *chunk, int ind, t_roll *roll);
void	ft_do_rr_rrr(t_begin *btmp, int rr_rrr);
void	ft_move_both(t_begin *btmp, t_chunk *chunk, int ind, t_roll *roll);
void	ft_fill_b(t_begin *btmp, t_chunk *chunk);
void	ft_b_clean(t_begin *btmp);

// ROLL
void	ft_fill_roll_a(t_roll *roll, int ra, int rra);
void	ft_fill_roll_b(t_roll *roll, int rb, int rrb);

// PRINT / DEBUG
void	ft_print_chunk(t_chunk *chunk);
void	ft_print_pile(t_pile *pile);
void	ft_print_begin(t_begin *begin);
void	ft_print_roll(t_roll *roll);

#endif
