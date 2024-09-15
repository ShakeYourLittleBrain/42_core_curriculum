/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_tric_prep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:10:06 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/07 02:30:54 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_fractol_tric_data(t_fractol *frtl_data_tric)
{
	frtl_data_tric->mlx_instance = mlx_init(WIDTH, HEIGHT, TRICON, true);
	if (!frtl_data_tric->mlx_instance)
		return (mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	frtl_data_tric->image = mlx_new_image(frtl_data_tric->mlx_instance, WIDTH,
			HEIGHT);
	if (!frtl_data_tric->image)
		return (mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	if (mlx_image_to_window(frtl_data_tric->mlx_instance, frtl_data_tric->image,
			0, 0) == -1)
		return (mlx_close_window(frtl_data_tric->mlx_instance),
			mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	frtl_data_tric->horizontal_min = H_MIN_T;
	frtl_data_tric->horizontal_max = H_MAX_T;
	frtl_data_tric->vertical_min = V_MIN_T;
	frtl_data_tric->vertical_max = V_MAX_T;
	frtl_data_tric->title = 3;
}

void	init_fractol_tric_fin(t_fractol *frtl_data_tric)
{
	mlx_loop_hook(frtl_data_tric->mlx_instance, draw_tric, frtl_data_tric);
	mlx_resize_hook(frtl_data_tric->mlx_instance, my_resizefunc,
		frtl_data_tric);
	mlx_scroll_hook(frtl_data_tric->mlx_instance, my_scrollhook,
		frtl_data_tric);
	mlx_key_hook(frtl_data_tric->mlx_instance, my_keyhook, frtl_data_tric);
	mlx_loop(frtl_data_tric->mlx_instance);
	mlx_terminate(frtl_data_tric->mlx_instance);
}

void	draw_tric(void *param)
{
	double		horizontal;
	double		vertical;
	t_fractol	*f_t;

	f_t = (t_fractol *)param;
	vertical = ZERO;
	while (++vertical < f_t->image->height)
	{
		horizontal = ZERO;
		while (++horizontal < f_t->image->width)
		{
			tric_init(f_t, horizontal, vertical);
			while (f_t->iteration < MAX_ITR && (power_x(f_t->real_z)
					+ power_x(f_t->immg_z)) <= MAN_TRI_VAL_LIMIT)
				tric_values(f_t);
			f_t->clear = psychedelic_color(f_t->iteration);
			mlx_put_pixel(f_t->image, horizontal, vertical, f_t->clear);
		}
	}
}

void	tric_init(t_fractol *f_t, double horiz, double vert)
{
	f_t->real_c = f_t->horizontal_min + horiz / f_t->image->width
		* (f_t->horizontal_max - f_t->horizontal_min);
	f_t->immg_c = f_t->vertical_min + vert / f_t->image->height
		* (f_t->vertical_max - f_t->vertical_min);
	f_t->iteration = ZERO;
	f_t->real_z = ZERO;
	f_t->immg_z = ZERO;
}

/*
one of the tricky part is that as the hooks are constantly
listenning to the changes that we make to our fractol's data,
we must be careful how the value are manipulated and changing orders too
*/
void	tric_values(t_fractol *f_t)
{
	double	temp;

	temp = power_x(f_t->real_z) - power_x(f_t->immg_z) + f_t->real_c;
	f_t->immg_z = -2 * f_t->real_z * f_t->immg_z + f_t->immg_c;
	f_t->real_z = temp;
	f_t->iteration++;
}
