/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:35:21 by akheired          #+#    #+#             */
/*   Updated: 2024/05/13 17:49:12 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *s)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	is_sorted(t_list *head)
{
	t_list	*node;
	int	i;

	i = ft_lstsize(head);
	node = head->next;
	while (i > 1 && (head->nbr < node->nbr))
	{
		head = head->next;
		node = head->next;
		i--;
	}
	if (i > 1)
		return (1);
	else
		return (0);
}

int	get_biggest(int *stack, int size)
{
	int	i;
	int	tmp;
	int	in;

	i = 0;
	in = 0;
	tmp = stack[i];
	while (i <= size)
	{
		if (stack[i] > tmp)
		{
			tmp = stack[i];
			in = i;
		}
		i++;
	}
	return (in);
}

int		get_max_index(t_list *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (index < stack->index)
			index = stack->index;
		stack = stack->next;
	}
	return(index);
}

int	get_position(t_list *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if(index == stack->index)
			break;
		stack = stack->next;
		i++;
	}
	return (i);
}
