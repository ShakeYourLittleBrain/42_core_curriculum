/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:55:24 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 12:11:40 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int val, int *flag_error)
{
	int	i;

	i = 0;
	if (val < 0)
		i += ft_putnbr_fd((val * -1), 1, flag_error);
	else
		i += ft_putnbr_fd(val, 1, flag_error);
	return (i);
}
