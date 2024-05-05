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
