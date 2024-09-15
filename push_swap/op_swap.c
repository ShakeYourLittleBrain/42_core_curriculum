/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 03:52:17 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/11 00:29:54 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head_node)
{
	if (!*head_node || !(*head_node)->next_node)
		return ;
	*head_node = (*head_node)->next_node;
	(*head_node)->prev_node->prev_node = *head_node;
	(*head_node)->prev_node->next_node = (*head_node)->next_node;
	if ((*head_node)->next_node)
		(*head_node)->next_node->prev_node = (*head_node)->prev_node;
	(*head_node)->next_node = (*head_node)->prev_node;
	(*head_node)->prev_node = NULL;
}

void	swap_a(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
