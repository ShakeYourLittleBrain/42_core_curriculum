/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 03:14:19 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/24 21:45:55 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_miniRT	*mini_rt;

	(void)envp;
	input_validation(argc, argv);
	init_minirt(&mini_rt);
	prep_scene(&mini_rt, argv[1]);
	if (DEBUG)
		print_objects(mini_rt->objects_head);
	prep_window(&mini_rt);

	// mlx_loop_hook(mini_rt->mlx_instance, rotate_camera, mini_rt);
	// mlx_loop_hook(mini_rt->mlx_instance, translate_light, mini_rt);
	// mlx_loop_hook(mini_rt->mlx_instance, move_objects, mini_rt);
	return (EXIT_SUCCESS);
}
