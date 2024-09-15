/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:03:51 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/24 22:23:06 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector		cylinder_normal_1(t_vector center, t_vector axis,
					t_vector hit_point);
void			fetch_properties_1(t_node_object *object, t_vector hit_point,
					t_color *color, t_vector *normal);
t_color			calculate_lighting_1(t_miniRT *mini_rt, t_vector hit_point,
					t_vector normal, t_vector view_dir);
float			calculate_discriminant_1(t_ray *ray, t_sphere *sphere, float *b,
					float *c);
bool			solve_quadratic_1(float b, float discriminant, float *t0,
					float *t1);
bool			find_closest_hit_1(float t0, float t1, float *t);
bool			intersect_sphere_1(t_ray *ray, t_sphere *sphere, float *t);
bool			intersect_object_1(t_ray *ray, t_node_object *object, float *t);
float			cast_object_hard_shadows_1(t_miniRT *mini_rt,
					t_node_object *hit_object, t_vector hit_point,
					t_vector light_dir);
t_color			scale_color_1(t_color color, float factor);
t_color			gamma_correction_1(t_color color, float gamma);
t_color			combine_lighting_1(t_miniRT *mini_rt, t_color hit_color,
					t_color direct_light);
t_color			clamp_color_1(t_color color);
t_color			cast_light_1(t_miniRT *mini_rt, t_node_object *object,
					t_vector hit);
unsigned int	vec_to_color_1(t_color color);
t_node_object	*intersected_obj(t_ray *ray, t_node_object *object,
					float *min_distance);
t_node_object	*get_intersected_object(t_ray *ray, t_miniRT **miniRT,
					float *distance);
unsigned int	trace_ray(t_ray *ray, t_miniRT **miniRT);
void			prep_row_pixel(t_miniRT **miniRT, int row, int col);
bool			intersect_plane_1(t_ray *ray, t_plane *plane, float *t);
bool			intersect_cylinder_1(t_ray *ray, t_cylinder *cylinder,
					float *t);

t_vector	cylinder_normal_1(t_vector center, t_vector axis,
		t_vector hit_point)
{
	t_vector	closest_to_axis;
	t_vector	to_hit;
	t_vector	normal;
	t_vector	norm_axis;

	norm_axis = init(axis);
	to_hit = vector_subtraction(hit_point, center);
	closest_to_axis = vector_addition(center, vector_multiplication(norm_axis,
				dot_product(to_hit, norm_axis)));
	normal = vector_subtraction(hit_point, closest_to_axis);
	return (normal);
}

static t_vector	calc_normal_1(t_node_object *object, t_vector hit_point)
{
	t_vector	normal;

	normal = (t_vector){0, 0, 0, 0};
	if (object && object->type == SPHERE)
		normal = vector_subtraction(hit_point, object->sphere->cord_vector);
	else if (object && object->type == PLANE)
		normal = object->plane->norm_vector;
	else if (object && object->type == CYLINDER)
		normal = cylinder_normal_1(object->cylinder->cord_vector,
				object->cylinder->norm_vector, hit_point);
	return (init(normal));
}

void	fetch_properties_1(t_node_object *object, t_vector hit_point,
		t_color *color, t_vector *normal)
{
	*normal = calc_normal_1(object, hit_point);
	if (object && object->type == SPHERE)
		*color = object->sphere->color;
	else if (object && object->type == PLANE)
		*color = object->plane->color;
	else if (object && object->type == CYLINDER)
		*color = object->cylinder->color;
	else
		*color = (t_color){0, 0, 0};
}
// fetch properties-----------------------------------------------------------------------------------------

// calculate_lighting-----------------------------------------------------------------------------------------

t_color	apply_ambilight_1(t_amb_light *ambilight, t_color color)
{
	return ((t_color){.red = fmin(color.red * (0.1f + (ambilight->color.red
					* ambilight->brightness / 255.0f)), 255.0f),
		.green = fmin(color.green * (0.1f + (ambilight->color.green
					* ambilight->brightness / 255.0f)), 255.0f),
		.blue = fmin(color.blue * (0.1f + (ambilight->color.blue
					* ambilight->brightness / 255.0f)), 255.0f)});
}

