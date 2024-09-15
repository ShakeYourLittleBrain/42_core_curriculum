/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sphere_insect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:17:42 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/23 01:12:07 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*
The calculation of ( b ) as twice the dot product of the ray's direction and
the vector from the sphere's center to the ray's origin (( oc )) stems from
the quadratic equation derived from the intersection of a ray with a sphere.

### Ray-Sphere Intersection

1. **Sphere Equation**:
	A sphere centered at point ( C ) with radius ( r ) can be described by
	the equation:
	| P - C |^2 = r^2
	where ( P ) is any point on the sphere's surface.

2. **Ray Equation**:
	A ray originating from point ( O ) with direction ( D ) can be described
	by the equation:
	P(t) = O + tD
	where ( t ) is a scalar parameter.

3. **Substitute Ray into Sphere Equation**:
	To find the intersection points,
		we substitute the ray equation into the sphere equation:
	| (O + tD) - C |^2 = r^2
	Let ( oc = O - C ),
		the vector from the sphere's center to the ray's origin.
		The equation becomes:
	| oc + tD |^2 = r^2

4. **Expand and Simplify**:
	Expanding the left-hand side and using the dot product, we get:
	(oc + tD) * (oc + tD) = r^2
	| oc |^2 + 2t (oc * D) + t^2 | D |^2 = r^2
	Since ( D ) is a direction vector, ( | D |^2 = 1 ). Therefore,
		the equation simplifies to:
	| oc |^2 + 2t (oc * D) + t^2 = r^2

5. **Form Quadratic Equation**:
	Rearranging terms to form a standard quadratic equation in ( t ):
	t^2 + 2(oc * D)t + | oc |^2 - r^2 = 0
	This is a quadratic equation of the form:
	at^2 + bt + c = 0
	where:
	a = 1 (since | D |^2 = 1) and for this i skipped the a term
	b = 2(oc * D)
	c = | oc |^2 - r^2
*/

int	hit_distance(float point_1, float point_2, float *min_distance)
{
	if (point_1 > NEAR_ZERO && point_2 > NEAR_ZERO)
	{
		if (point_1 < point_2)
			*min_distance = point_1;
		else
			*min_distance = point_2;
		return (1);
	}
	return (0);
}

float	discriminant(t_ray *ray, t_sphere *sphere, float *b, float *c)
{
	t_vector	oc;
	float		discrim;

	oc = vector_subtraction(ray->cord_vector, sphere->cord_vector);
	*b = 2.f * dot_product(ray->direction, oc);
	*c = dot_product(oc, oc) - (sphere->diameter / 2) * (sphere->diameter / 2);
	discrim = *b * *b - 4 * *c;
	return (discrim);
}

int	eq_quadratic(float b, float *point_1, float *point_2, float discrim)
{
	if (discrim < 0)
		return (0);
	*point_1 = (-b - sqrt(discrim)) / 2;
	*point_2 = (-b + sqrt(discrim)) / 2;
	return (1);
}

t_node_object	*intersect_sphere(t_ray *ray, t_node_object *sphere,
		float *min_distance)
{
	float	b;
	float	c;
	float	point_1;
	float	point_2;
	float	value_b;

	value_b = discriminant(ray, sphere->sphere, &b, &c);
	if (DEBUG)
		printf("Value b: %f\n", value_b);
	if (!eq_quadratic(b, &point_1, &point_2, value_b))
		return (NULL);
	if (DEBUG)
	{
		printf("Point 1: %f\n", point_1);
		printf("Point 2: %f\n", point_2);
	}
	if (hit_distance(point_1, point_2, min_distance))
		return (sphere);
	return (NULL);
}
