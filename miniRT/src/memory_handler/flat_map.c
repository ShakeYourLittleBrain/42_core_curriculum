/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:32:15 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/01 00:39:46 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	map_2d_ptr_to_1d_ptr(t_gc **gc, void **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_gc_add(gc, array[i]);
		i++;
	}
	ft_gc_add(gc, array);
}
