#include "push_swap.h"

void	check_error(void)
{
	printf("Non\n");
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
			if ((args[i][0] == '-' || args[i][0] == '+') && (args[i][1] <= '0' && args[i][1] >= '9'))
			{
				check_error();
			}
			
		}
		
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
	check_nbrs(fnl);
}
int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	// int *ints;
	int spc;

	if (argc < 2)
		check_error();
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
			check_error();
		i++;
	}
	args_con(argv + 1);
}