/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_components.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:34:07 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/16 23:27:38 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

float	vector_magnitude(t_vector a)
{
	float	result;

	result = sqrt(pow(a.x_axis, 2) + pow(a.y_axis, 2) + pow(a.z_axis, 2)
			+ pow(a.w_axis, 2));
	return (result);
}

t_vector	vector_normalisation(t_vector a)
{
	t_vector	result;
	float		magnitude;

	magnitude = vector_magnitude(a);
	result.x_axis = magnitude * a.x_axis;
	result.y_axis = magnitude * a.y_axis;
	result.z_axis = magnitude * a.z_axis;
	result.w_axis = magnitude * a.w_axis;
	return (result);
}

float	dot_product(t_vector a, t_vector b)
{
	float	result;

	result = a.x_axis * b.x_axis + a.y_axis * b.y_axis + a.z_axis * b.z_axis;
	return (result);
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	result;

	result.x_axis = a.y_axis * b.z_axis - a.z_axis * b.y_axis;
	result.y_axis = a.z_axis * b.x_axis - a.x_axis * b.z_axis;
	result.z_axis = a.x_axis * b.y_axis - a.y_axis * b.x_axis;
	result.w_axis = 0;
	return (result);
}
