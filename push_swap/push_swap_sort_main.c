/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 23:10:05 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/09 23:23:49 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->upper_middle && cheapest_node->target_node->upper_middle)
		sort_main_rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->upper_middle)
		&& !(cheapest_node->target_node->upper_middle))
		sort_main_rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 1);
	prep_for_push(b, cheapest_node->target_node, 0);
	push_to_b_from_a(a, b);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 1);
	push_to_a_from_b(a, b);
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->value != find_min_node(*a)->value)
	{
		if (find_min_node(*a)->upper_middle)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_to_b_from_a(&*a, &*b);
	if (len_a-- > 3 && !stack_sorted(*a))
		push_to_b_from_a(&*a, &*b);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	node_indexing(*a);
	min_on_top(a);
}
