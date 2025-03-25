/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:09:08 by eieong            #+#    #+#             */
/*   Updated: 2025/03/19 12:40:57 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	// ini a
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			// sa
		else if (ft_lstsize(a) == 3)
			// sort 3
		else if (ft_lstsize(a) == 4)
			// sort 4
		else if (ft_lstsize(a) == 5)
			// sort 5
		else
			// sort stack
	}
	free_stack(a);
	return (0);
}
