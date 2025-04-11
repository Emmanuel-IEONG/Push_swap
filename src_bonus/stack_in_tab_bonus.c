/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_in_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:21:19 by eieong            #+#    #+#             */
/*   Updated: 2025/04/11 17:10:00 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_swap(int *a, int *b)
{
	int	hold;

	hold = *a;
	*a = *b;
	*b = hold;
}

static t_bool	ft_sort_int_tab(int *tab, int size)
{
	int	count;
	int	i;

	count = 0;
	while (count < size -1)
	{
		i = 0;
		while (i < size -1)
		{
			if (tab[i] == tab[i +1])
				return (false);
			if (tab[i] > tab[i +1])
				ft_swap(&tab[i], &tab[i +1]);
			else
				i++;
		}
		count++;
	}
	return (true);
}

int	*sort_stack_in_tab(t_stack **a)
{
	t_stack	*temp;
	int		*sorted_tab;
	int		i;

	i = 0;
	temp = *a;
	sorted_tab = malloc(sizeof(int) * ft_listsize(*a));
	if (!sorted_tab)
		return (NULL);
	while (temp)
	{
		sorted_tab[i] = temp->nb;
		i++;
		temp = temp->next;
	}
	if (!ft_sort_int_tab(sorted_tab, ft_listsize(*a)))
		return (free(sorted_tab), NULL);
	return (sorted_tab);
}
