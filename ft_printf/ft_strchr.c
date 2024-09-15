/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:22:57 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/16 11:35:09 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(char const *str, int ch)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == (char)ch)
			return ((char *)(str + i));
		i++;
	}
	if (*(str + i) == (char)ch)
		return ((char *)(str + i));
	else
		return (NULL);
}
