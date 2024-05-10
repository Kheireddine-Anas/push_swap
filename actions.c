#include "push_swap.h"

void	sa(t_stacks *stack)
{
	int	tmp;

	if (stack->a[0] > stack->a[1])
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	write(1, "sa\n", 4);
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
