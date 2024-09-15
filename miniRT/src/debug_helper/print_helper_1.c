/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:06:03 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/19 00:06:59 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	print_sphere(t_sphere *sphere)
{
	printf("Sphere:\n");
	printf("Cord: %f %f %f\n", sphere->cord_vector.x_axis,
		sphere->cord_vector.y_axis, sphere->cord_vector.z_axis);
	printf("Diameter: %f\n", sphere->diameter);
	printf("Color: %d %d %d\n", sphere->color.red, sphere->color.green,
		sphere->color.blue);
}

void	print_plane(t_plane *plane)
{
	printf("Plane:\n");
	printf("Cord: %f %f %f\n", plane->plane_vector.x_axis,
		plane->plane_vector.y_axis, plane->plane_vector.z_axis);
	printf("Norm: %f %f %f\n", plane->norm_vector.x_axis,
		plane->norm_vector.y_axis, plane->norm_vector.z_axis);
	printf("Color: %d %d %d\n", plane->color.red, plane->color.green,
		plane->color.blue);
}

void	print_cylinder(t_cylinder *cylinder)
{
	printf("Cylinder:\n");
	printf("Cord: %f %f %f\n", cylinder->cord_vector.x_axis,
		cylinder->cord_vector.y_axis, cylinder->cord_vector.z_axis);
	printf("Norm: %f %f %f\n", cylinder->norm_vector.x_axis,
		cylinder->norm_vector.y_axis, cylinder->norm_vector.z_axis);
	printf("Diameter: %f\n", cylinder->diameter);
	printf("Height: %f\n", cylinder->height);
	printf("Color: %d %d %d\n", cylinder->color.red, cylinder->color.green,
		cylinder->color.blue);
}

void	print_objects(t_node_object *objects_head)
{
	t_node_object	*current;

	current = objects_head;
	while (current)
	{
		if (current->type == SPHERE)
			print_sphere(current->sphere);
		else if (current->type == PLANE)
			print_plane(current->plane);
		else if (current->type == CYLINDER)
			print_cylinder(current->cylinder);
		current = current->next;
	}
}
