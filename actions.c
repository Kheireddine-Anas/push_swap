#include "push_swap.h"

void	sa(t_stacks *stack)
{
	int	tmp;

	if (stack->size_a >= 1)
	{
		tmp = stack->a[stack->size_a];
		stack->a[stack->size_a] = stack->a[stack->size_a - 1];
		stack->a[stack->size_a - 1] = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stacks *stack)
{
	int	tmp;

	if (stack->b[0] > stack->b[1])
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	write(1, "sb\n", 4);
}

// void	ss(t_stacks *stack)
// {

// }

// void	sb(t_stacks *stack)
// {

// }

// void	sb(t_stacks *stack)
// {

// }
