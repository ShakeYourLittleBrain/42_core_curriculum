/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_mov_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:28:31 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/25 01:11:17 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	ft_camera_hook(void *param)
{
	if ((mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_C)))
	{
		if (DEBUG)
			printf("Camera hook\n");
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
			((t_miniRT *)param)->camera->cord_vector.x_axis -= 0.5f;
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_LEFT))
			((t_miniRT *)param)->camera->cord_vector.x_axis += 0.5f;
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
			((t_miniRT *)param)->camera->cord_vector.y_axis -= 0.5f;
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_DOWN))
			((t_miniRT *)param)->camera->cord_vector.y_axis += 0.5f;
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_A))
			((t_miniRT *)param)->camera->norm_vector.x_axis -= 0.5f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_D))
			((t_miniRT *)param)->camera->norm_vector.x_axis += 0.5f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_W))
			((t_miniRT *)param)->camera->norm_vector.y_axis += 0.5f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_S))
			((t_miniRT *)param)->camera->norm_vector.y_axis -= 0.5f;
		scene_processor_engine(((t_miniRT **)&param), 0);
	}
}

void	ft_light_hook(void *param)
{
	if ((mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_L)))
	{
		if (DEBUG)
			printf("Light hook\n");
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_RIGHT))
			((t_miniRT *)param)->light->cord_vector.x_axis -= 2.1f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
				MLX_KEY_LEFT))
			((t_miniRT *)param)->light->cord_vector.x_axis += 2.1f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_UP))
			((t_miniRT *)param)->light->cord_vector.y_axis += 2.1f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance,
				MLX_KEY_DOWN))
			((t_miniRT *)param)->light->cord_vector.y_axis -= 2.1f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_A))
			((t_miniRT *)param)->light->cord_vector.z_axis -= 2.1f;
		else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_S))
			((t_miniRT *)param)->light->cord_vector.z_axis += 2.1f;
		scene_processor_engine(((t_miniRT **)&param), 0);
	}
}

void	move_object_hook(t_node_object *temp, void *param)
{
	if (temp->type == SPHERE)
	{
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_T))
			translate_sphere(temp, param);
	}
	else if (temp->type == PLANE)
	{
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_T))
			translate_plane(temp, param);
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_R))
			rotate_plane(temp, param);
	}
	else if (temp->type == CYLINDER)
	{
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_T))
			translate_cylinder(temp, param);
		if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_R))
			rotate_cylinder(temp, param);
	}
}

t_node_object	*find_object_by_id(t_node_object *head, int id)
{
	t_node_object	*temp;

	temp = head;
	while (temp)
	{
		if (temp->id == id)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	ft_object_hook(void *param)
{
	t_node_object	*temp;

	if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_0))
		temp = find_object_by_id(((t_miniRT *)param)->objects_head, 0);
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_1))
		temp = find_object_by_id(((t_miniRT *)param)->objects_head, 1);
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_2))
		temp = find_object_by_id(((t_miniRT *)param)->objects_head, 2);
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_3))
		temp = find_object_by_id(((t_miniRT *)param)->objects_head, 3);
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_4))
		temp = find_object_by_id(((t_miniRT *)param)->objects_head, 4);
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_5))
		temp = find_object_by_id(((t_miniRT *)param)->objects_head, 5);
	else if (mlx_is_key_down(((t_miniRT *)param)->mlx_instance, MLX_KEY_6))
		temp = find_object_by_id(((t_miniRT *)param)->objects_head, 6);
	else
		return ;
	if (temp)
		move_object_hook(temp, param);
	scene_processor_engine(((t_miniRT **)&param), 0);
}
