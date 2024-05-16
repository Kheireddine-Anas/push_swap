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

void	fill_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	range;
	
	range = 15;
	size = ft_lstsize(*stack_a);
	if (size >= 100 && size <= 500)
		range = 35;
	range_algo(stack_a, stack_b, 0, range);
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

void	sorting5(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 0)
	{
		if (get_position(*stack_a, 0) == 1 ||
			get_position(*stack_a, 0) == 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
	while ((*stack_a)->index != 1)
	{
		if (get_position(*stack_a, 1) == 1)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
	sorting3(stack_a);
	pa(stack_a, stack_b, 1);	
	pa(stack_a, stack_b, 1);	
}

void	make_stack(int size, char **args, t_list **stack_a, t_list **stack_b)
{
	t_list		*node;
	int			i;
	int			*sorted;

	i = 0;
	while (i < size)
	{
		node = new_node(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, node);
		i++;
	}
	if (!check_sort(*stack_a))
		check_error();
	if (check_duplicated(*stack_a))
		check_error();
	sorted = sort_them(*stack_a);
	set_index(*stack_a, sorted);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**nbrs;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		nbrs = args_con(argv + 1);
		size = stack_size(nbrs);
		make_stack(size, nbrs, &stack_a, &stack_b);
		if (size == 2)
			sa(&stack_a, 1);
		else if (size == 3)
			sorting3(&stack_a);
		else if (size <= 5)
			sorting5(&stack_a, &stack_b);
		else
			fill_stack_b(&stack_a, &stack_b);
	}
	return (0);
}
