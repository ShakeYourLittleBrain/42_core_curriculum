/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_b2a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:28:41 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/09 04:38:39 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	int				best_match_index;

	while (b)
	{
		current_a = a;
		best_match_index = INT_MAX;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next_node;
		}
		if (best_match_index == INT_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;
		b = b->next_node;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	node_indexing(a);
	node_indexing(b);
	set_target_b(a, b);
}
