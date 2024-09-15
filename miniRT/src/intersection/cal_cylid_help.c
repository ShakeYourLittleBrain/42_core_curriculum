/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_cylid_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:56:50 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/18 00:13:18 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	make_helper_plane(t_cylinder *cylinder, t_plane *to_init, bool is_top)
{
	t_vector	center;
	t_vector	normal;

	normal = cylinder->norm_vector;
	center = cylinder->cord_vector;
	if (is_top == true)
		center = vector_addition(cylinder->cord_vector, \
			vector_multiplication(normal, cylinder->height));
	*to_init = (t_plane){
		.plane_vector = center,
		.norm_vector = normal,
		.color = cylinder->color,
	};
}

bool	check_radius(float *t, t_ray *ray, t_plane *disk, float radius)
{
	t_vector	pos;
	float		len;

	pos = vector_addition(ray->cord_vector, \
		vector_multiplication(ray->direction, *t));
	len = sqrt(dot_product(vector_subtraction(disk->plane_vector, pos), \
		vector_subtraction(disk->plane_vector, pos)));
	if (len >= radius)
		return (false);
	return (true);
}

bool	intersect_disk(t_ray *ray, t_plane *disk, float *t, float radius)
{
	float		denominator;
	t_vector	point_to_origin;
	float		tmp;

	denominator = dot_product(disk->norm_vector, ray->direction);
	if (fabs(denominator) < 1e-16)
		return (false);
	point_to_origin = vector_subtraction(disk->plane_vector, ray->cord_vector);
	tmp = dot_product(point_to_origin, disk->norm_vector) / denominator;
	if (tmp >= 0 && check_radius(&tmp, ray, disk, radius))
	{
		if (tmp < *t)
			*t = tmp;
		return (true);
	}
	return (false);
}
