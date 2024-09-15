/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:01:10 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/26 04:55:43 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/*
	Will create a ray from the camera to the viewport point.

	Initialize view vectors:

	**dto.front_view**:
	Normalized front view direction of the camera.

	**dto.right_view**:
	Right direction vector, calculated as the cross product
		of the front view and a downward vector (0, -1, 0).

	**dto.up_view**:
	Up direction vector, calculated as the cross product of the
		right and front view vectors.

	**Get viewport point**:
	Calls get_viewport_point to get the coordinates of
		the point on the viewport corresponding to the pixel (row, col).

	**Transform viewport point**:
	Converts the viewport point to world coordinates
		by combining the right, up, and front view directions scaled by the
		respective components of the viewport point.

	**Calculate ray direction**:
	Computes the direction of the ray from the camera
		origin to the transformed viewport point, then normalizes it.

	**Return ray**:
	Constructs and returns a ray with the camera's origin as the
		starting point and the calculated direction.
*/

t_vector	get_viewport_point(t_camera *camera, int row, int col,
		mlx_image_t *image)
{
	return (create_vector(((row + 0.5f) / (float)image->width * camera->vp_width
				- camera->vp_width / 2.f), ((col + 0.5f) / (float)image->height
				* camera->vp_height - camera->vp_height / 2.f), 1.f, 0.f));
}

t_ray	create_ray(t_miniRT **miniRT, int row, int col)
{
	t_camera	*camera;
	t_dto		dto;

	camera = (*miniRT)->camera;
	dto.front_view = vector_normalisation(camera->norm_vector);
	dto.right_view = vector_normalisation((cross_product(dto.front_view,
					create_vector(0.0f, -1.0f, 0.0f, 0.0f))));
	dto.up_view = cross_product(dto.right_view, dto.front_view);
	dto.viewport_point = get_viewport_point(camera, row, col, (*miniRT)->image);
	dto.viewport_point = vector_addition(vector_addition(vector_multiplication(\
				dto.right_view, dto.viewport_point.x_axis),
				vector_multiplication(dto.up_view, dto.viewport_point.y_axis)),
			vector_multiplication(dto.front_view, dto.viewport_point.z_axis));
	dto.ray_point = vector_normalize((vector_subtraction(dto.viewport_point,
					camera->cord_vector)));
	return ((t_ray){c_v(camera->cord_vector),
		create_vector(dto.ray_point.x_axis, dto.ray_point.y_axis,
			dto.ray_point.z_axis, 0)});
}
