/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_free_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:56:21 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/10 23:56:51 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	destroy_and_free_minirt(t_miniRT **miniRT)
{
	if (*miniRT)
	{
		if ((*miniRT)->mlx_instance)
			mlx_close_window((*miniRT)->mlx_instance);
		if ((*miniRT)->camera)
			free((*miniRT)->camera);
		if ((*miniRT)->amb_light)
			free((*miniRT)->amb_light);
		if ((*miniRT)->plane)
			free((*miniRT)->plane);
		free(*miniRT);
	}
}
