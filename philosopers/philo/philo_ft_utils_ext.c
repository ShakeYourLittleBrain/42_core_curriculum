/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ft_utils_ext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 01:57:10 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/11 01:57:56 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_digit(int ch)
{
	if (ch > 47 && ch < 58)
		return (1);
	return (0);
}

long	ft_atol(char *str)
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
