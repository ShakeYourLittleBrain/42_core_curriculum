/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:49:16 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 16:06:33 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_to_stack(t_list **stack, char *buffer)
{
	t_list	*last_node;
	t_list	*next_node;

	last_node = NULL;
	next_node = NULL;
	next_node = (t_list *) malloc(sizeof(t_list));
	if (!next_node)
		clear_satck_up2_next_chr(stack, NULL, buffer);
	next_node->content = buffer;
	next_node->next = NULL;
	last_node = ft_lstlast(*stack);
	if (!last_node)
		*stack = next_node;
	else
		last_node->next = next_node;
}

void	create_stack(int fd, t_list **stack)
{
	int		length;
	char	*buffer;
	int		flag;

	flag = 0;
	while (flag == 0)
	{
		if (has_next_line_chr(*stack))
		{
			flag = 1;
			return ;
		}
		buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			clear_satck_up2_next_chr(stack, NULL, NULL);
		length = read(fd, buffer, BUFFER_SIZE);
		if (!length)
		{
			free(buffer);
			return ;
		}
		*(buffer + length) = '\0';
		add_to_stack(stack, buffer);
	}
}

char	*get_line_str(t_list *stack)
{
	char	*line;
	int		length;
	int		line_index;

	line = NULL;
	length = 0;
	if (!stack)
		return (NULL);
	line_index = 0;
	length = next_char_point(stack);
	line = (char *) malloc(sizeof(char) * (length + 1));
	if (!line)
		return (NULL);
	*(line + length) = '\0';
	while (stack != NULL && length >= 0)
	{
		join_str(line, stack->content, &length, &line_index);
		stack = stack->next;
	}
	return (line);
}

void	clear_stack(t_list **stack)
{
	t_list	*last_node;
	t_list	*after_next_node;
	int		i;
	int		k;
	char	*line_after_next_chr;

	i = -1;
	k = 0;
	line_after_next_chr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	after_next_node = (t_list *)malloc(sizeof(t_list));
	if (!after_next_node && line_after_next_chr)
		clear_satck_up2_next_chr(stack, NULL, line_after_next_chr);
	if (!line_after_next_chr && after_next_node)
		clear_satck_up2_next_chr(stack, after_next_node, NULL);
	last_node = ft_lstlast(*stack);
	while (*(last_node->content + ++i) && *(last_node->content + i) != '\n')
		;
	while (*(last_node->content + i) && *(last_node->content + ++i))
		*(line_after_next_chr + k++) = *(last_node->content + i);
	*(line_after_next_chr + k) = '\0';
	after_next_node->content = line_after_next_chr;
	after_next_node->next = NULL;
	clear_satck_up2_next_chr(stack, after_next_node, line_after_next_chr);
}

char	*get_next_line(int fd)
{
	static t_list	*stack;
	t_list			*temp;
	char			*line;

	line = NULL;
	temp = NULL;
	if (fd < 0 || read(fd, &line, 0))
	{
		while (stack)
		{
			temp = (stack)->next;
			free((stack)->content);
			free(stack);
			stack = temp;
		}
		free(stack);
		return (NULL);
	}
	create_stack(fd, &stack);
	if (!stack)
		return (NULL);
	line = get_line_str(stack);
	clear_stack(&stack);
	return (line);
}
