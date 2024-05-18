/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:30:38 by akheired          #+#    #+#             */
/*   Updated: 2024/05/17 09:30:38 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack, int man)
{
	int	tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	if (man)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack, int man)
{
	int	tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
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
