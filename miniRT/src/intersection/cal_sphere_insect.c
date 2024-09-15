/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sphere_insect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:17:42 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/18 23:59:12 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static int	closest_hit(float point_1, float point_2, float *min_distance)
{
	if (point_1 > PL_CNT && point_2 > PL_CNT)
	{
		if (point_1 < point_2)
			*min_distance = point_1;
		else
			*min_distance = point_2;
		return (1);
	}
	return (0);
}

static float	discriminant(t_ray *ray, t_sphere *sphere, float *b, float *c)
{
	t_vector	oc;
	float		discrim;

	oc = vector_subtraction(ray->cord_vector, sphere->cord_vector);
	*b = 2.f * dot_product(ray->direction, oc);
	*c = dot_product(oc, oc) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discrim = *b * *b - 4 * *c;
	return (discrim);
}

static int	eq_quadratic(float b, float *point_1, float *point_2, float discrim)
{
	if (discrim < 0)
		return (0);
	*point_1 = (-b - sqrtf(discrim)) / 2;
	*point_2 = (-b + sqrtf(discrim)) / 2;
	return (1);
}

t_node_object	*intersect_sphere(t_ray *ray, t_node_object *sphere,
		float *min_distance)
{
	float	b;
	float	c;
	float	point_1;
	float	point_2;
	float	discrim;

	discrim = discriminant(ray, sphere->sphere, &b, &c);
	if (!eq_quadratic(b, &point_1, &point_2, discrim))
		return (NULL);
	if (closest_hit(point_1, point_2, min_distance))
		return (sphere);
	return (NULL);
}