static t_color	calc_specular_light_1(t_light *light, t_vector hit_point,
		t_vector normal, t_vector view_dir)
{
	t_vector	light_dir;
	t_vector	reflect_dir;
	float		spec;

	light_dir = init(vector_subtraction(light->cord_vector, hit_point));
	reflect_dir = vector_subtraction(vector_multiplication(normal, 2
				* dot_product(normal, light_dir)), light_dir);
	spec = pow(fmax(dot_product(view_dir, reflect_dir), 0.0), 32);
	return ((t_color){.red = light->color.red * spec * light->brightness,
		.green = light->color.green * spec * light->brightness,
		.blue = light->color.blue * spec * light->brightness});
}

static t_color	calc_diffuse_light_1(t_light *light, t_vector hit_point,
		t_vector normal)
{
	t_vector	light_dir;
	float		vect_dot_product;

	light_dir = init(vector_subtraction(light->cord_vector, hit_point));
	vect_dot_product = fmax(dot_product(normal, light_dir), 0.f);
	return ((t_color){.red = (light->color.red * vect_dot_product
			* light->brightness), .green = (light->color.green
			* vect_dot_product * light->brightness), .blue = (light->color.blue
			* vect_dot_product * light->brightness)});
}

t_color	calculate_lighting_1(t_miniRT *mini_rt, t_vector hit_point,
		t_vector normal, t_vector view_dir)
{
	t_color	diffuse_light;
	t_color	specular_light;
	t_color	total_direct_light;

	diffuse_light = calc_diffuse_light_1(mini_rt->light, hit_point, normal);
	specular_light = calc_specular_light_1(mini_rt->light, hit_point, normal,
			view_dir);
	total_direct_light = (t_color){.red = diffuse_light.red
		+ specular_light.red, .green = diffuse_light.green
		+ specular_light.green, .blue = diffuse_light.blue
		+ specular_light.blue};
	return (total_direct_light);
}

// calculate_lighting-----------------------------------------------------------------------------------------

// apply_hard_shadows-----------------------------------------------------------------------------------------

float	calculate_discriminant_1(t_ray *ray, t_sphere *sphere, float *b,
		float *c)
{
	t_vector	sphere_offset;
	float		radius;
	float		a;

	sphere_offset = vector_subtraction(ray->cord_vector, sphere->cord_vector);
	radius = sphere->diameter / 2;
	a = 1.f;
	*b = 2.f * dot_product(sphere_offset, ray->direction);
	*c = dot_product(sphere_offset, sphere_offset) - radius * radius;
	return (*b * *b - 4 * a * *c);
}

bool	solve_quadratic_1(float b, float discriminant, float *t0, float *t1)
{
	float	a;
	float	sqrt_disc;

	a = 1.f;
	if (discriminant < 0)
		return (false);
	sqrt_disc = sqrtf(discriminant);
	*t0 = (-b - sqrt_disc) / (2 * a);
	*t1 = *t0;
	if (discriminant > 0)
		*t1 = (-b + sqrt_disc) / (2 * a);
	return (true);
}

bool	find_closest_hit_1(float t0, float t1, float *t)
{
	if (t0 > 0 && t1 > 0)
	{
		if (t0 < t1)
			*t = t0;
		else
			*t = t1;
		return (true);
	}
	else if (t0 > 0)
		return (*t = t0, true);
	else if (t1 > 0)
		return (*t = t1, true);
	return (false);
}

bool	intersect_sphere_1(t_ray *ray, t_sphere *sphere, float *t)
{
	float	discriminant;
	float	b;
	float	c;
	float	t0;
	float	t1;

	discriminant = calculate_discriminant_1(ray, sphere, &b, &c);
	if (!solve_quadratic_1(b, discriminant, &t0, &t1))
		return (false);
	if (find_closest_hit_1(t0, t1, t))
		return (true);
	return (false);
}

static bool	shadow_intersect_1(t_ray *ray, t_miniRT *mini_rt, float light_dist)
{
	float			t;
	int				i;
	bool			hit;
	t_node_object	*temp;

	i = -1;
	temp = mini_rt->objects_head;
	while (temp)
	{
		t = INFINITY;
		hit = false;
		if (temp->type == SPHERE)
			hit = intersect_sphere_1(ray, temp->sphere, &t);
		else if (temp->type == CYLINDER)
			hit = intersect_cylinder_1(ray, temp->cylinder, &t);
		if (hit && t > 0.0001f && t < light_dist)
			return (true);
		temp = temp->next;
	}
	return (false);
}

static float	rand_float_1(void)
{
	return (((float)rand() / RAND_MAX) * 2.0f - 1.0f);
}

