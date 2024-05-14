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

void	*ft_calloc(int count, int size)
{
	char	*hld;
	int		i;

	i = 0;
	hld = malloc(count * size);
	if (!hld)
		return (NULL);
	while (i < (count * size))
	{
		hld[i] = 0;
		i++;
	}
	
	return (hld);
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

int	*arr_cp(int *arrd, int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * (size + 1));
	while (i <= size)
	{
		arr[i] = arrd[i];
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
	// int	j;

	i = 0;
	size = stack_a->size_a;
	// arr = arr_cp(stack_a);
	arr = arr_cp(stack_a->a, stack_a->size_a);
	printf("%d  |%d\n",size , arr[i]);
	while (i <= size)
	{
		if(arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	// i = 0;
	// while (i <= stack_a->size_a)
	// {
	// 	printf("%d  |%d\n",i , arr[i]);
	// 	i++;
	// }
	exit(1);
	return (arr);
}

int	get_index(int *arr, int nbr, int size)
{
	int	i;

	i = 0;
	while (i < size && arr[i] != nbr)
		i++;
	return (i);
}

void	fill_stack_b(t_stacks *stack)
{
	int	*sorted;
	int	index;

	int	start = 0;
	int	end = 15;
	if (stack->size_a > 100)
		end = 35;
	sorted = sort_them(stack);
	int kd=0;
	int size = stack->size_a;
	printf("%d  ?? %d  ??? %d\n", size, end , start);
	while (stack->size_a >= 0)
	{
		index = get_index(sorted, stack->a[stack->size_a], stack->size_a);
		if (index >= start && index <= end)
		{
			pb(stack);
			if (end <= size)
				{start++;
				end++;}
			// start++;
			// end++;
		}
		else if (index < start)
		{
			pb(stack);
			rb(stack);
			if (end <= size)
				{start++;
				end++;}
		}
		else if (index > end)
			ra(stack);
		printf("start = %d | end = %d  | size = %d /// >>>%d\n", start, end, size, index);
		printf("KD + %d\n", kd);
		if(/*kd == 3 || kd == 4 || kd == 5 || kd ==6 || */ kd == 155 ||  kd == 156)
		{
			int kj=0;
			while(kj <= 99)
			{
				printf("%d| %d |    | %d |    | %d |\n", kj, stack->a[kj], stack->b[kj], sorted[kj]);
				kj++;
			}
		}
		kd++;
	}
	printf("||||\n");
	printf("%d  ?? %d  ??? %d\n", size, end , start);
	pause();
	// printf("| %d |    | %d |    | %d |\n", stack->a[1], stack->b[1], sorted[1]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[2], stack->b[2], sorted[2]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[3], stack->b[3], sorted[3]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[4], stack->b[4], sorted[4]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[5], stack->b[5], sorted[5]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[6], stack->b[6], sorted[6]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[7], stack->b[7], sorted[7]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[8], stack->b[8], sorted[8]);
	// printf("| %d |    | %d |    | %d |\n", stack->a[9], stack->b[9], sorted[9]);
	// pause();
	// printf("||||\n");
	free(sorted);
}

void	make_stack(int size, char **args, t_stacks *stacks)
{
	// t_stacks	*stacks = NULL;
	int			i;

	i = 0;
	// stacks = malloc(sizeof(t_stacks));
	stacks->a = ft_calloc(size, sizeof(int));
	stacks->b = ft_calloc(size, sizeof(int));
	// stacks->a = malloc(sizeof(int) * size);
	// stacks->b = malloc(sizeof(int) * size);
	stacks->size_a = size - 1;
	stacks->size_b = -1;
	stacks->range = 15;
	while (size--)
	{
		stacks->a[i] = ft_atoi(args[size]);
		i++;
	}
	check_duplicated(stacks, stacks->size_a);
	if (is_sorted(stacks, stacks->size_a))
			exit(1);
	fill_stack_b(stacks);
	fill_stack_a(stacks);

	// return (stacks);
}

int main(int argc, char **argv)
{
	t_stacks	stacks;
	char	**nbrs;

	// int i = 0;
	if (argc > 1)
	{
		nbrs = args_con(argv + 1);
		make_stack(stack_size(nbrs), nbrs, &stacks);
		// printf("%d $ %d\n", stacks->a[0], stacks->a[1]);
		if (!(is_sorted(&stacks, stacks.size_a)))
			printf("NON");
		// printf("%d # %d\n", stacks->a[0], stacks->a[1]);
		// free(stacks);
		// printf("%d\n", stacks->a[0]);
		// printf("%d\n", stacks->a[0]);
		// stacks = make_stack();
		// printf("%s", nbrs[0]);
		// pause();
		// into_stack();
		// while (i <= stacks->size_a)
		// {
		// 	printf("%d =>  %d\n", i, stacks->a[i]);
		// 	i++;
		// }
		// pause();
	}
	return (0);
}
