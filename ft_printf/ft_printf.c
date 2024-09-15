/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:50:54 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 13:01:18 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main_printf(const char *str_to_frmt, va_list args)
{
	int	i;
	int	length;
	int	flag_error;

	length = 0;
	i = 0;
	flag_error = 0;
	while (*(str_to_frmt + i) && *(str_to_frmt + i) != '\0')
	{
		if (*(str_to_frmt + i) == '%'
			&& ft_strchr("cspdiuoxX%", *(str_to_frmt + i + 1)))
		{
			length += ft_get_formated_str(args, *(str_to_frmt + i + 1),
					&flag_error);
			i++;
		}
		else
			length += ft_putchar_fd(*(str_to_frmt + i), 1, &flag_error);
		i++;
		if (flag_error != 0)
			return (-1);
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		tot_num_chr;

	tot_num_chr = 0;
	va_start(args, str);
	tot_num_chr = main_printf(str, args);
	va_end(args);
	return (tot_num_chr);
}

/*
 * else if (*(str_to_frmt + i) == '%'
    && ft_strchr("#", *(str_to_frmt + i + 1))
    && ft_strchr("oxX", *(str_to_frmt + i + 2)))
{
    if (ft_strchr("o", *(str_to_frmt + i + 2)))
        length += ft_putchar_fd('0', 1);
    if (ft_strchr("x", *(str_to_frmt + i + 2)))
        length += ft_putstr_fd("0x", 1);
    if (ft_strchr("X", *(str_to_frmt + i + 2)))
        length += ft_putstr_fd("0X", 1);
    length += ft_get_formated_str(args, *(str_to_frmt + i + 2));
    i += 2;
}
 else if (*(str_to_frmt + i) == '%'
 	&& ft_strchr("+", *(str_to_frmt + i + 1))
	&& ft_strchr("di", *(str_to_frmt + i + 2)))
{
	length += ft_get_formated_str(args, *(str_to_frmt + i + 2));
	i += 2;
}
*/
