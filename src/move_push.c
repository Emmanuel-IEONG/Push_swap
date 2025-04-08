/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:47:26 by eieong            #+#    #+#             */
/*   Updated: 2025/04/08 13:47:45 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	write(1, "pa\n", 3);
}

void	do_pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	write(1, "pb\n", 3);
}
