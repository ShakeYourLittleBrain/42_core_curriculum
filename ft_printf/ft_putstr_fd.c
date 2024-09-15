/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:00:33 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 12:59:43 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd, int *flag_error)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	if (!s)
	{
		temp = write(fd, "(null)", 6);
		if (temp < 0)
			*flag_error = -1;
		return (temp);
	}
	while (*(s + i) && *flag_error != -1)
	{
		temp = write(fd, (s + i), 1);
		if (temp < 0)
		{
			*flag_error = -1;
			return (-1);
		}
		i++;
	}
	return (i);
}
