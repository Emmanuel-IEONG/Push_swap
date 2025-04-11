/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:47 by eieong            #+#    #+#             */
/*   Updated: 2025/04/11 16:40:50 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/ft_printf.h"
# include "../libft/get_next_line_bonus.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef enum e_bool
{
	false,
	true
}				t_bool;

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

void	ft_cleaning(t_stack **a, int *tab);
void	ft_exit_err(t_stack **a, int *tab);

t_bool	add_in_stack(t_stack **a, char *value);
t_bool	arg_is_digit(char *str);
t_bool	check_one_arg(char **av, t_stack **a);
t_bool	check_args(int ac, char **av, t_stack **a);

t_bool	do_swap(t_stack **a);
void	do_ss(t_stack **a, t_stack **b);
void	do_pa(t_stack **a, t_stack **b);
void	do_pb(t_stack **a, t_stack **b);
t_bool	do_rotate(t_stack **a);
void	do_rr(t_stack **a, t_stack **b);
t_bool	do_rev_rotate(t_stack **a);
void	do_rrr(t_stack **a, t_stack **b);

void	clear_stack(t_stack **a);
int		ft_listsize(t_stack *lst);
t_stack	*ft_listlast(t_stack *lst);
t_stack	*ft_before_lstlast(t_stack *lst);
void	ft_listadd_back(t_stack **lst, t_stack *new);

long	ft_atol(const char *nptr);

int		*sort_stack_in_tab(t_stack **a);

t_bool	stack_sorted(t_stack *stack);

#endif
