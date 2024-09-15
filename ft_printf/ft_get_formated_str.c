/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_formated_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:07:53 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/26 13:10:49 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_formated_str(va_list args, const char format, int *flag_error)
{
	if (format == 'c')
		return (ft_putchar_fd((va_arg(args, int)), 1, flag_error));
	else if (format == 's')
		return (ft_putstr_fd((va_arg(args, char *)), 1, flag_error));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_fd((va_arg(args, int)), 1, flag_error));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", flag_error));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", flag_error));
	else if (format == 'o')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"01234567", flag_error));
	else if (format == 'p')
		return (ft_putaddress(va_arg(args, void *), flag_error));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int), flag_error));
	else if (format == '%')
		return (ft_putchar_fd('%', 1, flag_error));
	else
		return (-1);
}
/*
 * else if(format == 'd' || format == 'i')
 * 		return (ft_putnbr_fd((va_arg(args, int)), 2));
 * */
