/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrighi <alrighi@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-15 13:58:23 by alrighi           #+#    #+#             */
/*   Updated: 2025-02-15 13:58:23 by alrighi          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_arguments(int argc, char **argv, t_stack *a)
{
	int		i;
	int		value;

	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]); // Remplacez par une fonction de validation robuste
		if (add_node_bot(a, value) == NULL)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b || !parse_arguments(argc, argv, a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	if (!is_sorted(a))
		sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
