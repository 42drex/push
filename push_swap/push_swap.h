/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 12:42:11 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-15 12:42:11 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int		value;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}			t_stack;

typedef struct s_cost
{
	int	moves_a;
	int	moves_b;
	int	total;
}			t_cost;

t_stack	*init_stack(void);
void	free_stack(t_stack *stack);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
int		get_min_value(t_stack *stack);
int		get_max_value(t_stack *stack);
int		find_min_pos(t_stack *stack);
int		find_max_pos(t_stack *stack);
int		get_pos(t_stack *stack, int value);
int		get_target_pos(t_stack *stack, int value);
int		get_value_at_pos(t_stack *stack, int pos);
t_node	*add_node_bot(t_stack *stack, int value);
void	sort(t_stack *a, t_stack *b);
t_cost	calculate_moves(t_stack *a, t_stack *b, int pos_b);
void	sort_three(t_stack *a);
void	push_back(t_stack *a, t_stack *b);
void	push_init(t_stack *a, t_stack *b);
t_cost	find_cheapest(t_stack *a, t_stack *b);
void	exec_moves(t_stack *a, t_stack *b, t_cost cost);
int		add_node_top(t_stack *stack, int value);
int		parse_arguments(int argc, char **argv, t_stack *a);
#endif