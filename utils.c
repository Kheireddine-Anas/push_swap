/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:19:13 by akheired          #+#    #+#             */
/*   Updated: 2024/05/06 22:35:17 by akheired         ###   ########.fr       */
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

int	stack_size(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

void	check_duplicated(t_stacks *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
				check_error(7);
			j++;
		}
		i++;
	}
}
