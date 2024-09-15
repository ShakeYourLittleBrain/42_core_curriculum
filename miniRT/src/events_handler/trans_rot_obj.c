/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_rot_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:37:19 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/10 01:31:29 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	translate_plane(t_node_object *temp, void *param)
{
	if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
		temp->plane->plane_vector.x_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_LEFT))
		temp->plane->plane_vector.x_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
		temp->plane->plane_vector.y_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_DOWN))
		temp->plane->plane_vector.y_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_UP))
		temp->plane->plane_vector.z_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_DOWN))
		temp->plane->plane_vector.z_axis += 1.0f;
}

void	rotate_plane(t_node_object *temp, void *param)
{
	if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
		temp->plane->norm_vector.x_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_LEFT))
		temp->plane->norm_vector.x_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
		temp->plane->norm_vector.y_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_DOWN))
		temp->plane->norm_vector.y_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_UP))
		temp->plane->norm_vector.z_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_DOWN))
		temp->plane->norm_vector.z_axis += 1.0f;
}

void	translate_cylinder(t_node_object *temp, void *param)
{
	if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
		temp->cylinder->cord_vector.x_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_LEFT))
		temp->cylinder->cord_vector.x_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
		temp->cylinder->cord_vector.y_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_DOWN))
		temp->cylinder->cord_vector.y_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_UP))
		temp->cylinder->cord_vector.z_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_DOWN))
		temp->cylinder->cord_vector.z_axis += 1.0f;
}

void	rotate_cylinder(t_node_object *temp, void *param)
{
	if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
		temp->cylinder->norm_vector.x_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_LEFT))
		temp->cylinder->norm_vector.x_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
		temp->cylinder->norm_vector.y_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_DOWN))
		temp->cylinder->norm_vector.y_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_UP))
		temp->cylinder->norm_vector.z_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_DOWN))
		temp->cylinder->norm_vector.z_axis += 1.0f;
}

void	translate_sphere(t_node_object *temp, void *param)
{
	if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
		temp->sphere->cord_vector.x_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_LEFT))
		temp->sphere->cord_vector.x_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
		temp->sphere->cord_vector.y_axis += 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_DOWN))
		temp->sphere->cord_vector.y_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_UP))
		temp->sphere->cord_vector.z_axis -= 1.0f;
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
			MLX_KEY_PAGE_DOWN))
		temp->sphere->cord_vector.z_axis += 1.0f;
}
