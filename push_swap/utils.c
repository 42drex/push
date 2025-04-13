/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 17:15:59 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-14 17:15:59 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return NULL;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*add_node_top(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (NULL);
	node = create_node(value);
	if (!node)
		return (NULL);
	if (!stack->top)
	{
		stack->top = node;
		stack->bot = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
	return (node);
}

t_node	*add_node_bot(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (NULL);
	node = create_node(value);
	if (!node)
		return (NULL);
	if (!stack->bot)
	{
		stack->top = node;
		stack->bot = node;
	}
	else
	{
		node->prev = stack->bot;
		stack->bot->next = node;
		stack->bot = node;
	}
	stack->size++;
	return (node);
}


/*void	print_stack(t_stack *stack, char *name)
{
	t_node	*tmp;

	printf("Stack %s (%d elements): ", name, stack->size);
	if (!stack || !stack->top)
	{
		printf("(empty)\n");
		return ;
	}
	tmp = stack->top;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
*/