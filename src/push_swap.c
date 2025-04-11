/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:09:08 by eieong            #+#    #+#             */
/*   Updated: 2025/04/11 12:52:48 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	parsing(t_stack **a, int ac, char **av, int *sorted_tab)
{
	if (ac == 1)
		exit(1);
	else if (ac == 2)
	{
		if (!check_one_arg(av, a))
			ft_exit_err(a, sorted_tab);
	}
	else if (ac > 2)
	{
		if (!check_args(ac, av, a))
			ft_exit_err(a, sorted_tab);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted_tab;

	a = NULL;
	b = NULL;
	sorted_tab = NULL;
	parsing(&a, ac, av, sorted_tab);
	sorted_tab = sort_stack_in_tab(&a);
	if (!sorted_tab)
		ft_exit_err(&a, sorted_tab);
	if (!stack_sorted(a))
		sort_stack(&a, &b, sorted_tab);
	ft_cleaning(&a, sorted_tab);
	return (0);
}
