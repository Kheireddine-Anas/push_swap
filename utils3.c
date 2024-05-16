#include "push_swap.h"

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
				check_error();
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
	while (args[i])
	{
		j = 0;
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& !(args[i][1] >= '0' && args[i][1] <= '9'))
			check_error();
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& (args[i][1] >= '0' && args[i][1] <= '9'))
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				check_error();
			j++;
		}
		i++;
	}
}

void	check_spc(char **argv)
{
	int	i;
	int	j;
	int	spc;

	i = 0;
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
}

char	**args_con(char **args)
{
	char	**fnl;
	char	*con;
	int		i;

	i = 0;
	check_spc(args);
	con = ft_strdup("");
	while (args[i])
	{
		con = ft_strjoin(con, " ");
		con = ft_strjoin(con, args[i]);
		i++;
	}
	fnl = ft_split(con, ' ');
	free(con);
	check_chars(fnl);
	check_nbrs(fnl);
	return (fnl);
}

int	*arr_cp(t_list *head, int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i++] = head->nbr;
		head = head->next;
	}
	return (arr);
}
