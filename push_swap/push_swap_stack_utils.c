/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:40:45 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/08 22:48:32 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next_node)
	{
		if (stack->value > stack->next_node->value)
			return (0);
		stack = stack->next_node;
	}
	return (1);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;

	if (stack == NULL)
		return (NULL);
	min_node = stack;
	while (stack != NULL)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next_node;
	}
	return (min_node);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (stack == NULL)
		return (NULL);
	max_node = stack;
	while (stack != NULL)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next_node;
	}
	return (max_node);
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next_node)
		lst = lst->next_node;
	return (lst);
}

void	node_indexing(t_stack_node *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (!stack)
		return ;
	middle = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->lowest_moves = 0;
		if (i <= middle)
			stack->upper_middle = 1;
		else
			stack->upper_middle = 0;
		stack = stack->next_node;
		++i;
	}
}
