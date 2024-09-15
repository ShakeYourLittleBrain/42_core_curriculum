/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:24:12 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/09 04:19:08 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max_node(*a);
	if (biggest_node == *a)
		rotate_a(a);
	else if ((*a)->next_node == biggest_node)
		rev_rotate_a(a);
	if ((*a)->value > (*a)->next_node->value)
		swap_a(a);
}
