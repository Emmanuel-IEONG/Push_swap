/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:14:46 by eieong            #+#    #+#             */
/*   Updated: 2025/03/19 12:32:14 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->(*a)->next;
	(*a)->next = temp;
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	*b = (*b)->next;
	temp->(*b)->next;
	(*b)->next = temp;
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->(*a)->next;
	(*a)->next = temp;
	temp = *b;
	*b = (*b)->next;
	temp->(*b)->next;
	(*b)->next = temp;
	write(1, "ss\n", 3);
}

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
