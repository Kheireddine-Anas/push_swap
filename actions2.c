/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:30:45 by akheired          #+#    #+#             */
/*   Updated: 2024/05/17 09:37:09 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (man)
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
