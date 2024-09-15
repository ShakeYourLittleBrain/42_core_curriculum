/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:08:48 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 12:13:13 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(long n, int fd, int *flag_error)
{
	int	i;

	i = 0;
	if (*flag_error == -1)
		return (-1);
	if (n == -2147483648)
	{
		i += ft_putchar_fd('-', fd, flag_error);
		i += ft_putchar_fd('2', fd, flag_error);
		n = 147483648;
	}
	if (n < 0)
	{
		i += ft_putchar_fd('-', fd, flag_error);
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd, flag_error);
		i += ft_putnbr_fd(n % 10, fd, flag_error);
	}
	else
		i += ft_putchar_fd(n + '0', fd, flag_error);
	return (i);
}

/*
 * if (fd == 2)
 * 		i+= ft_putchar_fd('+', 1);
 */
