/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:15:28 by eieong            #+#    #+#             */
/*   Updated: 2025/04/11 12:31:55 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	add_in_stack(t_stack **a, char *value)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (false);
	new->nb = ft_atol(value);
	if (new->nb < INT_MIN || new->nb > INT_MAX)
		return (false);
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
		return (false);
	while (split[i])
	{
		if (!arg_is_digit(split[i]))
			return (false);
		if (!add_in_stack(a, split[i]))
			return (false);
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
