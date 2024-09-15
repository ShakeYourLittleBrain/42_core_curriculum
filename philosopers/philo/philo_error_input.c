/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 01:36:12 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/05 01:22:38 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input_data(int argc, char *argv[])
{
	int	i;

	if (DEBUG)
		printf("\033[0;93mDEBUG :----------check_input_data() \
starts--------\033[0;39m\n");
	i = 0;
	if (argc != 5 && argc != 6)
	{
		print_error_exit(ERR, 1);
		return (0);
	}
	while (argv[++i])
	{
		if (!is_integer(argv[i]) || ft_atol(argv[i]) <= 0)
		{
			print_error_exit(get_error_string(i), 0);
			print_error_exit(ERR, 1);
			return (0);
		}
	}
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------check_input_data() \
end--------\033[0;39m\n");
	return (1);
}

void	print_error_exit(char *s, int flag)
{
	size_t	i;

	(void)flag;
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------print_error_exit() \
starts--------\033[0;39m\n");
	i = 0;
	while (*(s + i))
	{
		write(1, (s + i), 1);
		i++;
	}
	write(1, "\n", 1);
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------print_error_exit() \
end--------\033[0;39m\n");
}

char	*get_error_string(int i)
{
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------get_error_string() \
starts--------\033[0;39m\n");
	if (i == 1)
		return (ERR_ARG_1);
	else if (i == 2)
		return (ERR_ARG_2);
	else if (i == 3)
		return (ERR_ARG_3);
	else if (i == 4)
		return (ERR_ARG_4);
	else if (i == 5)
		return (ERR_ARG_5);
	else
		return (NULL);
}
