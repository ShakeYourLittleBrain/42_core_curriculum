/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:13:44 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/09 03:51:11 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = push_node->next_node;
	if (*src)
		(*src)->prev_node = NULL;
	if (!*dest)
	{
		*dest = push_node;
		push_node->next_node = NULL;
	}
	else
	{
		push_node->next_node = *dest;
		push_node->next_node->prev_node = push_node;
		*dest = push_node;
	}
}

void	push_to_a_from_b(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	push_to_b_from_a(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
