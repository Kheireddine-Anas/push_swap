/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:19:13 by akheired          #+#    #+#             */
/*   Updated: 2024/05/06 22:46:15 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (0);
	while (i[s1])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = 0;
	free(s1);
	return (str);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		fnl;
	long	rzlt;

	i = 0;
	sign = 1;
	rzlt = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rzlt = rzlt * 10 + (str[(i++)] - 48);
		if ((rzlt > INT_MAX && sign == 1) || (rzlt > 2147483648 && sign == -1))
			printf("NOD\n");
	}
	fnl = rzlt;
	return (sign * fnl);
}

int	check_duplicated(t_list *stack)
{
	t_list	*node;

	while (stack)
	{
		node = stack->next;
		while (node)
		{
			if (node->nbr == stack->nbr)
				return (1);
			node = node->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	check_sort(t_list *stack)
{
	t_list	*head;
	int	size;

	size = ft_lstsize(stack);
	head = stack->next;
	while (size > 1 && stack->nbr < head->nbr)
	{
		size--;
		stack = stack->next;
		head = stack->next;
	}
	if (size > 1)
		return (1);
	return (0);
}
