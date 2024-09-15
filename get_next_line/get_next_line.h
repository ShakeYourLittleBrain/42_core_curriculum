/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:49:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/21 19:23:01 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	create_stack(int fd, t_list **stack);
void	add_to_stack(t_list **stack, char *buffer);
char	*get_line_str(t_list *stack);
void	clear_stack(t_list **stack);
int		has_next_line_chr(t_list *stack);
t_list	*ft_lstlast(t_list *stack);
int		next_char_point(t_list *stack);
void	clear_satck_up2_next_chr(t_list **stack, t_list *after_next_node,
			char *line_after_next_chr);
void	join_str(char *line, char *content, int *length, int *line_index);

#endif
