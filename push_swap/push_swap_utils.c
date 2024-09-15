/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:19:56 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/10 20:32:11 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char const *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (*(str + i) && ft_check_space(*(str + i)))
		i++;
	sign = ft_check_sign((str + i), &i);
	while (*(str + i) && ft_check_digit(*(str + i)))
	{
		result = result * 10 + sign * (*(str + i) - '0');
		i++;
	}
	return (result);
}

int	ft_lstsize(t_stack_node *lst)
{
	int				i;
	t_stack_node	*current;

	i = 0;
	current = lst;
	while (current)
	{
		current = current->next_node;
		i++;
	}
	return (i);
}

size_t	str_len(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*subs;

	i = 0;
	if (start > str_len(s))
		len = 0;
	else if (len > (str_len(s) - start))
		len = str_len(s) - start;
	subs = (char *)(malloc(sizeof(char) * (len + 1)));
	if (!subs)
		return (NULL);
	while (len > 0 && *(s + start + i))
	{
		*(subs + i) = *(s + start + i);
		i++;
		len--;
	}
	*(subs + i) = '\0';
	return (subs);
}
