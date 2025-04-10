/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:32:55 by eieong            #+#    #+#             */
/*   Updated: 2025/04/10 15:06:25 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	do_rotate(t_stack **a)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return (false);
	temp = *a;
	*a = (*a)->next;
	last = ft_listlast(*a);
	last->next = temp;
	temp->next = NULL;
	return (true);
}

void	do_ra(t_stack **a)
{
	if (do_rotate(a))
		write(1, "ra\n", 3);
}

void	do_rb(t_stack **b)
{
	if (do_rotate(b))
		write(1, "rb\n", 3);
}

void	do_rr(t_stack **a, t_stack **b)
{
	if (do_rotate(a) && do_rotate(b))
		write(1, "rr\n", 3);
	else
	{
		if (do_rotate(a))
			write(1, "ra\n", 3);
		if (do_rotate(b))
			write(1, "rb\n", 3);
	}
}
