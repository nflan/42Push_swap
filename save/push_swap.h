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

#include "libft/libft.h"

int		main(int, char **);

// CHECKS
int		ft_check_double(char **, int);
int		ft_check_tab(char **);

// FILL
t_pile	*ft_pilenew(int);
t_pile	*ft_fill_pile(char **);
int		ft_count_line(char **);
void	ft_print_pile(t_pile *);
char	**ft_fill_argv(char **, int, char **);

// OP
int	ft_swap(t_pile **);
int	ft_push(t_pile **, t_pile **);
int	ft_reverse_rotate(t_pile **);
int	ft_rotate(t_pile **);

#endif
