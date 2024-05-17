/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:30:43 by akheired          #+#    #+#             */
/*   Updated: 2024/05/17 09:39:51 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int man)
{
	t_list	*tmp;
	t_list	*head;
	int		size;

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
