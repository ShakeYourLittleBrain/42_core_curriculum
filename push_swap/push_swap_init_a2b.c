/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init_a2b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:04:35 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/09 04:36:36 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	int				closest_smaller_val;

	target_node = NULL;
	while (stack_a)
	{
		current_b = stack_b;
		closest_smaller_val = INT_MIN;
		while (current_b)
		{
			if (stack_a->value > current_b->value
				&& current_b->value > closest_smaller_val)
			{
				closest_smaller_val = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next_node;
		}
		if (closest_smaller_val == INT_MIN)
			stack_a->target_node = find_max_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next_node;
	}
}

void	cost_analysis_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->upper_middle))
			stack_a->push_cost = size_a - (stack_a->index);
		if (stack_a->target_node->upper_middle)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += size_b - (stack_a->target_node->index);
		stack_a = stack_a->next_node;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	int				cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = stack->push_cost;
	cheapest_node = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next_node;
	}
	cheapest_node->lowest_moves = 1;
}

void	init_nodes_a(t_stack_node *stack_a, t_stack_node *stack_b)
{
	node_indexing(stack_a);
	node_indexing(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
