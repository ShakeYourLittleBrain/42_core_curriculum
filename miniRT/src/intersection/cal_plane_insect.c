/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_plane_insect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:45:24 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/23 04:41:13 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*
The `intersect_plane` function is part of a ray tracing algorithm that
	determines if a given ray intersects with a plane. If an intersection occurs,
	it calculates the distance from the ray's origin to the intersection point
	and updates the minimum distance. Here’s a detailed explanation of
	how the function works:

The `intersect_plane` function determines the intersection of a ray with a
 plane in the following steps:

1. **Calculate the Denominator**:
	The dot product of the plane's normal vector and the ray's direction vector.
		This determines if the ray is parallel to the plane.

2. **Check for Parallelism**:
	If the denominator is near zero,
		the ray is considered parallel to the plane,
		and there is no intersection.

3. **Calculate the Point-to-Origin Vector**:
	The vector from a known point on the plane to the ray's origin.

4. **Calculate the Intersection Distance**:
	Using the point-to-origin vector and the plane's normal vector, compute the
	distance to the intersection point.

5. **Check Intersection Distance**:
	Ensure the intersection point is in front of the ray's origin.

6. **Return the Plane Object**:
	If the intersection is valid, return (the plane object); otherwise,
		return `NULL`.

This function is crucial in ray tracing for determining if and where a ray
intersects with planes in the scene, which is necessary for rendering and
 shading calculations.
*/

t_node_object	*intersect_plane(t_ray *ray, t_node_object *plane,
		float *min_distance)
{
	float		denominator;
	t_vector	point_to_origin;

	denominator = dot_product(plane->plane->norm_vector, ray->direction);
	if (fabs(denominator) < NEAR_ZERO)
		return (NULL);
	point_to_origin = vector_subtraction(plane->plane->plane_vector,
			ray->cord_vector);
	*min_distance = dot_product(point_to_origin, plane->plane->norm_vector)
		/ denominator;
	if (*min_distance < 0)
		return (NULL);
	return (plane);
}

int	solve_quadratic_cyld(t_cylnd_dto *dto)
{
	float	discriminant;
	float	sqrt_discriminant;

	discriminant = powf((dto)->b, 2) - 4 * (dto)->a * (dto)->c;
	if (discriminant < 0)
		return (0);
	sqrt_discriminant = sqrtf(discriminant);
	(dto)->point_1 = (-(dto)->b - sqrt_discriminant) / (2 * (dto)->a);
	(dto)->point_2 = (-(dto)->b + sqrt_discriminant) / (2 * (dto)->a);
	return (1);
}

void	check_hit(t_ray *ray, t_cylnd_dto *dto)
{
	dto->hit_valid = hit_cyld_body(ray, dto) || intersect_disk_radius(ray, dto,
			1) || intersect_disk_radius(ray, dto, 0);
}
