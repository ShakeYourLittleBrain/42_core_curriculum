/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:10:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/19 00:13:12 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	print_camera(t_camera *camera)
{
	printf("Camera:\n");
	printf("Cord: %f %f %f\n", camera->cord_vector.x_axis,
		camera->cord_vector.y_axis, camera->cord_vector.z_axis);
	printf("Norm: %f %f %f\n", camera->norm_vector.x_axis,
		camera->norm_vector.y_axis, camera->norm_vector.z_axis);
	printf("FOV: %f\n", camera->fov);
}

void	print_light(t_light *light)
{
	printf("Light:\n");
	printf("Cord: %f %f %f\n", light->cord_vector.x_axis,
		light->cord_vector.y_axis, light->cord_vector.z_axis);
	printf("Brightness: %f\n", light->brightness);
	printf("Color: %d %d %d\n", light->color.red, light->color.green,
		light->color.blue);
}

void	print_ray(t_ray *ray)
{
	printf("Ray:\n");
	printf("Cord: %f %f %f\n", ray->cord_vector.x_axis,
		ray->cord_vector.y_axis, ray->cord_vector.z_axis);
	printf("Direction: %f %f %f\n", ray->direction.x_axis,
		ray->direction.y_axis, ray->direction.z_axis);
}

