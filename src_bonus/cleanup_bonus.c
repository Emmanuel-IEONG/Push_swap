/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:38:05 by eieong            #+#    #+#             */
/*   Updated: 2025/04/11 17:46:49 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	clear_stack(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	*a = NULL;
}

void	ft_cleaning(t_stack **a, int *tab)
{
	if (*a)
		clear_stack(a);
	if (tab)
		free(tab);
}

void	ft_exit_err(t_stack **a, int *tab)
{
	write(2, "Error\n", 6);
	ft_cleaning(a, tab);
	exit(1);
}
