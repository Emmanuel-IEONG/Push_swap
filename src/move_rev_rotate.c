/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rev_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:08:31 by eieong            #+#    #+#             */
/*   Updated: 2025/04/08 16:25:30 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	do_rev_rotate(t_stack **a)
{
	t_stack	*bef_last;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return (false);
	bef_last = ft_before_lstlast(a);
	last = ft_listlast(a);
	bef_last->next = NULL;
	last->next = *a;
	*a = last;
	return (true);
}

void	do_rra(t_stack **a)
{
	if (do_rev_rotate(a))
		write(1, "rra\n", 4);
}

void	do_rrb(t_stack **b)
{
	if (do_rev_rotate(b))
		write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **a, t_stack **b)
{
	if (do_rev_rotate(a) && do_rev_rotate(b))
		write(1, "rrr\n", 4);
}
