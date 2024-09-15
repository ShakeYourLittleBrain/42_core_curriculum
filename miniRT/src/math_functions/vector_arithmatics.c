/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmatics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:32:41 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/22 22:07:06 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	vector_addition(t_vector a, t_vector b)
{
	t_vector	result;

	result.x_axis = a.x_axis + b.x_axis;
	result.y_axis = a.y_axis + b.y_axis;
	result.z_axis = a.z_axis + b.z_axis;
	result.w_axis = a.w_axis + b.w_axis;
	return (result);
}

t_vector	vector_subtraction(t_vector a, t_vector b)
{
	t_vector	result;

	result.x_axis = a.x_axis - b.x_axis;
	result.y_axis = a.y_axis - b.y_axis;
	result.z_axis = a.z_axis - b.z_axis;
	result.w_axis = a.w_axis - b.w_axis;
	return (result);
}

t_vector	negating_vector(t_vector a)
{
	t_vector	result;

	result.x_axis = 0 - a.x_axis;
	result.y_axis = 0 - a.y_axis;
	result.z_axis = 0 - a.z_axis;
	result.w_axis = 0 - a.w_axis;
	return (result);
}

t_vector	vector_multiplication(t_vector a, float multiple)
{
	t_vector	result;

	result.x_axis = multiple * a.x_axis;
	result.y_axis = multiple * a.y_axis;
	result.z_axis = multiple * a.z_axis;
	result.w_axis = multiple * a.w_axis;
	return (result);
}

t_vector	vector_division(t_vector a, float divisor)
{
	t_vector	result;

	if (divisor == 0.0)
		return ((t_vector){0.0, 0.0, 0.0, 0.0});
	else if (divisor == 1.0)
		divisor = 0.999994;
	result.x_axis = a.x_axis / divisor;
	result.y_axis = a.y_axis / divisor;
	result.z_axis = a.z_axis / divisor;
	result.w_axis = a.w_axis / divisor;
	return (result);
}
