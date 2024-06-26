/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:30:50 by akheired          #+#    #+#             */
/*   Updated: 2024/05/17 09:30:50 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

static size_t	count_word(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

static size_t	count_len(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char	*str_alloc(const char *str, char c)
{
	char	*word;
	size_t	i;
	size_t	worldlen;

	i = 0;
	worldlen = count_len(str, c);
	word = (char *)malloc(sizeof(char) * (worldlen + 1));
	if (!word)
		return (NULL);
	while (i < worldlen)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strings;
	size_t	i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!strings)
		return (NULL);
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0')
		{
			strings[i] = str_alloc(str, c);
			if (!strings[i])
				return (NULL);
			i++;
		}
		while (*str != '\0' && *str != c)
			str++;
	}
	strings[i] = 0;
	return (strings);
}
