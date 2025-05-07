/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_index_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:47:06 by eieong            #+#    #+#             */
/*   Updated: 2025/04/10 15:25:00 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack **a)
{
	t_stack	*temp;
	int		max;

	temp = *a;
	max = INT_MIN;
	while (temp)
	{
		if (temp->nb > max)
			max = temp->nb;
		temp = temp->next;
	}
	return (max);
}

int	index_min(t_stack **a)
{
	t_stack	*temp;
	int		min;
	int		i;
	int		j;

	temp = *a;
	min = INT_MAX;
	i = 0;
	j = 0;
	while (temp)
	{
		if (temp->nb < min)
		{
			min = temp->nb;
			j = i;
		}
		i++;
		temp = temp->next;
	}
	return (j);
}

int	index_max(t_stack **a)
{
	t_stack	*temp;
	int		max;
	int		i;
	int		j;

	temp = *a;
	max = INT_MIN;
	i = 0;
	j = 0;
	while (temp)
	{
		if (temp->nb > max)
		{
			max = temp->nb;
			j = i;
		}
		i++;
		temp = temp->next;
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
