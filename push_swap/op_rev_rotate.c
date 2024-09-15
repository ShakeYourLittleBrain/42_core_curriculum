/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:52:42 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/09 03:51:04 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack_node **head_node)
{
	t_stack_node	*tail_node;

	if (!*head_node || !(*head_node)->next_node)
		return ;
	tail_node = ft_lstlast(*head_node);
	(tail_node->prev_node)->next_node = NULL;
	tail_node->next_node = *head_node;
	*head_node = tail_node;
	(tail_node->next_node)->prev_node = tail_node;
}

void	rev_rotate_a(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
