/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 19:00:44 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-14 19:00:44 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	t_node	*tmp;
	int		min;
	int		pos;
	int		min_pos;

	pos = 0;
	min_pos = 0;
	if (!stack || !stack->top)
		return (-1);
	tmp = stack->top;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

int	find_max_pos(t_stack *stack)
{
	t_node	*tmp;
	int		max;
	int		pos;
	int		max_pos;

	pos = 0;
	max_pos = 0;
	if (!stack || !stack->top)
		return (-1);
	tmp = stack->top;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

int	get_pos(t_stack *stack, int value)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	if (!stack || !stack->top)
		return (-1);
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

int	get_value_at_pos(t_stack *stack, int pos)
{
	t_node	*tmp;
	int		i;

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	i = 0;
	while (tmp && i < pos)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp)
		return (tmp->value);
	return (0);
}

int	get_target_pos(t_stack *stack, int value)
{
	int		pos;
	t_node	*tmp;
	int		min_pos;
	int		max_pos;

	if (!stack || !stack->top)
		return (0);
	
	min_pos = find_min_pos(stack);
	max_pos = find_max_pos(stack);
	
	if (value < get_value_at_pos(stack, min_pos))
		return (min_pos);
	
	if (value > get_value_at_pos(stack, max_pos))
		return ((max_pos + 1) % stack->size);
	
	pos = 0;
	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (value > tmp->value && value < tmp->next->value)
			return (pos + 1);
		pos++;
		tmp = tmp->next;
	}
	
	return (0);
}
