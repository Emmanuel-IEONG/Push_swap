/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:42:21 by eieong            #+#    #+#             */
/*   Updated: 2025/04/22 11:17:16 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_bool	read_instruct(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (do_swap(a), true);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (do_swap(b), true);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		return (do_ss(a, b), true);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		return (do_pa(a, b), true);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (do_pb(a, b), true);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		return (do_rotate(a), true);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (do_rotate(b), true);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (do_rr(a, b), true);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (do_rev_rotate(a), true);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (do_rev_rotate(b), true);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (do_rrr(a, b), true);
	else
		return (false);
}

t_bool	stdinput(t_stack **a, t_stack **b)
{
	char	*line;
	
	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			break ;
		}
		if (ft_strlen(line) > 4 || !read_instruct(a, b, line))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (true);
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
	if (!stdinput(&a, &b))
	{
		clear_stack(&b);
		ft_exit_err(&a, sorted_tab);
	}
	if (stack_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clear_stack(&b);
	ft_cleaning(&a, sorted_tab);
	return (0);
}