static t_ray	calc_shadow_ray_1(t_vector hit_point, t_vector normal,
		t_vector light_dir, float filter_radius)
{
	t_ray		shadow_ray;
	t_vector	offset_dir;

	offset_dir.x_axis = rand_float_1() * filter_radius;
	offset_dir.y_axis = rand_float_1() * filter_radius;
	offset_dir.z_axis = rand_float_1() * filter_radius;
	shadow_ray.cord_vector = vector_addition(hit_point,
			vector_multiplication(normal, 0.001f));
	shadow_ray.direction = init(vector_addition(light_dir, offset_dir));
	return (shadow_ray);
}

float	cast_shadow_1(t_miniRT *mini_rt, t_vector hit_point, t_light *light,
		t_vector normal)
{
	t_ray	shadow_ray;
	float	light_dist;
	float	shadow_intensity;
	float	filter_radius;

	light_dist = vector_magnitude(vector_subtraction(light->cord_vector,
				hit_point));
	shadow_intensity = 0.f;
	if (light_dist < 0.001f)
		light_dist = 0.001f;
	filter_radius = fmin(1.f / light_dist, 1.f);
	shadow_ray = calc_shadow_ray_1(hit_point, normal,
			vector_subtraction(light->cord_vector, hit_point), filter_radius);
	if (shadow_intersect_1(&shadow_ray, mini_rt, light_dist)) // doing
		shadow_intensity += 1.0f;
	return (shadow_intensity);
}

void	make_helper_plane_1(t_cylinder *cylinder, t_plane *to_init, bool is_top)
{
	t_vector	center;
	t_vector	normal;

	normal = cylinder->norm_vector;
	center = cylinder->cord_vector;
	if (is_top == true)
		center = vector_addition(cylinder->cord_vector,
				vector_multiplication(normal, cylinder->height));
	*to_init = (t_plane){
		.plane_vector = center,
		.norm_vector = normal,
		.color = cylinder->color,
	};
}

bool	intersect_plane_1(t_ray *ray, t_plane *plane, float *t)
{
	float		denominator;
	t_vector	point_to_cord_vector;

	denominator = dot_product(plane->norm_vector, ray->direction);
	if (fabs(denominator) < 1e-16)
		return (false);
	point_to_cord_vector = vector_subtraction(plane->plane_vector,
			ray->cord_vector);
	*t = dot_product(point_to_cord_vector, plane->norm_vector) / denominator;
	if (*t < 0)
		return (false);
	return (true);
}

static bool	solve_quadratic_siuuu_1(float *coefficients, float *t0, float *t1)
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

static void	calculate_coefficients_1(t_ray *ray, t_cylinder *cy, float *coeffs)
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
	coeffs[2] = dot_product(delta_p, delta_p) - powf(dp_axis, 2) - powf(radius,
			2);
}

static bool	calc_hit_1(t_ray *ray, t_cylinder *cy, float dist, float *t)
{
	t_vector	hit_point;
	float		dist_to_cap;

	hit_point = vector_addition(ray->cord_vector,
			vector_multiplication(ray->direction, dist));
	dist_to_cap = dot_product(vector_subtraction(hit_point, cy->cord_vector),
			cy->norm_vector);
	if (dist_to_cap >= 0 && dist_to_cap <= cy->height)
	{
		if (dist < *t)
			*t = dist;
		return (true);
	}
	return (false);
}

static bool	check_cy_body_1(t_ray *ray, t_cylinder *cy, float *coeffs, float *t)
{
	float	t0;
	float	t1;
	float	tmp;
	bool	hit0_valid;
	bool	hit1_valid;

	tmp = INFINITY;
	hit0_valid = false;
	hit1_valid = false;
	if (!solve_quadratic_siuuu_1(coeffs, &t0, &t1))
		return (false);
	hit0_valid = calc_hit_1(ray, cy, t0, &tmp);
	hit1_valid = calc_hit_1(ray, cy, t1, &tmp);
	if (hit0_valid || hit1_valid)
	{
		*t = tmp;
		return (true);
	}
	return (false);
}

bool	check_radius_1(float *t, t_ray *ray, t_plane *disk, float radius)
{
	t_vector	pos;
	float		len;

	pos = vector_addition(ray->cord_vector,
			vector_multiplication(ray->direction, *t));
	len = sqrt(dot_product(vector_subtraction(disk->plane_vector, pos),
				vector_subtraction(disk->plane_vector, pos)));
	if (len >= radius)
		return (false);
	return (true);
}

