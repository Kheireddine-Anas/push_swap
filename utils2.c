#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*hld;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	hld = *lst;
	while (hld->next != NULL)
		hld = hld->next;
	hld->next = new;
}

t_list	*new_node(int nbr)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	*ft_calloc(int count, int size)
{
	char	*hld;
	int		i;

	hld = malloc(count * size);
	i = 0;
	if (!hld)
		exit(1);
	while (i < (count * size))
	{
		hld[i] = 0;
		i++;
	}
	return (hld);
}

int	stack_size(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}
