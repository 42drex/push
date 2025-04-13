/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 18:31:16 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-14 18:31:16 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2 || !stack->top)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	tmp->next = NULL;
	tmp->prev = stack->bot;
	stack->bot->next = tmp;
	stack->bot = tmp;
}

void	ra(t_stack *a)
{
	if (!a)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (!b)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
