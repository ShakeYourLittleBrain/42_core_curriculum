/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prep_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:01:24 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/16 16:26:12 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init_minirt_mlx(t_miniRT **miniRT)
{
	(*miniRT)->mlx_instance = mlx_init(WIDTH, HEIGHT, NAME, true);
	if (!(*miniRT)->mlx_instance)
		return (mlx_strerror(mlx_errno),
			throw_error_exit("Error\nError\nMlx instance failed\n", miniRT, 1));
	(*miniRT)->image = mlx_new_image((*miniRT)->mlx_instance, WIDTH, HEIGHT);
	if (!(*miniRT)->image)
		return (mlx_strerror(mlx_errno),
			throw_error_exit("Error\nMlx image failed\n", miniRT, 1));
	if (mlx_image_to_window((*miniRT)->mlx_instance, (*miniRT)->image, 0, 0) == \
		-1)
		return (mlx_close_window((*miniRT)->mlx_instance),
			mlx_strerror(mlx_errno), throw_error_exit("Mlx window failed\n",
				miniRT, 1));
}

void	init_minirt(t_miniRT **miniRT)
{
	*miniRT = (t_miniRT *)malloc(sizeof(t_miniRT));
	if (!*miniRT)
		throw_error_exit("Error\nMemory allocation failed\n", miniRT, 1);
	init_minirt_mlx(&(*miniRT));
	(*miniRT)->objects_head = NULL;
	(*miniRT)->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!(*miniRT)->camera)
		throw_error_exit("Error\nMemory allocation failed\n", miniRT, 1);
	(*miniRT)->amb_light = (t_amb_light *)malloc(sizeof(t_amb_light));
	if (!(*miniRT)->amb_light)
		throw_error_exit("Error\nMemory allocation failed\n", miniRT, 1);
	(*miniRT)->plane = (t_plane *)malloc(sizeof(t_plane));
	if (!(*miniRT)->plane)
		throw_error_exit("Error\nMemory allocation failed\n", miniRT, 1);
	(*miniRT)->light = (t_light *)malloc(sizeof(t_light));
	if (!(*miniRT)->light)
		throw_error_exit("Error\nMemory allocation failed\n", miniRT, 1);
	(*miniRT)->m_cofactor = (t_mat_4 *)malloc(sizeof(t_mat_4));
	if (!(*miniRT)->m_cofactor)
		throw_error_exit("Error\nMemory allocation failed\n", miniRT, 1);
	(*miniRT)->m_indentifier = (t_mat_4 *)malloc(sizeof(t_mat_4));
	if (!(*miniRT)->m_indentifier)
		throw_error_exit("Error\nMemory allocation failed\n", miniRT, 1);
	init_minirt_matrix_co(&(*miniRT)->m_cofactor);
	init_minirt_matrix_id(&(*miniRT)->m_indentifier);
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
		throw_error_exit("Error\nFailed to read scene file\n", miniRT, 1);
}
