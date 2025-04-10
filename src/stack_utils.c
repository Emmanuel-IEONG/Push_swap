/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:40:02 by eieong            #+#    #+#             */
/*   Updated: 2025/04/10 15:22:37 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack **a)
{
	t_stack	*temp;

	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	*a = NULL;
}

int	ft_listsize(t_stack *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_stack	*ft_listlast(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_before_lstlast(t_stack *lst)
{
	t_stack	*bef_last;

	bef_last = NULL;
	if (lst)
	{
		while (lst->next)
		{
			bef_last = lst;
			lst = lst->next;
		}
	}
	return (bef_last);
}

void	ft_listadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst)
	{
		temp = ft_listlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}
