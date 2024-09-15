/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:50:55 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/12 01:03:42 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	ft_split_len(char **split_args)
{
	int	i;

	i = 0;
	if (!split_args)
		return (0);
	while (split_args[i])
		i++;
	return (i);
}

void	ft_free_2d(void **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	ft_print_2d(void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}

int	check_is_numeric(char **split_args_2)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (split_args_2[i])
	{
		j = 0;
		while (split_args_2[i][j])
		{
			c = split_args_2[i][j];
			if (c != '.' && c != '-' && c != ',' && c != '+' && c != ' '
				&& c != '\0' && c != '\n' && c != '\t' && c != '\r')
			{
				if (ft_isdigit(c) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
