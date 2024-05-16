#include "push_swap.h"

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
	fill_stack_a(stack_a, stack_b);
}

void	fill_stack_a(t_list **stack_a, t_list **stack_b)
{
	int	biggest;
	int	size;

	while (ft_lstsize(*stack_b) > 0)
	{
		size = ft_lstsize(*stack_b);
		biggest = get_max_index(*stack_b);
		if ((*stack_b)->index == biggest)
			pa(stack_a, stack_b, 1);
		else if (get_position(*stack_b, biggest) <= (size / 2))
			rb(stack_b, 1);
		else if (get_position(*stack_b, biggest) > (size / 2))
			rrb(stack_b, 1);
	}
}
