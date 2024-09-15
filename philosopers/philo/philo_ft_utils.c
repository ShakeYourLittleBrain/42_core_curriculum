/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:53:08 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/14 01:07:45 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char *str)
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

int	is_in_int_range(char *str)
{
	if (ft_atol(str) >= -2147483648 && ft_atol(str) <= 2147483647)
		return (1);
	return (0);
}

int	is_integer(char *argv)
{
	if (!is_digit(argv) || !is_in_int_range(argv))
		return (0);
	return (1);
}

int	ft_check_sign(char *str, int *index)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (*(str + i) && (*(str + i) == '-' || *(str + i) == '+'))
	{
		if (*(str + i) == '-')
			sign *= -1;
		*index = *index + 1;
		i++;
	}
	return (sign);
}

int	ft_check_space(int ch)
{
	if ((ch && ch == ' ') || ((ch >= 9 && ch <= 13)))
		return (1);
	return (0);
}
