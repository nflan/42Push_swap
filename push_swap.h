#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct n_list
{
	int				num;
	struct n_list	*next;
}	i_list;

#include "libft/libft.h"

int		main(int, char **);
int		ft_check_double(char **, int);
int		ft_check_tab(char **);
i_list	*ft_fill_pile(char **, i_list *);
void	ft_print_pile(i_list *);
char	**ft_fill_argv(char **, int, char **);

#endif
