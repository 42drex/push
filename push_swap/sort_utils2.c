/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 12:48:47 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-15 12:48:47 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_min_value(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max_value(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

static int	get_rotation_cost(int pos, int stack_size)
{
	if (pos <= stack_size / 2)
		return (pos);
	return (pos - stack_size);
}

t_cost	calculate_moves(t_stack *a, t_stack *b, int pos_b)
{
	t_cost	cost;
	int		pos_a;
	int		value;

	value = get_value_at_pos(b, pos_b);
	pos_a = get_target_pos(a, value);
	
	cost.moves_a = get_rotation_cost(pos_a, a->size);
	cost.moves_b = get_rotation_cost(pos_b, b->size);
	
	cost.total = abs(cost.moves_a) + abs(cost.moves_b);
	if ((cost.moves_a > 0 && cost.moves_b > 0)
		|| (cost.moves_a < 0 && cost.moves_b < 0))
	{
		if (abs(cost.moves_a) > abs(cost.moves_b))
			cost.total = abs(cost.moves_a);
		else
			cost.total = abs(cost.moves_b);
	}
	cost.total++;
	return (cost);
}
