/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:47 by eieong            #+#    #+#             */
/*   Updated: 2025/03/25 13:30:10 by eieong           ###   ########.fr       */
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
	int				index;
	int				move_count;
	struct s_stack	*next;
}	t_stack;

#endif
