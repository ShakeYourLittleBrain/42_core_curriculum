/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_cyld_insect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 02:45:53 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/24 22:11:28 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

bool	solve_quadratic_siuuu(float *coefficients, float *t0, float *t1)
{
	float	discriminant;
	float	sqrt_disc;
	float	a;
	float	b;
	float	c;

	a = coefficients[0];
	b = coefficients[1];
	c = coefficients[2];
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	sqrt_disc = sqrtf(discriminant);
	*t0 = (-b - sqrt_disc) / (2 * a);
	*t1 = (-b + sqrt_disc) / (2 * a);
	return (true);
}

void	calculate_coefficients(t_ray *ray, t_cylinder *cy, float *coeffs)
{
	t_vector	delta_p;
	float		dp_axis;
	float		rd_axis;
	float		radius;

	radius = cy->diameter / 2;
	delta_p = vector_subtraction(ray->cord_vector, cy->cord_vector);
	dp_axis = dot_product(delta_p, cy->norm_vector);
	rd_axis = dot_product(ray->direction, cy->norm_vector);
	coeffs[0] = dot_product(ray->direction, ray->direction) - powf(rd_axis, 2);
	coeffs[1] = 2 * (dot_product(ray->direction, delta_p) - rd_axis * dp_axis);
	coeffs[2] = dot_product(delta_p, delta_p) - powf(dp_axis, 2) \
		- powf(radius, 2);
}

bool	calc_hit(t_ray *ray, t_cylinder *cy, float dist, float *t)
{
	t_vector	hit_point;
	float		dist_to_cap;

	hit_point = vector_addition(ray->cord_vector, \
		vector_multiplication(ray->direction, dist));
	dist_to_cap = dot_product(vector_subtraction(hit_point, cy->cord_vector), \
		cy->norm_vector);
	if (dist_to_cap >= 0 && dist_to_cap <= cy->height)
	{
		if (dist < *t)
			*t = dist;
		//printf("temp: %f\n", *t);
		return (true);
	}
	return (false);
}

bool	check_cy_body(t_ray *ray, t_cylinder *cy, float *coeffs, float *t)
{
	float	t0;
	float	t1;
	float	tmp;
	bool	hit0_valid;
	bool	hit1_valid;

	tmp = INFINITY;
	hit0_valid = false;
	hit1_valid = false;
	if (!solve_quadratic_siuuu(coeffs, &t0, &t1))
		return (false);
	//printf("t0: %f t1: %f\n", t0, t1);
	hit0_valid = calc_hit(ray, cy, t0, &tmp);
	hit1_valid = calc_hit(ray, cy, t1, &tmp);
	if (hit0_valid || hit1_valid)
	{
		*t = tmp;
		//printf("min_distance: %f\n", *t);
		return (true);
	}
	return (false);
}

t_node_object	*intersect_cylinder(t_ray *ray, t_node_object *cylnd,
		float *min_distance)
{
	float		coefficients[3];
	t_cylinder	tmp;
	t_plane		bottom;
	t_plane		top;


	tmp = *cylnd->cylinder;
	tmp.norm_vector = init(cylnd->cylinder->norm_vector);
	make_helper_plane(&tmp, &bottom, false);
	make_helper_plane(&tmp, &top, true);
	calculate_coefficients(ray, &tmp, coefficients);
	//printf("coefficients[0]: %f coefficients[1]: %f coefficients[2]: %f\n", coefficients[0], coefficients[1], coefficients[2]);
	if (check_cy_body(ray, &tmp, coefficients, min_distance) \
	|| intersect_disk(ray, &bottom, min_distance, \
	cylnd->cylinder->diameter / 2) \
	|| intersect_disk(ray, &top, min_distance, \
	cylnd->cylinder->diameter
			/ 2))
		return (cylnd);
	return (NULL);
}
