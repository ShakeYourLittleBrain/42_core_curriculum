/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:14:17 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/20 21:27:00 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

t_vector	c_v(t_vector vector)
{
	return (create_vector(vector.x_axis, vector.y_axis, vector.z_axis,
			vector.w_axis));
}

t_vector	create_vector(float x, float y, float z, float w)
{
	t_vector	vector;

	vector.x_axis = x;
	vector.y_axis = y;
	vector.z_axis = z;
	vector.w_axis = w;
	return (vector);
}

t_vector	vector_normalize(t_vector a)
{
	return (vector_division(a, sqrt(dot_product(a, a))));
}
