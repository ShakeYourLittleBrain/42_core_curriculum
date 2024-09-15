/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prep_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:01:24 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/11 18:58:05 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	init_minirt_mlx(t_miniRT **miniRT)
{
	(*miniRT)->mlx_instance = NULL;
	(*miniRT)->image = NULL;
	(*miniRT)->mlx_instance = (mlx_t *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(mlx_t));
	(*miniRT)->image = (mlx_image_t *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(mlx_image_t));
	(*miniRT)->mlx_instance = mlx_init(WIDTH, HEIGHT, NAME, true);
	if (!(*miniRT)->mlx_instance)
		return (mlx_strerror(mlx_errno),
			throw_error("Error\nMlx instance failed\n", NULL, 1), 0);
	(*miniRT)->image = mlx_new_image((*miniRT)->mlx_instance, WIDTH, HEIGHT);
	if (!(*miniRT)->image)
		return (mlx_strerror(mlx_errno),
			throw_error("Error\nMlx image failed\n", NULL, 1), 0);
	if (mlx_image_to_window((*miniRT)->mlx_instance, (*miniRT)->image, 0, 0) == \
		-1)
		return (mlx_close_window((*miniRT)->mlx_instance),
			mlx_strerror(mlx_errno), throw_error("Mlx window failed\n", NULL,
				1), 0);
	return (1);
}

void	init_minirt(t_miniRT **miniRT)
{
	*miniRT = (t_miniRT *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(t_miniRT));
	(*miniRT)->objects_head = NULL;
	(*miniRT)->camera = (t_camera *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(t_camera));
	(*miniRT)->amb_light = (t_amb_light *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(t_amb_light));
	(*miniRT)->plane = (t_plane *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(t_plane));
	(*miniRT)->light = (t_light *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(t_light));
	(*miniRT)->m_cofactor = (t_mat_4 *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(t_mat_4));
	(*miniRT)->m_indentifier = (t_mat_4 *)ft_gc_malloc_check_and_add(get_gc(),
			sizeof(t_mat_4));
	init_minirt_matrix_co(&(*miniRT)->m_cofactor);
	init_minirt_matrix_id(&(*miniRT)->m_indentifier);
	(*miniRT)->camera_flag = 0;
	(*miniRT)->amb_light_flag = 0;
	(*miniRT)->plane_flag = 0;
	(*miniRT)->light_flag = 0;
}

void	init_minirt_matrix_id(t_mat_4 **m_indentifier)
{
	(*m_indentifier)->mat[0][0] = 1;
	(*m_indentifier)->mat[0][1] = 0;
	(*m_indentifier)->mat[0][2] = 0;
	(*m_indentifier)->mat[0][3] = 0;
	(*m_indentifier)->mat[1][0] = 0;
	(*m_indentifier)->mat[1][1] = 1;
	(*m_indentifier)->mat[1][2] = 0;
	(*m_indentifier)->mat[1][3] = 0;
	(*m_indentifier)->mat[2][0] = 0;
	(*m_indentifier)->mat[2][1] = 0;
	(*m_indentifier)->mat[2][2] = 1;
	(*m_indentifier)->mat[2][3] = 0;
	(*m_indentifier)->mat[3][0] = 0;
	(*m_indentifier)->mat[3][1] = 0;
	(*m_indentifier)->mat[3][2] = 0;
	(*m_indentifier)->mat[3][3] = 1;
}

void	init_minirt_matrix_co(t_mat_4 **m_cofactor)
{
	(*m_cofactor)->mat[0][0] = 1;
	(*m_cofactor)->mat[0][1] = -1;
	(*m_cofactor)->mat[0][2] = 1;
	(*m_cofactor)->mat[0][3] = -1;
	(*m_cofactor)->mat[1][0] = -1;
	(*m_cofactor)->mat[1][1] = 1;
	(*m_cofactor)->mat[1][2] = -1;
	(*m_cofactor)->mat[1][3] = 1;
	(*m_cofactor)->mat[2][0] = 1;
	(*m_cofactor)->mat[2][1] = -1;
	(*m_cofactor)->mat[2][2] = 1;
	(*m_cofactor)->mat[2][3] = -1;
	(*m_cofactor)->mat[3][0] = 1;
	(*m_cofactor)->mat[3][1] = -1;
	(*m_cofactor)->mat[3][2] = 1;
	(*m_cofactor)->mat[3][3] = -1;
}

void	prep_scene(t_miniRT **miniRT, char *filename)
{
	if (read_scene_file(filename, miniRT) == 0)
		return (throw_error("Error\nFailed to read scene file\n", NULL, 1),
			ft_gc_free(get_gc()), exit(EXIT_FAILURE));
	if (!init_minirt_mlx(&(*miniRT)))
		return (ft_gc_free(get_gc()), exit(EXIT_FAILURE));
}

/*
The Valgrind output indicates that there are no "definitely lost" or
"indirectly lost" bytes,which means there are no leaks directly caused
by your code's allocations that were not freed. However, it reports
"still reachable" memory, which typically means that allocated memory
 was not freed but still has pointers pointing to it (hence, not a leak
  in the strict sense since it could technically still be freed).

The "still reachable" memory is often related to system libraries or
frameworks that allocate memory for their internal use and may not free
 it until the program exits. This is common with libraries that
  initialize themselves once and expect to be used until the program
  terminates. In your case, the allocations are coming from the X11
  library and GLFW (used by your mlx library for window management).

To address the "Error Mlx instance failed" message, it's not directly
 related to the memory still reachable but indicates a failure in
 initializing the MLX instance. This could be due to a variety of
 reasons such as:

Incorrect installation or configuration of the MLX library.
Lack of necessary permissions or resources to create a window.
Incompatibility issues with the system's graphical environment.
*/
