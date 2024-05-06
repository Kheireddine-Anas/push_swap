#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct	s_stacks{
	int	*a;
	int	*b;
}	t_stacks;

char	**ft_split(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
void	to_stack(char **arrays, t_stacks *stack);

#endif