/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:17:31 by akheired          #+#    #+#             */
/*   Updated: 2024/05/17 13:27:19 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**nbrs;
	int		size;

	if (argc > 1)
	{
		nbrs = args_con(argv + 1);
		size = stack_size(nbrs);
		make_stack(size, nbrs, &stack_a)
	}
}