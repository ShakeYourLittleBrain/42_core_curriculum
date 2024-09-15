/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:49:01 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/24 22:26:59 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/*
	**	Initializes the camera settings
	ap_ratio - aspect ratio of the camera


*/

void	ft_camera_hook(void *param)
{
	if ((mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_C)))
	{
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
			((t_miniRT *)param)->camera->cord_vector.x_axis -= 0.1f;
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_LEFT))
			((t_miniRT *)param)->camera->cord_vector.x_axis += 0.1f;
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
			((t_miniRT *)param)->camera->cord_vector.y_axis -= 0.1f;
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_DOWN))
			((t_miniRT *)param)->camera->cord_vector.y_axis += 0.1f;
		scene_processor_engine(((t_miniRT **)&param), 0);
	}
}

void	init_cam_settings(t_miniRT **miniRT)
{
	(*miniRT)->camera->ap_ratio = (float)(*miniRT)->image->width
		/ (float)(*miniRT)->image->height;
	(*miniRT)->camera->vp_height = 2.f * tan((*miniRT)->camera->fov * M_PI
			/ 360);
	(*miniRT)->camera->vp_width = (*miniRT)->camera->vp_height
		* (*miniRT)->camera->ap_ratio;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		if (((t_miniRT *)param)->image)
			mlx_delete_image(((t_miniRT *)param)->mlx_instance,
				((t_miniRT *)param)->image);
		if (((t_miniRT *)param)->mlx_instance)
			mlx_terminate(((t_miniRT *)param)->mlx_instance);
		exit(EXIT_SUCCESS);
	}
}

void	prep_window(t_miniRT **miniRT)
{
	init_cam_settings(miniRT);
	scene_processor_engine(&(*miniRT), 1);
	mlx_key_hook((*miniRT)->mlx_instance, key_hook, *miniRT);
	mlx_loop_hook((*miniRT)->mlx_instance, ft_camera_hook, *miniRT);
	mlx_loop((*miniRT)->mlx_instance);
	mlx_terminate((*miniRT)->mlx_instance);
}
