/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:03:51 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/24 22:35:55 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_node_object	*intersected_obj(t_ray *ray, t_node_object *object,
		float *min_distance)
{
	t_node_object	*intersected_object;

	intersected_object = NULL;
	if (object->type == SPHERE)
		intersected_object = intersect_sphere(ray, object, min_distance);
	else if (object->type == PLANE)
		intersected_object = intersect_plane(ray, object, min_distance);
	else if (object->type == CYLINDER)
		intersected_object = intersect_cylinder(ray, object, min_distance);
	return (intersected_object);
}

t_node_object	*get_intersected_object(t_ray *ray, t_miniRT **miniRT,
		float *distance)
{
	t_node_object	*objects;
	t_node_object	*intersected_object;
	t_node_object	*object_intersected;
	float			min_distance;

	objects = (*miniRT)->objects_head;
	intersected_object = NULL;
	object_intersected = NULL;
	while (objects)
	{
		if (DEBUG)
			printf("Object type: %d\n", objects->type);
		intersected_object = intersected_obj(ray, objects, &min_distance);
		if (intersected_object && min_distance < *distance)
		{
			*distance = min_distance;
			object_intersected = intersected_object;
		}
		if (DEBUG)
			printf("Distance: %f\n", *distance);
		objects = objects->next;
	}
	if (*distance != INFINITY)
		return (object_intersected);
	return (intersected_object);
}

unsigned int	trace_ray(t_ray *ray, t_miniRT **miniRT)
{
	t_node_object	*objects;
	unsigned int	colour;
	float			distance;

	distance = INFINITY;
	objects = get_intersected_object(ray, miniRT, &distance);
	if (objects)
		colour = pixel_colour(objects, ray, miniRT, distance);
	else
		colour = 0x000000;
	return (colour);
}

void	prep_row_pixel(t_miniRT **miniRT, int row, int col)
{
	t_ray			ray;
	unsigned int	color;

	if (DEBUG)
		printf("Row: %d, Col: %d\n", row, col);
	ray = create_ray(miniRT, row, col);
	if (DEBUG)
		print_ray(&ray);
	color = trace_ray(&ray, miniRT);
	if (DEBUG)
		printf("Color: %d\n", color);
	mlx_put_pixel((*miniRT)->image, row, col, color);
}

void	scene_processor_engine(t_miniRT **miniRT, int flag)
{
	int	i;
	int	j;
	int	total;
	int	progress;

	i = -1;
	total = (int)(*miniRT)->image->width * (int)(*miniRT)->image->height;
	progress = 0;
	while (++i < (int)(*miniRT)->image->width)
	{
		j = -1;
		while (++j < (int)(*miniRT)->image->height)
		{
			prep_row_pixel(miniRT, i, j);
			if (flag)
			{
				progress++;
				print_progress_bar(progress, total);
			}
		}
	}
	if (flag)
		printf("\n");
}
