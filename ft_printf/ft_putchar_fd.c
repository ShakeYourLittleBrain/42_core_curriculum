/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:41:31 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 12:22:10 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd, int *flag_error)
{
	int	temp;

	temp = 0;
	if (*flag_error == -1)
		return (-1);
	temp = write(fd, &c, 1);
	if (temp < 0)
	{
		*flag_error = -1;
		return (-1);
	}
	return (temp);
}
