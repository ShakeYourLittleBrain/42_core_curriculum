/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 03:52:53 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/10 03:13:53 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **head_node)

{
	t_stack_node	*tail_node;

	if (!*head_node || !(*head_node)->next_node)
		return ;
	tail_node = ft_lstlast(*head_node);
	tail_node->next_node = *head_node;
	*head_node = (*head_node)->next_node;
	(*head_node)->prev_node = NULL;
	(tail_node->next_node)->prev_node = tail_node;
	(tail_node->next_node)->next_node = NULL;
}

void	rotate_a(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
