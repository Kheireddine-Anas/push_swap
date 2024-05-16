#include "push_swap.h"

void	sa(t_list **stack, int man)
{
	int	tmp;

	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	if (man)
		write(1, "sa\n", 3);
}
void	sb(t_list **stack, int man)
{
	int	tmp;

	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	if (man)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int man)
{
	sa(stack_a, man);
	sb(stack_b, man);
	if (man)
		write(1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int man)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_b) > 0)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
		if (man)
			write(1, "pa\n", 3);
	}
}

void	pb(t_list **stack_a, t_list **stack_b, int man)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) > 0)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		*stack_b = tmp;
		if (man)
			write(1, "pb\n", 3);
	}
}

void	ra(t_list **stack_a, int man)
{
	t_list	*tmp;
	t_list	*head;
	int	size;

	size = ft_lstsize(*stack_a);
	head = (*stack_a);
	tmp = (*stack_a);
	if (ft_lstsize(*stack_a) > 1)
	{
		*stack_a = tmp->next;
		while (head->next)
			head = head->next;
		head->next = tmp;
		tmp->next = NULL;
		if (man)
			write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b, int man)
{
	t_list	*tmp;
	t_list	*head;

	head = (*stack_b);
	tmp = (*stack_b);
	if (ft_lstsize(*stack_b) > 1)
	{
		*stack_b = tmp->next;
		while (head->next)
			head = head->next;
		head->next = tmp;
		tmp->next = NULL;
		if (man)
			write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, int man)
{
	ra(stack_a, man);
	rb(stack_b, man);
	if (man)
		write(1, "rr\n", 3);
}

void	rra(t_list **stack_a, int man)
{
	t_list	*frst;
	t_list	*blst;
	t_list	*lst;
	int		size;
	int		i;

	i = 1;
	size = ft_lstsize(*stack_a);
	frst = (*stack_a);
	blst = (*stack_a);
	lst = (*stack_a);
	if (size > 1)
	{
		while (lst->next)
			lst = lst->next;
		while (i++ < (size -1))
			blst = blst->next;
		*stack_a = lst;
		lst->next = frst;
		blst->next = NULL;
		if (man)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b, int man)
{
	t_list	*frst;
	t_list	*blst;
	t_list	*lst;
	int		size;
	int		i;

	i = 1;
	size = ft_lstsize(*stack_b);
	frst = (*stack_b);
	blst = (*stack_b);
	lst = (*stack_b);
	if (size > 1)
	{
		while (lst->next)
			lst = lst->next;
		while (i++ < (size -1))
			blst = blst->next;
		*stack_b = lst;
		lst->next = frst;
		blst->next = NULL;
		if(man)
			write(1, "rrb\n", 4);
	}
}
void	rrr(t_list **stack_a, t_list **stack_b, int man)
{
	rra(stack_a, man);
	rrb(stack_b, man);
	if (man)
		write(1, "rrr\n", 4);
}
// void	sb(t_stacks *stack)
// {

// }

// void	sb(t_stacks *stack)
// {

// }
