/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:49:46 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 16:15:43 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_next_line_chr(t_list *stack)
{
	int	index;

	if (!stack)
		return (0);
	while (stack)
	{
		index = 0;
		while (*(stack->content + index) && *(stack->content + index) != '\0')
		{
			if (*(stack->content + index) == '\n')
				return (1);
			index++;
		}
		stack = stack->next;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	next_char_point(t_list *stack)
{
	int	index;
	int	index_1;
	int	flag;

	index_1 = 0;
	flag = 0;
	while (stack && flag == 0)
	{
		index = 0;
		while ((stack->content) && *((stack->content) + index) && flag == 0)
		{
			if (*((stack->content) + index) == '\n')
			{
				index_1++;
				flag = 1;
			}
			else
			{
				index++;
				index_1++;
			}
		}
		stack = stack->next;
	}
	return (index_1);
}

void	clear_satck_up2_next_chr(t_list **stack, t_list *after_next_node,
		char *line_after_next_chr)
{
	t_list	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
	if (after_next_node && *(after_next_node->content))
		*stack = after_next_node;
	else if (after_next_node && !line_after_next_chr)
		free(line_after_next_chr);
	else if (!after_next_node && line_after_next_chr)
		free(after_next_node);
	else
	{
		free(line_after_next_chr);
		free(after_next_node);
	}
}

void	join_str(char *line, char *content, int *length, int *line_index)
{
	int	content_index;

	content_index = 0;
	while (*(content + content_index) && *(content + content_index) != '\0'
		&& *line_index < *length)
	{
		if (*(content + content_index) == '\n')
		{
			*(line + *line_index) = '\n';
			*length = 0;
			return ;
		}
		*(line + *line_index) = *(content + content_index);
		content_index++;
		*line_index = *line_index + 1;
	}
}
