/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_jul_prep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 05:59:11 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/06 21:09:38 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_julia_fractol_mlx_data(char *argv[], t_fractol *frtl_data_julia)
{
	frtl_data_julia->mlx_instance = mlx_init(WIDTH, HEIGHT, JULIA, true);
	if (!frtl_data_julia->mlx_instance)
		return (mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	frtl_data_julia->image = mlx_new_image(frtl_data_julia->mlx_instance, WIDTH,
			HEIGHT);
	if (!frtl_data_julia->image)
		return (mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	if (mlx_image_to_window(frtl_data_julia->mlx_instance,
			frtl_data_julia->image, 0, 0) == -1)
		return (mlx_close_window(frtl_data_julia->mlx_instance),
			mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
	frtl_data_julia->horizontal_max = H_MAX_J;
	frtl_data_julia->vertical_max = V_MAX_J;
	frtl_data_julia->horizontal_min = H_MIN_J;
	frtl_data_julia->vertical_min = V_MIN_J;
	frtl_data_julia->real_c = atof(argv[2]);
	frtl_data_julia->immg_c = atof(argv[3]);
	frtl_data_julia->title = 1;
}

void	init_fractol_jul_fin(t_fractol *frtl_data_julia)
{
	mlx_loop_hook(frtl_data_julia->mlx_instance, draw_julia, frtl_data_julia);
	mlx_resize_hook(frtl_data_julia->mlx_instance, my_resizefunc,
		frtl_data_julia);
	mlx_scroll_hook(frtl_data_julia->mlx_instance, my_scrollhook,
		frtl_data_julia);
	mlx_key_hook(frtl_data_julia->mlx_instance, my_keyhook, frtl_data_julia);
	mlx_loop(frtl_data_julia->mlx_instance);
	mlx_terminate(frtl_data_julia->mlx_instance);
}

void	draw_julia(void *param)
{
	double		horizontal;
	double		vertical;
	t_fractol	*f_j;

	f_j = (t_fractol *)param;
	vertical = ZERO;
	while (++vertical < f_j->image->height)
	{
		horizontal = ZERO;
		while (++horizontal < f_j->image->width)
		{
			f_j->real = f_j->horizontal_min + horizontal / f_j->image->width
				* (f_j->horizontal_max - f_j->horizontal_min);
			f_j->immg = f_j->vertical_min + vertical / f_j->image->height
				* (f_j->vertical_max - f_j->vertical_min);
			julia_values(f_j);
			f_j->clear = psychedelic_color(f_j->iteration);
			mlx_put_pixel(f_j->image, horizontal, vertical, f_j->clear);
		}
	}
}

/*
one of the tricky part as a beginner is that as the hooks are constantly
listenning to the changes that we make to our fractol's variables,
we must be careful how the value are manipulated and changing orders too

in this case i was having a problem trying not to create an extra
variable	temp_1;
*/
void	julia_values(t_fractol *frt_jul)
{
	double	temp_1;
	int		temp;

	temp = 0;
	while (temp < MAX_ITR && (power_x(frt_jul->real)
			+ power_x(frt_jul->immg)) <= 4)
	{
		temp_1 = (power_x(frt_jul->real) - power_x(frt_jul->immg))
			+ frt_jul->real_c;
		frt_jul->immg = (2 * frt_jul->real * frt_jul->immg) + frt_jul->immg_c;
		frt_jul->real = temp_1;
		temp++;
	}
	frt_jul->iteration = temp;
}
