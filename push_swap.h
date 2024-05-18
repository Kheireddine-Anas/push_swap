/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:41:36 by akheired          #+#    #+#             */
/*   Updated: 2024/05/17 09:41:36 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stacks{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	range;
}	t_stacks;

typedef struct s_list{
	int				nbr;
	int				index;
	struct s_list	*next;	
}	t_list;

char	**ft_split(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
int		stack_size(char **stack);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*new_node(int nbr);
int		ft_lstsize(t_list *lst);
int		check_sort(t_list *stack);
int		get_max_index(t_list *stack);
int		is_sorted(t_list *stack);
void	check_error(void);
int		check_duplicated(t_list *stack);
void	check_chars(char **args);
void	check_nbrs(char **args);
void	check_spc(char **argv);
char	**args_con(char **args);
void	*ft_calloc(int count, int size);
int		*arr_cp(t_list *head, int size);
int		*sort_them(t_list *stack);
void	make_stack(int size, char **args, t_list **stack_a);
void	range_algo(t_list **stack_a, t_list **stack_b, int start, int end);
void	sorting3(t_list **stack_a);
void	lst_checker(t_list **stack_a, t_list **stack_b);
void	sorting5(t_list **stack_a, t_list **stack_b);
void	fill_stack_a(t_list **stack_a, t_list **stack_b);
void	fill_stack_b(t_list **stack_a, t_list **stack_b);
int		get_index(t_list *stack, int nbr);
void	set_index(t_list *stack, int *arr);
int		get_index(t_list *stack, int nbr);
int		get_position(t_list *stack, int index);
int		get_biggest(int *stack, int size);
void	sa(t_list **stack, int man);
void	sb(t_list **stack, int man);
void	ss(t_list **stack_a, t_list **stack_b, int man);
void	pa(t_list **stack_a, t_list **stack_b, int man);
void	pb(t_list **stack_a, t_list **stack_b, int man);
void	ra(t_list **stack_a, int man);
void	rb(t_list **stack_b, int man);
void	rr(t_list **stack_a, t_list **stack_b, int man);
void	rra(t_list **stack_a, int man);
void	rrb(t_list **stack_b, int man);
void	rrr(t_list **stack_a, t_list **stack_b, int man);

#endif