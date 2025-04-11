/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:47:26 by eieong            #+#    #+#             */
/*   Updated: 2025/04/11 17:54:56 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*b))
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
}

void	do_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
}

t_bool	do_swap(t_stack **a)
{
	int	temp;

	if (!(*a) || !(*a)->next)
		return (false);
	temp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = temp;
	return (true);
}

void	do_ss(t_stack **a, t_stack **b)
{
	do_swap(a);
	do_swap(b);
}
