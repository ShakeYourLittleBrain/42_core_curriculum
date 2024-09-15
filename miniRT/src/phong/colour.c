/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 00:42:47 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/25 01:06:05 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_color	create_color(float r, float g, float b)
{
	t_color	color;

	color.red = r;
	color.green = g;
	color.blue = b;
	return (color);
}

unsigned int	render_colour(t_miniRT **miniRT, t_color object_colour,
		t_color object_shadow)
{
	int	red;
	int	green;
	int	blue;

	red = fmin(object_colour.red * (0.1f + ((*miniRT)->amb_light->color.red \
	* (*miniRT)->amb_light->brightness / 255.0f)), 255.0f);
	green = fmin(object_colour.green * (0.1f + (\
	(*miniRT)->amb_light->color.green \
	* (*miniRT)->amb_light->brightness / 255.0f)), 255.0f);
	blue = fmin(object_colour.blue * (0.1f + (\
	(*miniRT)->amb_light->color.blue \
	* (*miniRT)->amb_light->brightness / 255.0f)), 255.0f);
	red = fmin(255, red + object_shadow.red);
	green = fmin(255, green + object_shadow.green);
	blue = fmin(255, blue + object_shadow.blue);
	red = pow(red / 255.0, 2.2) * 255;
	green = pow(green / 255.0, 2.2) * 255;
	blue = pow(blue / 255.0, 2.2) * 255;
	return (red << 24 | green << 16 | blue << 8 | 0xFF);
}

unsigned int	pixel_colour(t_node_object *objects, t_ray *ray,
		t_miniRT **miniRT, float distance)
{
	t_color		object_lighting;
	t_color		object_shadow;
	t_color		object_colour;
	t_vector	intersection_point;
	t_vector	intersection_normal;

	intersection_point = vector_addition(ray->cord_vector,
			vector_multiplication(ray->direction, distance));
	intersection_normal = ft_intersection_normal(objects, intersection_point);
	object_colour = ft_object_colour(objects);
	object_lighting = ft_light(miniRT, intersection_point, intersection_normal,
			object_colour);
	object_shadow = ft_shadow(miniRT, intersection_point, intersection_normal,
			object_lighting);
	return (render_colour(miniRT, object_colour, object_shadow));
}
