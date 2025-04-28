/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:08:10 by eieong            #+#    #+#             */
/*   Updated: 2025/04/28 11:28:52 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_range(int *start, int *range)
{
	*start += 1;
	*range += 1;
}

void	small_nb(t_stack **a, t_stack **b, int index, int range)
{
	if (index >= range)
	{
		do_pb(a, b);
		do_rr(a, b);
	}
	else
	{
		do_pb(a, b);
		do_rb(b);
	}
}

void	push_to_b(t_stack **a, t_stack **b, int *sorted_tab, int size)
{
	int	start;
	int	range;
	int	tab_index;
	int	next_tab_index;

	start = 0;
	range = 23;
	while (ft_listsize(*a))
	{
		tab_index = get_index_tab(sorted_tab, size, (*a)->nb);
		if (ft_listsize(*a) > 2)
			next_tab_index = get_index_tab(sorted_tab, size, (*a)->next->nb);
		else
			next_tab_index = -1;
		if (tab_index < start)
			small_nb(a, b, next_tab_index, (range + 1));
		else if (tab_index >= start && tab_index < range)
			do_pb(a, b);
		else if (tab_index >= range)
			do_ra(a);
		if (tab_index < range)
			move_range(&start, &range);
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	int	max_i;

	while (*b)
	{
		max_i = index_max(b);
		if (max_i > ft_listsize(*b) / 2)
		{
			while ((*b)->nb != get_max(b))
				do_rrb(b);
		}
		else
		{
			while ((*b)->nb != get_max(b))
				do_rb(b);
		}
		do_pa(a, b);
	}
}
