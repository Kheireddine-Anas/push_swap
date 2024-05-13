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

void	pa(t_stacks *stack)
{
	if (stack->size_b < 0)
		return ;
	stack->size_a++;
	stack->a[stack->size_a] = stack->b[stack->size_b];
	stack->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stack)
{
	if (stack->size_a < 0)
		return ;
	stack->size_b++;
	stack->b[stack->size_b] = stack->a[stack->size_a];
	stack->size_a--;
	write(1, "pb\n", 3);
}

void	ra(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->size_a >= 1)
	{
		i = stack->size_a;
		tmp = stack->a[i];
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[i] = tmp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b >= 1)
	{
		i = stack->size_b;
		tmp = stack->b[i];
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[i] = tmp;
		write(1, "rb\n", 3);
	}
}

void	rrb(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->size_b < 1)
		return ;
	i = 0;
	tmp = stack->b[i];
	while (i < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	write(1, "rrb\n", 4);
}
// void	sb(t_stacks *stack)
// {

// }

// void	sb(t_stacks *stack)
// {

// }
