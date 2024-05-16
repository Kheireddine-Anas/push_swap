/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:35:48 by akheired          #+#    #+#             */
/*   Updated: 2024/05/14 19:35:48 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

void	check_chars(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] != '-' && args[i][j] != '+')
				&& !(args[i][j] >= '0' && args[i][j] <= '9'))
				check_error();
			j++;
		}
		i++;
	}
}

void	check_nbrs(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& !(args[i][1] >= '0' && args[i][1] <= '9'))
			check_error();
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& (args[i][1] >= '0' && args[i][1] <= '9'))
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				check_error();
			j++;
		}
		i++;
	}
}

void	check_spc(char **argv)
{
	int	i;
	int	j;
	int	spc;

	i = 0;
	while (argv[i])
	{
		j = 0;
		spc = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				spc++;
			j++;
		}
		if (j == spc)
			check_error();
		i++;
	}
}

char	**args_con(char **args)
{
	char	**fnl;
	char	*con;
	int		i;

	i = 0;
	check_spc(args);
	con = ft_strdup("");
	while (args[i])
	{
		con = ft_strjoin(con, " ");
		con = ft_strjoin(con, args[i]);
		i++;
	}
	fnl = ft_split(con, ' ');
	free(con);
	check_chars(fnl);
	check_nbrs(fnl);
	return (fnl);
}

void	*ft_calloc(int count, int size)
{
	char	*hld;
	int		i;

	hld = malloc(count * size);
	i = 0;
	if (!hld)
		exit(1);
	while (i < (count * size))
	{
		hld[i] = 0;
		i++;
	}
	return (hld);
}

int	*arr_cp(t_list *head, int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i++] = head->nbr;
		head = head->next;
	}
	return (arr);
}

int	*sort_them(t_list *stack)
{
	int	size;
	int	tmp;
	int	*arr;
	int	i;
	int	j;

	i = 0;
	size = ft_lstsize(stack);
	arr = arr_cp(stack, size);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	get_index(t_list *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (nbr == stack->nbr)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

void	set_index(t_list *stack, int *arr)
{
	int	i;
	int	size;

	size = ft_lstsize(stack);
	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->nbr == arr[i])
				stack->index = i;
			i++;
		}
		stack = stack->next;
	}
}

void	range_algo(t_list **stack_a, t_list **stack_b, int start, int end)
{
	while (ft_lstsize(*stack_a))
	{
		if ((*stack_a)->index < start)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			start++;
			end++;
		}
		else if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			pb(stack_a, stack_b, 1);
			start++;
			end++;
		}
		else if ((*stack_a)->index > end)
			ra(stack_a, 1);
	}
}

void	fill_stack_b(t_list **stack_a, t_list **stack_b)
{
	// int	*sorted;
	int	size;
	int	range;
	
	range = 15;
	// sorted = sort_them(*stack_a);
	// set_index(*stack_a, sorted);
	size = ft_lstsize(*stack_a);
	if (size >= 100 && size <= 500)
		range = 35;
	range_algo(stack_a, stack_b, 0, range);
	// free(sorted);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*hld;

	// if (!lst || !new)
	// 	return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	hld = *lst;
	while (hld->next != NULL)
		hld = hld->next;
	hld->next = new;
}

t_list	*new_node(int nbr)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

int	check_sort(t_list *stack)
{
	t_list	*head;
	int	size;

	size = ft_lstsize(stack);
	head = stack->next;
	while (size > 1 && stack->nbr < head->nbr)
	{
		size--;
		stack = stack->next;
		head = stack->next;
	}
	if (size > 1)
		return (1);
	return (0);
}
void	sorting3(t_list **stack_a)
{
	t_list	*head;
	int		biggest;

	biggest = get_max_index(*stack_a);
	if ((*stack_a)->index == biggest)
		ra(stack_a, 1);
	else if (get_position(*stack_a, biggest) == 1)
		rra(stack_a, 1);
	head = (*stack_a)->next;
	if (head->nbr < (*stack_a)->nbr)
		sa(stack_a, 1);
}

void	make_stack(int size, char **args)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*node;
	int			i;
	int			*sorted;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (i < size)
	{
		node = new_node(ft_atoi(args[i]));
		ft_lstadd_back(&stack_a, node);
		i++;
	}
	if (!check_sort(stack_a))
		check_error();
	if (check_duplicated(stack_a))
		check_error();
	sorted = sort_them(stack_a);
	set_index(stack_a, sorted);
	if (size == 2)
		sa(&stack_a, 1);
	else if (size == 3)
		sorting3(&stack_a);
	else if (size == 5)
	// printf("%d |\n", size);
	// fill_stack_b(&stack_a, &stack_b, sorted);
	// fill_stack_a(&stack_a, &stack_b);
	// pause();
}

int	main(int argc, char **argv)
{
	// t_list	*stacks;
	char		**nbrs;

	if (argc > 1)
	{
		nbrs = args_con(argv + 1);
		make_stack(stack_size(nbrs), nbrs);
	}
	return (0);
}
