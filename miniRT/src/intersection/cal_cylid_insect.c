/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_cylid_insect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:39:03 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/23 04:41:23 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*
	Will start by calculating the intersection of a ray with a cylinder.
*/
int	valid_hit(t_ray *ray, t_cylnd_dto *dto, int flag)
{
	t_vector	hit_point;
	float		hit_point_distance;
	float		temp;

	if (flag)
		temp = dto->point_1;
	else
		temp = dto->point_2;
	hit_point = vector_addition(ray->cord_vector,
			vector_multiplication(ray->direction, temp));
	hit_point_distance = dot_product(vector_subtraction(hit_point,
				dto->cyld.cord_vector), (dto->cyld.norm_vector));
	if (hit_point_distance >= 0 && hit_point_distance <= dto->cyld.height)
	{
		if (temp < (dto)->temp)
			(dto)->temp = temp;
		return (1);
	}
	return (0);
}

int	hit_cyld_body(t_ray *ray, t_cylnd_dto *dto)
{
	int	hit_valid;

	dto->temp = INFINITY;
	if (!solve_quadratic_cyld(dto))
		return (0);
	hit_valid = valid_hit(ray, dto, 1) || valid_hit(ray, dto, 0);
	if (hit_valid)
	{
		*dto->min_distance = dto->temp;
		return (1);
	}
	return (0);
}

int	intersect_disk_radius(t_ray *ray, t_cylnd_dto *dto, int flag)
{
	t_plane		*disk;
	t_vector	point_to_origin;
	t_vector	pos;
	float		len;
	float		denominator;

	if (flag)
		disk = &dto->plane_bottom;
	else
		disk = &dto->plane_top;
	denominator = dot_product(disk->norm_vector, ray->direction);
	if (fabs(denominator) < NEAR_ZERO)
		return (0);
	point_to_origin = vector_subtraction(disk->plane_vector, ray->cord_vector);
	dto->temp = dot_product(point_to_origin, disk->norm_vector) / denominator;
	pos = vector_addition(ray->cord_vector,
			vector_multiplication(ray->direction, dto->temp));
	len = sqrt(dot_product(vector_subtraction(disk->plane_vector, pos),
				vector_subtraction(disk->plane_vector, pos)));
	if (dto->temp < 0 || len >= dto->cyld.diameter / 2)
		return (0);
	if (dto->temp < *dto->min_distance)
		*dto->min_distance = dto->temp;
	return (1);
}

void	main_cal_hit_check(t_ray *ray, t_cylnd_dto *dto)
{
	t_vector	clyld_cntr_to_ray;
	float		prjtn_cctr_axis;
	float		prjtn_rd_axis;

	clyld_cntr_to_ray = vector_subtraction(ray->cord_vector,
			dto->cyld.cord_vector);
	prjtn_cctr_axis = dot_product(clyld_cntr_to_ray, dto->cyld.norm_vector);
	prjtn_rd_axis = dot_product(ray->direction, dto->cyld.norm_vector);
	dto->a = dot_product(ray->direction, ray->direction) - powf(prjtn_rd_axis,
			2);
	dto->b = 2 * (dot_product(ray->direction, clyld_cntr_to_ray)
			- (prjtn_rd_axis * prjtn_cctr_axis));
	dto->c = dot_product(clyld_cntr_to_ray, clyld_cntr_to_ray)
		- powf(prjtn_cctr_axis, 2) - powf(dto->cyld.diameter / 2, 2);
	check_hit(ray, dto);
}

t_node_object	*intersect_cylinder(t_ray *ray, t_node_object *cylnd,
		float *min_distance)
{
	t_cylnd_dto	dto;

	dto.cyld = *cylnd->cylinder;
	dto.min_distance = min_distance;
	dto.cyld.norm_vector = vector_normalize(dto.cyld.norm_vector);
	dto.plane_bottom = (t_plane){
		.plane_vector = dto.cyld.cord_vector,
		.norm_vector = dto.cyld.norm_vector,
		.color = dto.cyld.color,
	};
	dto.plane_top = (t_plane){
		.plane_vector = vector_addition(dto.cyld.cord_vector, \
				vector_multiplication(dto.cyld.norm_vector, dto.cyld.height)),
		.norm_vector = dto.cyld.norm_vector,
		.color = dto.cyld.color,
	};
	main_cal_hit_check(ray, &dto);
	if (dto.hit_valid)
		return (cylnd);
	return (NULL);
}
