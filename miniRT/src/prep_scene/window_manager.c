/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:49:01 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/09 03:32:58 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/*
**	Initializes the camera settings
	**The aspect ratio is the ratio of the image width
		to the image height. This is important because it ensures that the image
		does not appear stretched or squished. It maintains the correct
		proportions of the scene being rendered.
		=>aspect ratio = width / height
	**The viewport height is the height of the camera's view plane.
		The viewport height is calculated based on the field of view (FOV)
		of the camera.The FOV is the extent of the observable world seen through
			the camera at any given moment. By using the tangent of half
			the FOV angle, you determine the height of the viewport in
			world units. This ensures that the scene's dimensions are
			proportional to the camera's FOV, providing a realistic perspective.
		=>viewport height = 2 * tan(fov * PI/360)
	**The viewport width is the width of the camera's view plane.
		The viewport width is then derived by multiplying the viewport height by
		the aspect ratio. This maintains the correct proportions between
		width and height based on the aspect ratio.
		=>viewport width = viewport height * aspect ratio
*/

void	init_cam_settings(t_miniRT **miniRT)
{
	(*miniRT)->camera->ap_ratio = (float)(*miniRT)->image->width
		/ (float)(*miniRT)->image->height;
	(*miniRT)->camera->vp_height = 2 * tan((*miniRT)->camera->fov * (M_PI
				/ 360));
	(*miniRT)->camera->vp_width = (*miniRT)->camera->vp_height
		* (*miniRT)->camera->ap_ratio;
	if (DEBUG)
	{
		printf("Aspect ratio: %f\n", (*miniRT)->camera->ap_ratio);
		printf("Viewport height: %f\n", (*miniRT)->camera->vp_height);
		printf("Viewport width: %f\n", (*miniRT)->camera->vp_width);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		if (DEBUG)
			printf("Escape key pressed\n");
		if (((t_miniRT *)param)->image)
			mlx_delete_image(((t_miniRT *)param)->mlx_instance,
				((t_miniRT *)param)->image);
		if (((t_miniRT *)param)->mlx_instance)
			mlx_close_window(((t_miniRT *)param)->mlx_instance);
		return (ft_gc_free(get_gc()), exit(EXIT_SUCCESS));
	}
}

void	resize(int32_t width, int32_t height, void *param)
{
	mlx_delete_image(((t_miniRT *)param)->mlx_instance,
		((t_miniRT *)param)->image);
	((t_miniRT *)param)->image = mlx_new_image(\
		((t_miniRT *)param)->mlx_instance, width, height);
	if (mlx_image_to_window(((t_miniRT *)param)->mlx_instance,
			((t_miniRT *)param)->image, 0, 0) == -1
		|| ((t_miniRT *)param)->image == NULL)
		return (mlx_close_window(((t_miniRT *)param)->mlx_instance),
			mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	scene_processor_engine((t_miniRT **)&param, 0);
}

void	prep_window(t_miniRT **miniRT)
{
	init_cam_settings(miniRT);
	if (DEBUG)
		print_camera((*miniRT)->camera);
	scene_processor_engine(&(*miniRT), 1);
	mlx_key_hook((*miniRT)->mlx_instance, key_hook, *miniRT);
	mlx_resize_hook((*miniRT)->mlx_instance, resize, *miniRT);
	mlx_loop_hook((*miniRT)->mlx_instance, ft_camera_hook, *miniRT);
	mlx_loop_hook((*miniRT)->mlx_instance, ft_light_hook, *miniRT);
	mlx_loop_hook((*miniRT)->mlx_instance, ft_object_hook, *miniRT);
	mlx_loop((*miniRT)->mlx_instance);
	mlx_terminate((*miniRT)->mlx_instance);
}
