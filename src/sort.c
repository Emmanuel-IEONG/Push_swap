/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:46:06 by eieong            #+#    #+#             */
/*   Updated: 2025/04/10 15:23:55 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack **a)
{
	int	max_i;

	max_i = index_max(a);
	if (max_i == 0)
		do_ra(a);
	else if (max_i == 1)
		do_rra(a);
	if ((*a)->nb > (*a)->next->nb)
		do_sa(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min_i;

	min_i = index_min(a);
	if (min_i == 1)
		do_sa(a);
	else if (min_i == 2)
	{
		do_ra(a);
		do_ra(a);
	}
	else if (min_i == 3)
		do_rra(a);
	if (!stack_sorted(*a))
	{
		do_pb(a, b);
		sort_three(a);
		do_pa(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min_i;

	min_i = index_min(a);
	if (min_i == 1)
		do_sa(a);
	else if (min_i == 2)
	{
		do_ra(a);
		do_ra(a);
	}
	else if (min_i == 3)
	{
		do_rra(a);
		do_rra(a);
	}
	else if (min_i == 4)
		do_rra(a);
	if (!stack_sorted(*a))
	{
		do_pb(a, b);
		sort_four(a, b);
		do_pa(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b, int *sorted_tab)
{
	int	stack_size;

	stack_size = ft_listsize(*a);
	if (stack_size == 2)
		do_sa(a);
	else if (stack_size == 3)
		sort_three(a);
	else if (stack_size == 4)
		sort_four(a, b);
	else if (stack_size == 5)
		sort_five(a, b);
	else
	{
		push_to_b(a, b, sorted_tab, stack_size);
		push_to_a(a, b);
	}
}
