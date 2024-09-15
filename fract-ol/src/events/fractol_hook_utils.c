/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:47:05 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/07 02:41:11 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	infinite_scroll(t_fractol *frtl, double zoom_factor, double x_pos,
		double y_pos)
{
	frtl->horizontal_min = x_pos + (frtl->horizontal_min - x_pos) * zoom_factor;
	frtl->horizontal_max = x_pos + (frtl->horizontal_max - x_pos) * zoom_factor;
	frtl->vertical_min = y_pos + (frtl->vertical_min - y_pos) * zoom_factor;
	frtl->vertical_max = y_pos + (frtl->vertical_max - y_pos) * zoom_factor;
}

/*
*the move events will work with the number key also up = 8 , down = 2
*/
void	key_press_up_down(mlx_key_data_t keydata, t_fractol *frtl)
{
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_8)
		&& keydata.action == MLX_PRESS)
	{
		frtl->vertical_min += (frtl->vertical_max - frtl->vertical_min)
			* MOVE_RATIO;
		frtl->vertical_max += (frtl->vertical_max - frtl->vertical_min)
			* MOVE_RATIO;
	}
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_2)
		&& keydata.action == MLX_PRESS)
	{
		frtl->vertical_min -= (frtl->vertical_max - frtl->vertical_min)
			* MOVE_RATIO;
		frtl->vertical_max -= (frtl->vertical_max - frtl->vertical_min)
			* MOVE_RATIO;
	}
}

/*
*the move events will work with the number key also left = 4 , right = 6
*/
void	key_press_left_right(mlx_key_data_t keydata, t_fractol *frtl)
{
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_4)
		&& keydata.action == MLX_PRESS)
	{
		frtl->horizontal_min += (frtl->horizontal_max - frtl->horizontal_min)
			* MOVE_RATIO;
		frtl->horizontal_max += (frtl->horizontal_max - frtl->horizontal_min)
			* MOVE_RATIO;
	}
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_6)
		&& keydata.action == MLX_PRESS)
	{
		frtl->horizontal_min -= (frtl->horizontal_max - frtl->horizontal_min)
			* MOVE_RATIO;
		frtl->horizontal_max -= (frtl->horizontal_max - frtl->horizontal_min)
			* MOVE_RATIO;
	}
}
