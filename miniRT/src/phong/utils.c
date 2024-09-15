/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:59:02 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/24 06:51:23 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*---------------------------------------------------------------------------*/
//                                  Sphere
/*---------------------------------------------------------------------------*/
// For a sphere, the normal vector at the point of intersection can be
// calculated using the center of the sphere and the intersection point.
//
//                                  Formula:
//                          N = (P - C) / ||P - C||
//
//  - N = is the normal vector at the intersection point.
//  - P = is the intersection point.
//  - C = is the center of the sphere.
//  - ||P - C|| = is the magnitude (length) of the vector from the center to
//                the intersection point, which normalizes the vector.
/*---------------------------------------------------------------------------*/
//                                  Cylinder
/*---------------------------------------------------------------------------*/
// For a cylinder aligned along the y-axis, the normal vector at the
// intersection point can be calculated using the base center of the cylinder
// and the intersection point. If the cylinder is aligned along a different
// axis, the calculations need to be adjusted accordingly.
//
//                                  Formula:
//          N = (P - C) - ((P - C) · A) A / ||(P - C) - ((P - C) · A) A||
//
//  - N = is the normal vector at the intersection point.
//  - P = is the intersection point.
//  - C = is a point on the central axis of the cylinder, often the center
//        of the base.
//  - A = is the normalized axis vector of the cylinder.
//  - (P - C) · A = is the projection of the vector from the cylinder's base
//                  center to the intersection point onto the cylinder's axis.
/*---------------------------------------------------------------------------*/
static t_vector	object_normal(t_node_object *object,
		t_vector intersection_point, int type)
{
	t_vector	cord_vector;
	t_vector	norm_vector;
	t_vector	normal;

	normal = create_vector(0, 0, 0, 0);
	if (type == SPHERE)
		normal = vector_subtraction(intersection_point,
				object->sphere->cord_vector);
	else if (type == CYLINDER)
	{
		cord_vector = object->cylinder->cord_vector;
		norm_vector = object->cylinder->norm_vector;
		normal = vector_subtraction(intersection_point,
				vector_addition(cord_vector,
					vector_multiplication(vector_normalisation(norm_vector),
						dot_product(vector_subtraction(intersection_point,
								cord_vector),
							vector_normalisation(norm_vector)))));
	}
	else if (object && object->type == PLANE)
		normal = object->plane->norm_vector;
	normal = vector_normalisation(normal);
	return (normal);
}

/*---------------------------------------------------------------------------*/
//                                  Plane
/*---------------------------------------------------------------------------*/
// For a plane, the normal vector is constant and does not change regardless
// of the intersection point.
//
//                                Formula:
//                                 N = n
//
//  - N = is the normal vector at the intersection point.
//  - n = is the normal vector of the plane, which is typically given
//        as part of the plane's equation.
/*---------------------------------------------------------------------------*/
t_vector	ft_intersection_normal(t_node_object *objects,
		t_vector intersection_point)
{
	t_vector	normal;

	normal = create_vector(0, 0, 0, 0);
	if (objects->type == SPHERE)
		normal = object_normal(objects, intersection_point, SPHERE);
	else if (objects->type == CYLINDER)
		normal = object_normal(objects, intersection_point, CYLINDER);
	else if (objects->type == PLANE)
		normal = objects->plane->norm_vector;
	return (normal);
}

t_color	ft_object_colour(t_node_object *objects)
{
	t_color	color;

	color = create_color(0, 0, 0);
	if (objects->type == SPHERE)
		color = objects->sphere->color;
	else if (objects->type == CYLINDER)
		color = objects->cylinder->color;
	else if (objects->type == PLANE)
		color = objects->plane->color;
	return (color);
}
