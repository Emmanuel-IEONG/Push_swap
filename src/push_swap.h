/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:47 by eieong            #+#    #+#             */
/*   Updated: 2025/04/08 16:34:37 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/ft_printf.h"
#include "../libft/get_next_line_bonus.h"
#include "../libft/libft.h"

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

void	do_sa(t_stack **a);
void	do_sb(t_stack **b);
void	do_ss(t_stack **a, t_stack **b);
void	do_pa(t_stack **a, t_stack **b);
void	do_pb(t_stack **a, t_stack **b);
void	do_ra(t_stack **a);
void	do_rb(t_stack **b);
void	do_rr(t_stack **a, t_stack **b);
void	do_rra(t_stack **a);
void	do_rrb(t_stack **b);
void	do_rrr(t_stack **a, t_stack **b);

t_stack	*ft_listlast(t_stack *lst);
t_stack	*ft_before_lstlast(t_stack *lst);
void	ft_listadd_back(t_stack **lst, t_stack *new);

#endif
