/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_man_prep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:58:51 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/07 02:30:43 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_mand_fractol_mlx_data(t_fractol *frtl_data_mand)
{
	frtl_data_mand->mlx_instance = mlx_init(WIDTH, HEIGHT, MAND, true);
	if (!frtl_data_mand->mlx_instance)
		return (mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	frtl_data_mand->image = mlx_new_image(frtl_data_mand->mlx_instance, WIDTH,
			HEIGHT);
	if (!frtl_data_mand->image)
		return (mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	if (mlx_image_to_window(frtl_data_mand->mlx_instance, frtl_data_mand->image,
			0, 0) == -1)
		return (mlx_close_window(frtl_data_mand->mlx_instance),
			mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	frtl_data_mand->horizontal_min = H_MIN_M;
	frtl_data_mand->horizontal_max = H_MAX_M;
	frtl_data_mand->vertical_min = V_MIN_M;
	frtl_data_mand->vertical_max = V_MAX_M;
	frtl_data_mand->title = 2;
}

void	init_fractol_mand_fin(t_fractol *frtl_data_mand)
{
	mlx_loop_hook(frtl_data_mand->mlx_instance, draw_mand, frtl_data_mand);
	mlx_resize_hook(frtl_data_mand->mlx_instance, my_resizefunc,
		frtl_data_mand);
	mlx_scroll_hook(frtl_data_mand->mlx_instance, my_scrollhook,
		frtl_data_mand);
	mlx_key_hook(frtl_data_mand->mlx_instance, my_keyhook, frtl_data_mand);
	mlx_loop(frtl_data_mand->mlx_instance);
	mlx_terminate(frtl_data_mand->mlx_instance);
}

void	draw_mand(void *param)
{
	double		horizontal;
	double		vertical;
	t_fractol	*f_m;

	f_m = (t_fractol *)param;
	vertical = ZERO;
	while (++vertical < f_m->image->height)
	{
		horizontal = ZERO;
		while (++horizontal < f_m->image->width)
		{
			mand_init(f_m, horizontal, vertical);
			while (f_m->iteration < MAX_ITR && (power_x(f_m->real_z)
					+ power_x(f_m->immg_z)) <= MAN_TRI_VAL_LIMIT)
				mand_values(f_m);
			f_m->clear = psychedelic_color(f_m->iteration);
			mlx_put_pixel(f_m->image, horizontal, vertical, f_m->clear);
		}
	}
}

void	mand_init(t_fractol *f_m, double horiz, double vert)
{
	f_m->real_c = f_m->horizontal_min + horiz / f_m->image->width
		* (f_m->horizontal_max - f_m->horizontal_min);
	f_m->immg_c = f_m->vertical_min + vert / f_m->image->height
		* (f_m->vertical_max - f_m->vertical_min);
	f_m->iteration = ZERO;
	f_m->real_z = ZERO;
	f_m->immg_z = ZERO;
}

/*
one of the tricky part is that as the hooks are constantly
listenning to the changes that we make to our fractol's data,
we must be careful how the value are manipulated and changing orders too
*/
void	mand_values(t_fractol *f_m)
{
	double	temp;

	temp = power_x(f_m->real_z) - power_x(f_m->immg_z) + f_m->real_c;
	f_m->immg_z = 2 * f_m->real_z * f_m->immg_z + f_m->immg_c;
	f_m->real_z = temp;
	f_m->iteration++;
}
