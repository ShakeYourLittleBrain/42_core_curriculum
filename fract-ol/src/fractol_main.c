/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:48:06 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/06 21:07:43 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	frtl_data;
	int			fractol_num;

	fractol_num = 0;
	fractol_num = input_error_check(argc, argv);
	if (fractol_num == 1)
	{
		init_julia_fractol_mlx_data(argv, &frtl_data);
		init_fractol_jul_fin(&frtl_data);
	}
	else if (fractol_num == 2)
	{
		init_mand_fractol_mlx_data(&frtl_data);
		init_fractol_mand_fin(&frtl_data);
	}
	else if (fractol_num == 3)
	{
		init_fractol_tric_data(&frtl_data);
		init_fractol_tric_fin(&frtl_data);
	}
	return (EXIT_SUCCESS);
}
