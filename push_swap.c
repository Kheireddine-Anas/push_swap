#include "push_swap.h"

void	check_error(int i)
{
	if (i == 1)
		printf("Non1\n");
	if (i == 2)
		printf("Non2\n");
	if (i == 3)
		printf("Non3\n");
	if (i == 4)
		printf("Non4\n");
	if (i == 5)
		printf("Non5\n");
	
	exit(1);
}

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

void	check_chars(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] != '-' && args[i][j] != '+')
				&& !(args[i][j] >= '0' && args[i][j] <= '9'))
			{
				printf("%d-%d-%c", i, j, args[i][j]);
				check_error(2);
			}
			j++;
		}
		i++;
	}
}

void	check_nbrs(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		while (args[i][j])
		{
			printf("%c<<\n", args[i][j]);
			if ((args[i][j] == '-' || args[i][j] == '+') && !(args[i][j + 1] >= '0' && args[i][j + 1] <= '9'))
			{
				printf("%c>> %d , %d\n", args[i][j], i, j);
				check_error(5);
			}
			j++;
		}
		i++;
	}
	
}

void	args_con(char **args)
{
	char	**fnl;
	char	*con;
	int		i;
	int		j;
	i = 0;
	j = 0;
	con = ft_strdup("");
	while (args[i])
	{
		con = ft_strjoin(con, " ");
		con = ft_strjoin(con, args[i]);
		i++;
	}
	fnl = ft_split(con, ' ');
	check_chars(fnl);
	check_nbrs(args);
}
int main(int argc, char **argv)
{
	int i = 1;
	int j;
	// int *ints;
	int spc;

	if (argc < 2)
		check_error(3);
	while (argv[i])
	{
		j = 0;
		spc = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				spc++;
			j++;
		}
		if (j == spc)
			check_error(4);
		i++;
	}
	args_con(argv + 1);
}