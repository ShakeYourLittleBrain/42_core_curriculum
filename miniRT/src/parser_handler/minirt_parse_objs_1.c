/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_objs_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:43:39 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/21 21:10:06 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	parse_cylinder(char *line, t_miniRT **miniRT, int *id)
{
	t_node_object	*n_obj;
	char			**split_args;
	char			**split_args_2;

	n_obj = create_node_object(CYLINDER, id);
	split_args = ft_split(line, ' ');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args);
	if (ft_split_len(split_args) != 6)
		return (throw_error("Error\nInvalid cylinder format\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid cylinder format\n", miniRT, 1), 0);
	set_cord_vector(&(n_obj->cylinder)->cord_vector, &split_args_2);
	split_args_2 = ft_split(split_args[2], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid cylinder format\n", miniRT, 1), 0);
	set_norm_vector(&(n_obj->cylinder)->norm_vector, &split_args_2);
	if (!set_cylinder_dimen_hght_clr(n_obj, split_args))
		return (throw_error("Error\nInvalid cylinder dimension\n", NULL, 1), 0);
	return (n_obj->next = (*miniRT)->objects_head,
		(*miniRT)->objects_head = n_obj, 1);
}

int	parse_plane(char *line, t_miniRT **mt, int *id)
{
	t_node_object	*n_obj;
	char			**split_args;
	char			**s_a2;

	n_obj = create_node_object(PLANE, id);
	split_args = ft_split(line, ' ');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args);
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid plane format\n", NULL, 1), 0);
	s_a2 = ft_split(split_args[1], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)s_a2);
	if (ft_split_len(s_a2) != 3)
		return (throw_error("Error\nInvalid plane format\n", NULL, 1), 0);
	set_cord_vector(&(n_obj->plane)->plane_vector, &s_a2);
	s_a2 = ft_split(split_args[2], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)s_a2);
	if (ft_split_len(s_a2) != 3)
		return (throw_error("Error\nInvalid plane format\n", NULL, 1), 0);
	set_norm_vector(&(n_obj->plane)->norm_vector, &s_a2);
	s_a2 = ft_split(split_args[3], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)s_a2);
	if (ft_split_len(s_a2) != 3)
		return (throw_error("Error\nInvalid plane format\n", NULL, 1), 0);
	return (n_obj->next = (*mt)->objects_head, (*mt)->objects_head = n_obj,
		set_color(&(n_obj->plane)->color, &s_a2));
}

int	parse_sphere(char *line, t_miniRT **miniRT, int *id)
{
	t_node_object	*n_obj;
	char			**split_args;
	char			**split_args_2;

	n_obj = create_node_object(SPHERE, id);
	split_args = ft_split(line, ' ');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args);
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid sphere format\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid sphere format\n", miniRT, 1), 0);
	set_cord_vector(&n_obj->sphere->cord_vector, &split_args_2);
	n_obj->sphere->diameter = ft_atof(split_args[2]);
	if (n_obj->sphere->diameter <= 0)
		return (throw_error("Error\nInvalid sphere diameter\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[3], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid sphere format\n", miniRT, 1), 0);
	return (n_obj->next = (*miniRT)->objects_head,
		(*miniRT)->objects_head = n_obj, set_color(&n_obj->sphere->color,
			&split_args_2));
}
