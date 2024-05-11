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
	int	size_a;
	int	size_b;
}	t_stacks;

char	**ft_split(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
t_stacks	*to_stack(char **arrays, t_stacks *stack);
int	stack_size(char **stack);
void	check_error(int i);
void	check_duplicated(t_stacks *stack, int size);
int		is_sorted(t_stacks *stack, int size);
void	sa(t_stacks *stack);

#endif