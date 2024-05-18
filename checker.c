/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:17:31 by akheired          #+#    #+#             */
/*   Updated: 2024/05/18 15:43:04 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	range;

	range = 35;
	size = ft_lstsize(*stack_a);
	if (size <= 100)
		range = 15;
	range_algo(stack_a, stack_b, 0, range);
}

void	make_stack(int size, char **args, t_list **stack_a)
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
		exit(0);
	if (check_duplicated(*stack_a))
		check_error();
	sorted = sort_them(*stack_a);
	set_index(*stack_a, sorted);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	// t_list	*stack_b = NULL;
	char	**nbrs;
	int		size;
	char	inst[5];

	if (argc > 1)
	{
		nbrs = args_con(argv + 1);
		size = stack_size(nbrs);
		make_stack(size, nbrs, &stack_a);
		printf("%d |\n", stack_a->nbr);
		while (1)
		{
			/* code */
		}
		
	}
}