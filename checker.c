/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:17:31 by akheired          #+#    #+#             */
/*   Updated: 2024/05/18 21:53:20 by akheired         ###   ########.fr       */
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
	if (check_duplicated(*stack_a))
		check_error();
	sorted = sort_them(*stack_a);
	set_index(*stack_a, sorted);
	free(sorted);
}

void	apply_inst(t_list **stack_a, t_list **stack_b, char *buf)
{
	if (buf[0] == 's' && buf[1] == 'a' && buf[2] == '\n')
		sa(stack_a, 0);
	else if (buf[0] == 's' && buf[1] == 'b' && buf[2] == '\n')
		sb(stack_b, 0);
	else if (buf[0] == 's' && buf[1] == 's' && buf[2] == '\n')
		ss(stack_a, stack_b, 0);
	else if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\n')
		pa(stack_a, stack_b, 0);
	else if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\n')
		pb(stack_a, stack_b, 0);
	else if (buf[0] == 'r' && buf[1] == 'a' && buf[2] == '\n')
		ra(stack_a, 0);
	else if (buf[0] == 'r' && buf[1] == 'b' && buf[2] == '\n')
		rb(stack_b, 0);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
		rr(stack_a, stack_b, 0);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a' && buf[3] == '\n')
		rra(stack_a, 0);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b' && buf[3] == '\n')
		rrb(stack_b, 0);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r' && buf[3] == '\n')
		rrr(stack_a, stack_b, 0);
	else if (buf[0] != 's' && buf[0] != 'p' && buf[0] != 'r' && buf[0] != '\n')
		check_error();
}

void	read_inst(t_list **stack_a, t_list **stack_b)
{
	int		readed;
	int		i;
	char	buffer;
	char	inst[5];

	readed = 1;
	i = 0;
	while (readed)
	{
		readed = read(0, &buffer, 1);
		inst[i++] = buffer;
		if (buffer == '\n')
		{
			inst[i] = '\0';
			apply_inst(stack_a, stack_b, inst);
			i = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**nbrs;

	if (argc > 1)
	{
		nbrs = args_con(argv + 1);
		make_stack(stack_size(nbrs), nbrs, &stack_a);
		read_inst(&stack_a, &stack_b);
		lst_checker(&stack_a, &stack_b);
	}
	// system("leaks checker");
}
