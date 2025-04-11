/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:32:55 by eieong            #+#    #+#             */
/*   Updated: 2025/04/11 17:40:46 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_bool	do_rotate(t_stack **a)
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

void	do_rr(t_stack **a, t_stack **b)
{
	do_rotate(a);
	do_rotate(b);
}

t_bool	do_rev_rotate(t_stack **a)
{
	t_stack	*bef_last;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return (false);
	bef_last = ft_before_lstlast(*a);
	last = ft_listlast(*a);
	bef_last->next = NULL;
	last->next = *a;
	*a = last;
	return (true);
}

void	do_rrr(t_stack **a, t_stack **b)
{
	do_rev_rotate(a);
	do_rev_rotate(b);
}
