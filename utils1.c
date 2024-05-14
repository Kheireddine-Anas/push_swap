/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:35:21 by akheired          #+#    #+#             */
/*   Updated: 2024/05/14 10:27:29 by akheired         ###   ########.fr       */
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

int	is_sorted(t_stacks *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (stack->a[i] < stack->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

// void	fill_stack_a(t_stacks *stack)
// {
// 	int	biggest;
// 	int size;
// 	while (stack->size_b >= 0)
// 	{
// 		size = stack->size_b;
// 		biggest = get_biggest(stack->b, stack->size_b);
// 		if (biggest == stack->size_b)
// 			pa(stack);
// 		else if (biggest > size / 2)
// 			rb(stack);
// 		else if (biggest <= size / 2)
// 			rrb(stack);
// 	}
// }

void	fill_stack_a(t_stacks *stack)
{
	int	biggest;

	while (stack->size_b >= 0)
	{
		biggest = get_biggest(stack->b, stack->size_b);
		if (biggest == stack->size_b)
			pa(stack);
		else if (stack->size_b - biggest <= biggest)
			rb(stack);
		else if (stack->size_b - biggest > biggest)
			rrb(stack);
	}
}