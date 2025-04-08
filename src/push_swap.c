/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:09:08 by eieong            #+#    #+#             */
/*   Updated: 2025/04/08 17:17:43 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void	add_in_stack(t_stack **a, char *value)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nb = ft_atoi(value);
	new->next = NULL;
	if (!*a)
		*a = new;
	else
		ft_listadd_back(*a, new);
}

/*	if ac = 2
		split, atoi, check int, check nb arg
	if ac > 2
		ac[i] : atoi, check int, -> stack*/

/*gerer pb atoi ("-" = 0, INT_MIN)*/
t_bool	check_one_arg(char **av, t_stack **a)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(av[1], ' ');
	if (!split)
		return (NULL);
	if (split[0] && !split[1])
		return (false);
	while (split[i])
	{
		add_in_stack(*a, split[i]);
		i++;
	}
	ft_freetab(split);
}

t_bool	check_args(int ac, char **av, t_stack **a)
{
	int	i;

	i = 0;
	while (i++ < ac - 1)
	{
		add_in_stack(*a, av[i]);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (!av[1][0] && ac == 2))
		return (1);
	else if (ac == 2)
		check_one_arg(av, a);
	else if (ac > 2)
		check_args(ac, av, a);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			do_sa(a);
		else if (ft_lstsize(a) == 3)
			// sort 3
		else if (ft_lstsize(a) == 4)
			// sort 4
		else if (ft_lstsize(a) == 5)
			// sort 5
		else
			// sort stack
	}
	free_stack(a);
	return (0);
}
