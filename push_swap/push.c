/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 18:13:14 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-14 18:13:14 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (!src || !dst)
		return ;
	if (!src->top || src->size == 0)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bot = NULL;
	tmp->next = dst->top;
	tmp->prev = NULL;
	if (dst->top)
		dst->top->prev = tmp;
	else
		dst->bot = tmp;
	dst->top = tmp;
	dst->size++;
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}
