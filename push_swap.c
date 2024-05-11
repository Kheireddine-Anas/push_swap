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
	if (i == 6)
		printf("Non6\n");
	if (i == 7)
		printf("Non7\n");
	if (i == 8)
		printf("Non8\n");
	
	exit(1);
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
	while (args[i])
	{
		j = 0;
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& !(args[i][1] >= '0' && args[i][1] <= '9'))
			check_error(5);
		if ((args[i][0] == '-' || args[i][0] == '+')
			&& (args[i][1] >= '0' && args[i][1] <= '9'))
			j++;
		while (args[i][j])
		{
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
			{
				printf("#%d, %d, %c $%s#\n", i, j, args[i][j], args[i]);
				check_error(6);
			}
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
			check_error(4);
		i++;
	}
}

char	**args_con(char **args)
{
	char	**fnl;
	char	*con;
	int		i;
	// int		j;

	i = 0;
	// j = 0;
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

int	*arr_cp(t_stacks *stack)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * (stack->size_a));
	while (i <= stack->size_a)
	{
		arr[i] = stack->a[i];
		i++;
	}
	return (arr);
}

int	*sort_them(t_stacks *stack_a)
{
	int	size;
	int	tmp;
	int	*arr;
	int	i;
	int	j;

	i = 0;
	size = stack_a->size_a;
	arr = arr_cp(stack_a);
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if(arr[j] > arr[j + 1])
			{
				tmp =arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	get_index(int *arr, int nbr)
{
	int	i;

	i = 0;
	while (arr[i] != nbr)
		i++;
	return (i);
}

void	fill_stack_b(t_stacks *stack)
{
	int	*sorted;
	int	index;

	sorted = sort_them(stack); //freeeeee
	while (stack->size_a >= 0)
	{
		index = get_index(sorted, stack->a[stack->size_a]);
	}
	
	pause();
	return;
}

t_stacks	*make_stack(int size, char **args)
{
	t_stacks	*stacks;
	int			i;

	i = 0;
	stacks = malloc(sizeof(t_stacks));
	stacks->a = malloc(sizeof(int) * size);
	stacks->b = malloc(sizeof(int) * size);
	// stacks->size_a = malloc(sizeof(int));
	// stacks->size_b = malloc(sizeof(int));
	stacks->size_a = size - 1;
	stacks->size_b = -1;
	while (size--)
	{
		stacks->a[i] = ft_atoi(args[size]);
		i++;
	}
	check_duplicated(stacks, stacks->size_a);
	if (is_sorted(stacks, stacks->size_a))
			exit(1);
	free(args);
	fill_stack_b(stacks);
	return (stacks);
}

int main(int argc, char **argv)
{
	t_stacks	*stacks;
	char	**nbrs;
	// int *ints;

	if (argc > 1)
	{
		nbrs = args_con(argv + 1);
		stacks = make_stack(stack_size(nbrs), nbrs);
		// printf("%d $ %d\n", stacks->a[0], stacks->a[1]);
		// if (!(is_sorted(stacks, stacks->size_a)))
		// 	sa(stacks);
		// printf("%d # %d\n", stacks->a[0], stacks->a[1]);
		// free(stacks);
		// printf("%d\n", stacks->a[0]);
		// printf("%d\n", stacks->a[0]);
		// stacks = make_stack();
		// printf("%s", nbrs[0]);
		// pause();
		// into_stack();
	}
	return (0);
}
