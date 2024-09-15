/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:09:34 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/10 00:48:13 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **head, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!head)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next_node = NULL;
	node->value = n;
	if (!(*head))
	{
		*head = node;
		node->prev_node = NULL;
	}
	else
	{
		last_node = ft_lstlast(*head);
		last_node->next_node = node;
		node->prev_node = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char *argv[], int flag)
{
	int	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		append_node(a, n);
		i++;
	}
	if (flag)
		free_argv(argv);
}

t_stack_node	*get_cheapest(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->lowest_moves)
			return (head);
		head = head->next_node;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node,
		int is_stack_a)
{
	while (*stack != top_node)
	{
		if (is_stack_a)
		{
			if (top_node->upper_middle)
				rotate_a(stack);
			else
				rev_rotate_a(stack);
		}
		else if (!is_stack_a)
		{
			if (top_node->upper_middle)
				rotate_b(stack);
			else
				rev_rotate_b(stack);
		}
	}
}
