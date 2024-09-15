/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:45:23 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/26 13:08:58 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*(base + i) == '\0')
		return (0);
	else if (*(base + i + 1) == '\0')
		return (0);
	i = 0;
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_recurv_base_nb(unsigned long nbr, char *base,
		unsigned long size, int *count)
{
	char			a;
	unsigned long	index;
	int				b;

	if (nbr < 0 && *count != -1)
	{
		b = write(1, "-", 1);
		if (b == -1)
			return (-1);
		nbr = nbr * (-1);
	}
	if (nbr >= size && *count != -1)
		ft_recurv_base_nb(nbr / size, base, size, count);
	if (*count == -1)
		return (-1);
	index = nbr % size;
	a = *(base + index);
	b = write(1, &a, 1);
	if (b == -1)
	{
		*count = -1;
		return (-1);
	}
	*count += b;
	return (*count);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int *flag_error)
{
	unsigned long	base_size;
	int				count;

	base_size = 0;
	count = 0;
	if (ft_check_base(base) == 1)
	{
		while (base[base_size] != '\0')
			base_size++;
		count = (ft_recurv_base_nb(nbr, base, base_size, &count));
	}
	if (count == -1)
	{
		*flag_error = -1;
		return (-1);
	}
	return (count);
}
