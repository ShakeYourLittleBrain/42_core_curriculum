/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:42:51 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/24 21:37:57 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	ft_shadow_intersection(t_ray *ray, t_miniRT **mini_rt, float light_dist)
{
	t_node_object	*temp;
	t_node_object	*object;
	float			distance;

	temp = (*mini_rt)->objects_head;
	while (temp)
	{
		distance = INFINITY;
		object = NULL;
		if (temp->type == SPHERE)
			object = intersect_sphere(ray, temp, &distance);
		if (temp->type == CYLINDER)
			object = intersect_cylinder(ray, temp, &distance);
		if (object && distance > NEAR_ZERO && distance < light_dist)
			return (1);
		temp = temp->next;
	}
	return (0);
}

float	ft_shadow_intensity(t_miniRT **miniRT, t_vector intersection_point,
		t_vector intersection_normal)
{
	t_vector	shadow_offset;
	t_ray		shadow_ray;
	float		shadow_intensity;
	float		light_distance;

	light_distance = vector_magnitude(vector_subtraction(\
	(*miniRT)->light->cord_vector, intersection_point));
	if (light_distance < NEAR_ZERO)
		light_distance = NEAR_ZERO;
	shadow_offset.x_axis = fmin(1.0f / light_distance, 1.0f);
	shadow_offset.y_axis = fmin(1.0f / light_distance, 1.0f);
	shadow_offset.z_axis = fmin(1.0f / light_distance, 1.0f);
	shadow_ray.cord_vector = vector_addition(intersection_point,
			vector_multiplication(intersection_normal, 1e-4));
	shadow_ray.direction = vector_normalisation(vector_addition(\
	vector_subtraction((*miniRT)->light->cord_vector, intersection_point), \
	shadow_offset));
	shadow_intensity = 0.f;
	if (ft_shadow_intersection(&shadow_ray, miniRT, light_distance))
		shadow_intensity++;
	shadow_intensity = 1.0f - shadow_intensity;
	return (shadow_intensity);
}

t_color	ft_shadow(t_miniRT **miniRT, t_vector intersection_point,
		t_vector intersection_normal, t_color light)
{
	t_color	result;
	float	shadow_intensity;

	shadow_intensity = ft_shadow_intensity(miniRT, intersection_point,
			intersection_normal);
	result.red = fmin(255, light.red * shadow_intensity);
	result.green = fmin(255, light.green * shadow_intensity);
	result.blue = fmin(255, light.blue * shadow_intensity);
	return (result);
}
