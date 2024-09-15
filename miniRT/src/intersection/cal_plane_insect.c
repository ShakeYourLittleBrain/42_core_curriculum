/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_plane_insect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:45:24 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/17 22:50:29 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_node_object	*intersect_plane(t_ray *ray, t_node_object *plane,
		float *min_distance)
{
	float		denominator;
	t_vector	point_to_origin;

	denominator = dot_product(plane->plane->norm_vector, ray->direction);
	if (fabs(denominator) < PL_CNT)
		return (NULL);
	point_to_origin = vector_subtraction(plane->plane->plane_vector,
			ray->cord_vector);
	*min_distance = dot_product(point_to_origin, plane->plane->norm_vector)
		/ denominator;
	if (*min_distance < 0)
		return (NULL);
	return (plane);
}
