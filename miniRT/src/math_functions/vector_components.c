/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_components.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:34:07 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/24 04:36:11 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

float	vector_magnitude(t_vector a)
{
	float	result;

	result = sqrt(pow(a.x_axis, 2) + pow(a.y_axis, 2) + pow(a.z_axis, 2));
	return (result);
}

t_vector	vector_normalisation(t_vector a)
{
	t_vector	result;
	float		magnitude;

	magnitude = sqrt(dot_product(a, a));
	result.x_axis = a.x_axis / magnitude;
	result.y_axis = a.y_axis / magnitude;
	result.z_axis = a.z_axis / magnitude;
	result.w_axis = a.w_axis / magnitude;
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
