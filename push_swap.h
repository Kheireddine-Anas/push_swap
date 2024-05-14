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
	int	range;
}	t_stacks;

char	**ft_split(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
t_stacks	*to_stack(char **arrays, t_stacks *stack);
int	stack_size(char **stack);
void	check_error(int i);
void	fill_stack_a(t_stacks *stack);
void	fill_stack_b(t_stacks *stack);
void	check_duplicated(t_stacks *stack, int size);
int		is_sorted(t_stacks *stack, int size);
int		get_index(int *arr, int nbr, int size);
int		get_biggest(int *stack, int size);
void	sa(t_stacks *stack);
void	pa(t_stacks *stack);
void	ra(t_stacks *stack);
void	rb(t_stacks *stack);
void	rrb(t_stacks *stack);
void	pb(t_stacks *stack);

#endif