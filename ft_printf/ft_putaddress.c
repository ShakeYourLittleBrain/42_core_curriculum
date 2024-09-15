/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:13:45 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 12:23:46 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(void *ptr, int *flag_error)
{
	int	i;

	i = 0;
	if (ptr)
	{
		i += ft_putstr_fd("0x", 1, flag_error);
		if (*flag_error == -1)
			return (-1);
		i += ft_putnbr_base((unsigned long) ptr,
				"0123456789abcdef", flag_error);
		if (*flag_error == -1)
			return (-1);
	}
	else
		i += ft_putstr_fd("0x0", 1, flag_error);
	if (*flag_error == -1)
		return (-1);
	return (i);
}
