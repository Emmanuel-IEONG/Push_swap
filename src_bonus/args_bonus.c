/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:15:28 by eieong            #+#    #+#             */
/*   Updated: 2025/04/28 11:33:31 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_bool	add_in_stack(t_stack **a, char *value)
{
	t_stack	*new;
	long	nb;

	new = malloc(sizeof(*new));
	if (!new)
		return (false);
	nb = ft_atol(value);
	if (nb < INT_MIN || nb > INT_MAX)
		return (free(new), false);
	new->nb = nb;
	new->next = NULL;
	if (!*a)
		*a = new;
	else
		ft_listadd_back(a, new);
	return (true);
}

t_bool	arg_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

t_bool	check_one_arg(char **av, t_stack **a)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(av[1], ' ');
	if (!split)
		return (false);
	if (!split[i])
		return (ft_freetab(split), false);
	while (split[i])
	{
		if (!arg_is_digit(split[i]))
			return (ft_freetab(split), false);
		if (!add_in_stack(a, split[i]))
			return (ft_freetab(split), false);
		i++;
	}
	ft_freetab(split);
	return (true);
}

t_bool	check_args(int ac, char **av, t_stack **a)
{
	int	i;

	i = 0;
	while (i++ < ac - 1)
	{
		if (!arg_is_digit(av[i]))
			return (false);
		if (!add_in_stack(a, av[i]))
			return (false);
	}
	return (true);
}
