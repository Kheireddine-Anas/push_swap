#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int main(void)
{
	// printf("%d\n", atoi("-2147483648"));
	// printf("%d\n", INT_MAX);
	printf("%d", ft_atoi("-2147483648"));
}