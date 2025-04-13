/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 13:17:59 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-15 13:17:59 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_init(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2)
		return ;
	pb(a, b);
	pb(a, b);
}

t_cost	find_cheapest(t_stack *a, t_stack *b)
{
	t_cost	min_cost;
	t_cost	cost;
	int		pos;

	if (!a || !b || !b->top)
		return ((t_cost){0, 0, -1});
	pos = 0;
	min_cost = calculate_moves(a, b, 0);
	while (pos < b->size)
	{
		cost = calculate_moves(a, b, pos);
		if (cost.total < min_cost.total)
			min_cost = cost;
		pos++;
	}
	return (min_cost);
}

void	exec_moves(t_stack *a, t_stack *b, t_cost cost)
{
	int	moves_a;
	int	moves_b;
	
	moves_a = cost.moves_a;
	moves_b = cost.moves_b;
	
	while (moves_a > 0 && moves_b > 0)
	{
		rr(a, b);
		moves_a--;
		moves_b--;
	}
	while (moves_a < 0 && moves_b < 0)
	{
		rrr(a, b);
		moves_a++;
		moves_b++;
	}
	while (moves_a > 0)
	{
		ra(a);
		moves_a--;
	}
	while (moves_a < 0)
	{
		rra(a);
		moves_a++;
	}
	while (moves_b > 0)
	{
		rb(b);
		moves_b--;
	}
	while (moves_b < 0)
	{
		rrb(b);
		moves_b++;
	}
	pa(a, b);
}

void	push_back(t_stack *a, t_stack *b)
{
	t_cost	cost;
	int		pos;
	int		prev_size;

	while (b->size)
	{
		prev_size = b->size;
		cost = find_cheapest(a, b);
		exec_moves(a, b, cost);
		
		if (b->size >= prev_size && b->size > 0)
			pa(a, b);
	}
	pos = find_min_pos(a);
	if (pos < a->size / 2)
		while (pos--)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}

void	sort(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || is_sorted(a))
		return ;
	if (a->size <= 3)
	{
		sort_three(a);
		return ;
	}
	
	push_init(a, b);
	
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	
	push_back(a, b);
}