bool	intersect_disk_1(t_ray *ray, t_plane *disk, float *t, float radius)
{
	float		denominator;
	t_vector	point_to_cord_vector;
	float		tmp;

	denominator = dot_product(disk->norm_vector, ray->direction);
	if (fabs(denominator) < 1e-16)
		return (false);
	point_to_cord_vector = vector_subtraction(disk->plane_vector,
			ray->cord_vector);
	tmp = dot_product(point_to_cord_vector, disk->norm_vector) / denominator;
	if (tmp >= 0 && check_radius_1(&tmp, ray, disk, radius))
	{
		if (tmp < *t)
			*t = tmp;
		return (true);
	}
	return (false);
}

bool	intersect_cylinder_1(t_ray *ray, t_cylinder *cylinder, float *t)
{
	float		coefficients[3];
	t_cylinder	*temp;
	t_plane		bottom;
	t_plane		top;
	bool		hits[3];

	temp = cylinder;
	temp->norm_vector = init(cylinder->norm_vector);
	make_helper_plane_1(temp, &bottom, false);
	make_helper_plane_1(temp, &top, true);
	calculate_coefficients_1(ray, temp, coefficients);
	hits[0] = check_cy_body_1(ray, temp, coefficients, t);
	hits[1] = intersect_disk_1(ray, &bottom, t, cylinder->diameter / 2);
	hits[2] = intersect_disk_1(ray, &top, t, cylinder->diameter / 2);
	return (hits[0] || hits[1] || hits[2]);
}

bool	intersect_object_1(t_ray *ray, t_node_object *object, float *t)
{
	if (object && object->type == SPHERE)
		return (intersect_sphere_1(ray, object->sphere, t)); // done
	else if (object && object->type == PLANE)
		return (intersect_plane_1(ray, object->plane, t)); // done
	else if (object && object->type == CYLINDER)
		return (intersect_cylinder_1(ray, object->cylinder, t));
	return (false);
}

float	cast_object_hard_shadows_1(t_miniRT *mini_rt, t_node_object *hit_object,
		t_vector hit_point, t_vector light_dir)
{
	t_ray			shadow_ray;
	t_node_object	*temp;
	bool			hit;
	float			t;

	shadow_ray.cord_vector = vector_addition(hit_point,
			vector_multiplication(light_dir, 0.001f));
	shadow_ray.direction = light_dir;
	hit = false;
	temp = mini_rt->objects_head;
	while (temp)
	{
		if (temp->id == hit_object->id)
			temp = temp->next;
		t = INFINITY;
		hit = intersect_object_1(&shadow_ray, temp, &t);
		if (hit_object->type == PLANE)
			hit = false;
		if (hit && t > 0.001f)
			return (1.f);
		if (temp)
			temp = temp->next;
	}
	return (0.f);
}

t_color	scale_color_1(t_color color, float factor)
{
	t_color	result;

	result.red = (unsigned char)fmin(255, color.red * factor);
	result.green = (unsigned char)fmin(255, color.green * factor);
	result.blue = (unsigned char)fmin(255, color.blue * factor);
	return (result);
}

static t_color	apply_hard_shadows_1(t_miniRT *mini_rt,
		t_node_object *hit_object, t_vector hit_point, t_vector normal)
{
	t_vector	light_dir;
	float		shadow_factor;
	t_color		direct_light;

	light_dir = init(vector_subtraction(mini_rt->light->cord_vector,
				hit_point));
	shadow_factor = 1.0f - cast_shadow_1(mini_rt, hit_point, mini_rt->light,
											normal); // done
	shadow_factor *= (1.0f - cast_object_hard_shadows_1(mini_rt, hit_object,
				hit_point, light_dir));
	// doing
	direct_light = calculate_lighting_1(mini_rt, hit_point, normal,
			init(vector_subtraction(mini_rt->camera->cord_vector, hit_point)));
	// calculate_lighting done
	return (scale_color_1(direct_light, shadow_factor));
}

// apply_hard_shadows-----------------------------------------------------------------------------------------

// clamp_color(combine_lighting-----------------------------------------------------------------------------------------
t_color	gamma_correction_1(t_color color, float gamma)
{
	t_color	corrected;

	corrected.red = pow(color.red / 255.0, gamma) * 255;
	corrected.green = pow(color.green / 255.0, gamma) * 255;
	corrected.blue = pow(color.blue / 255.0, gamma) * 255;
	return (corrected);
}

