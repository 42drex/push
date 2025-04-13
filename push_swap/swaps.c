/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 17:56:58 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-14 17:56:58 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*tmp;
	int		tmp_value;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	tmp_value = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = tmp_value;
}

void	sa(t_stack *a)
{
	if (!a)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (!b)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
