/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:14:46 by eieong            #+#    #+#             */
/*   Updated: 2025/04/08 16:23:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	do_swap(t_stack **a)
{
	int	temp;

	if (!(*a) || !(*a)->next)
		return (false);
	temp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = temp;
	return (true);
}

void	do_sa(t_stack **a)
{
	if (do_swap(a))
		write(1, "sa\n", 3);
}

void	do_sb(t_stack **b)
{
	if (do_swap(b))
		write(1, "sb\n", 3);
}	

void	do_ss(t_stack **a, t_stack **b)
{
	if (do_swap(a) && do_swap(b))
		write(1, "ss\n", 3);
}