t_color	combine_lighting_1(t_miniRT *mini_rt, t_color hit_color,
		t_color direct_light)
{
	t_color	ambilight;
	t_color	total_color;

	ambilight = apply_ambilight_1(mini_rt->amb_light, hit_color);
	total_color = (t_color){.red = fmin(255, ambilight.red + direct_light.red),
		.green = fmin(255, ambilight.green + direct_light.green),
		.blue = fmin(255, ambilight.blue + direct_light.blue)};
	return (gamma_correction_1(total_color, 1.2));
}

t_color	clamp_color_1(t_color color)
{
	color.red = fmin(fmax(color.red, 0), 255);
	color.green = fmin(fmax(color.green, 0), 255);
	color.blue = fmin(fmax(color.blue, 0), 255);
	return (color);
}
// clamp_color(combine_lighting-----------------------------------------------------------------------------------------

t_color	cast_light_1(t_miniRT *mini_rt, t_node_object *object, t_vector hit)
{
	t_color		hit_color;
	t_vector	normal;
	t_vector	view_dir;
	t_color		direct_light;

	fetch_properties_1(object, hit, &hit_color, &normal);
	// fech properties done
	view_dir = init(vector_subtraction(mini_rt->camera->cord_vector, hit));
	// direct_light = calculate_lighting_1(mini_rt, hit, normal, view_dir);
	// calculate_lighting done
	direct_light = apply_hard_shadows_1(mini_rt, object, hit,
										normal); // done
	return (clamp_color_1(combine_lighting_1(mini_rt, hit_color,
												direct_light))); // doing
}

unsigned int	vec_to_color_1(t_color color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;

	r = (unsigned int)color.red;
	g = (unsigned int)color.green;
	b = (unsigned int)color.blue;
	a = 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

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
	*distance = INFINITY;
	intersected_object = NULL;
	object_intersected = NULL;
	while (objects)
	{
		intersected_object = intersected_obj(ray, objects, &min_distance);
		if (intersected_object && min_distance < *distance)
		{
			*distance = min_distance;
			object_intersected = intersected_object;
		}
		objects = objects->next;
	}
	if (*distance != INFINITY)
		return (object_intersected);
	return (intersected_object);
}

unsigned int	trace_ray(t_ray *ray, t_miniRT **miniRT)
{
	t_node_object	*objects;
	float			distance;
	t_vector		hit_point;
	t_color			color;

	objects = get_intersected_object(ray, miniRT, &distance);
	if (objects)
	{
		hit_point = vector_addition(ray->cord_vector,
				vector_multiplication(ray->direction, distance));
		color = cast_light_1(*miniRT, objects, hit_point);
	}
	else
		color = (t_color){0, 0, 0};
	return (vec_to_color_1(color));
}

void	prep_row_pixel(t_miniRT **miniRT, int row, int col)
{
	t_ray			ray;
	unsigned int	color;

	ray = create_ray(miniRT, row, col);
	//printf("ray: %f %f %f\n", ray.direction.x_axis, ray.direction.y_axis, ray.direction.z_axis);
	color = trace_ray(&ray, miniRT);
	mlx_put_pixel((*miniRT)->image, row, col, color);
}


void	print_progress_bar(int progress, int total)
{
	int		barwidth;
	float	percentage;
	int		pos;

	barwidth = 50;
	percentage = (float)progress / total;
	printf("[");
	pos = 0;
	while (pos < barwidth)
	{
		if (pos < (int)(barwidth * percentage))
			printf("=");
		else if (pos == (int)(barwidth * percentage))
			printf(">");
		else
			printf(" ");
		pos++;
	}
	printf("] %d%% \033[1G", (int)(percentage * 100));
}

void	scene_processor_engine(t_miniRT **miniRT, int flag)
{
	int	i;
	int	j;
	int	total;
	int	progress;

	i = 0;
	j = 0;
	total = (int)(*miniRT)->image->width * (int)(*miniRT)->image->height;
	progress = 0;
	while (i < (int)(*miniRT)->image->width)
	{
		j = 0;
		while (j < (int)(*miniRT)->image->height)
		{
			prep_row_pixel(miniRT, i, j);
			j++;
				if (flag)
			{
				progress++;
				print_progress_bar(progress, total);
			}
		}
		i++;
	}
	printf("\n");
}

// void	scene_processor_engine(t_miniRT **miniRT)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < (int)(*miniRT)->image->width)
// 	{
// 		j = -1;
// 		while (++j < (int)(*miniRT)->image->height)
// 			prep_row_pixel(miniRT, i, j);
// 	}
// }
