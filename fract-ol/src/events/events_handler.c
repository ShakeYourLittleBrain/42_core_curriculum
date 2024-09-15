/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:05:38 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/06 21:06:57 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*frtl;
	double		zoom_factor;
	double		x_pos;
	double		y_pos;

	xdelta = ZERO;
	zoom_factor = ZERO;
	x_pos = 0;
	y_pos = 0;
	frtl = (t_fractol *)param;
	mlx_get_mouse_pos(frtl->mlx_instance, &frtl->x_pos, &frtl->y_pos);
	if (frtl->x_pos >= 0 && frtl->y_pos >= 0
		&& frtl->x_pos < (int32_t)frtl->image->width
		&& frtl->y_pos < (int32_t)frtl->image->height)
	{
		x_pos = frtl->x_pos * (frtl->horizontal_max - frtl->horizontal_min)
			/ frtl->image->width + frtl->horizontal_min;
		y_pos = frtl->y_pos * (frtl->vertical_max - frtl->vertical_min)
			/ frtl->image->height + frtl->vertical_min;
	}
	if (ydelta > 0)
		zoom_factor = 0.5;
	else if (ydelta < 0)
		zoom_factor = 1.5;
	infinite_scroll(frtl, zoom_factor, x_pos, y_pos);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frtl;

	frtl = (t_fractol *)param;
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN
			|| keydata.key == MLX_KEY_8 || keydata.key == MLX_KEY_2)
		&& keydata.action == MLX_PRESS)
		key_press_up_down(keydata, frtl);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT
			|| keydata.key == MLX_KEY_4 || keydata.key == MLX_KEY_6)
		&& keydata.action == MLX_PRESS)
		key_press_left_right(keydata, frtl);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (mlx_close_window(frtl->mlx_instance));
}

void	my_resizefunc(int32_t width, int32_t height, void *param)
{
	t_fractol	*frtl;

	frtl = (t_fractol *)param;
	mlx_delete_image(frtl->mlx_instance, frtl->image);
	frtl->image = mlx_new_image(frtl->mlx_instance, width, height);
	if (mlx_image_to_window(frtl->mlx_instance, frtl->image, 0, 0) == -1)
		return (mlx_close_window(frtl->mlx_instance), mlx_strerror(mlx_errno),
			exit(EXIT_FAILURE));
	if (frtl->title == 1)
		draw_julia((void *)param);
	else if (frtl->title == 2)
		draw_mand((void *)param);
	else if (frtl->title == 3)
		draw_tric((void *)param);
}
