/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:45:14 by skhastag          #+#    #+#             */
/*   Updated: 2024/04/10 20:30:42 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(const char *str)
{
	int	i;

	i = 0;
	if (*(str + i) == '\0' || *(str + i) == '+' || *(str + i) == '-')
		i++;
	if (*(str + i) == '\0')
		return (0);
	while (*(str + i) != '\0')
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_in_int_range(const char *str)
{
	if (ft_atol(str) >= -2147483648 && ft_atol(str) <= 2147483647)
		return (1);
	return (0);
}

int	is_integers(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_integer(argv[i]) || !is_in_int_range(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_error(int argc, char *argv[])
{
	char	**temp;

	temp = NULL;
	if (argc == 1 || (argc == 2 && !argv[1]))
		return (0);
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (!is_integers(temp) || has_duplicates(temp))
			return (0);
	}
	else
	{
		if (!is_integers((argv + 1)) || has_duplicates((argv + 1)))
			return (0);
	}
	if (temp)
		free_argv(temp);
	return (1);
}
