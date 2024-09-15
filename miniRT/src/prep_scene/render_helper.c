/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:01:10 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/17 22:15:00 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	c_v(t_vector vector)
{
	return (create_vector(vector.x_axis, vector.y_axis, vector.z_axis,
			vector.w_axis));
}

t_vector	create_vector(float x, float y, float z, float w)
{
	t_vector	vector;

	vector.x_axis = x;
	vector.y_axis = y;
	vector.z_axis = z;
	vector.w_axis = w;
	return (vector);
}

t_vector	get_viewport_point(t_camera *camera, int row, int col,
		mlx_image_t *image)
{
	return (create_vector((2.f * ((row + 0.5f) / (float)image->width) - 1.f)
			* (camera->vp_width / 2.f), (2.f * ((col + 0.5f)
					/ (float)image->height) - 1.f) * (camera->vp_height / 2.f),
			1.f, 1.f));
}

t_vector	init(t_vector a)
{
	return (vector_division(a, sqrt(dot_product(a, a))));
}

t_ray	create_ray(t_miniRT **miniRT, int row, int col)
{
	t_camera	*camera;
	t_dto		dto;

	camera = (*miniRT)->camera;
	dto.front_view = init(camera->norm_vector);
	dto.right_view = init((cross_product(dto.front_view, create_vector(0, -1, 0,
						0))));
	dto.up_view = cross_product(dto.right_view, dto.front_view);
	dto.viewport_point = get_viewport_point(camera, row, col, (*miniRT)->image);
	dto.viewport_point = vector_addition(vector_addition(vector_multiplication(\
				dto.right_view, dto.viewport_point.x_axis),
				vector_multiplication(dto.up_view, dto.viewport_point.y_axis)),
			vector_multiplication(dto.front_view, dto.viewport_point.z_axis));
	dto.ray_point = init((vector_subtraction(dto.viewport_point,
					camera->cord_vector)));
	return ((t_ray){c_v(camera->cord_vector),
		create_vector(dto.ray_point.x_axis, dto.ray_point.y_axis,
			dto.ray_point.z_axis, 0)});
}
