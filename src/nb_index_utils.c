/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_index_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:47:06 by eieong            #+#    #+#             */
/*   Updated: 2025/04/09 15:56:40 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack **a)
{
	int	max;

	max = INT_MIN;
	while (*a)
	{
		if((*a)->nb > max)
			max = (*a)->nb;
		(*a) = (*a)->next;
	}
	return (max);
}

int	index_min(t_stack **a)
{
	int	min;
	int	i;
	int	j;
	
	min = INT_MAX;
	i = 0;
	j = 0;
	while (*a)
	{
		if ((*a)->nb < min)
		{
			min = (*a)->nb;
			j = i;
		}
		i++;
		(*a) = (*a)->next;
	}
	return (j);
}

int	index_max(t_stack **a)
{
	int	max;
	int	i;
	int	j;
	
	max = INT_MIN;
	i = 0;
	j = 0;
	while (*a)
	{
		if ((*a)->nb > max)
		{
			max = (*a)->nb;
			j = i;
		}
		i++;
		(*a) = (*a)->next;
	}
	return (j);
}

int	get_index_tab(int *sorted_tab, int size, int nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb == sorted_tab[i])
			return (i);
		i++;
	}
	return (i);
}

long	ft_atol(const char *nptr)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}
