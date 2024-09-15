/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_objs_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:43:39 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/16 09:15:59 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	parse_cylinder(char *line, t_miniRT **miniRT, int *id)
{
	t_node_object	*n_obj;
	char			**split_args;
	char			**split_args_2;

	n_obj = create_node_object(CYLINDER, id);
	if (!n_obj)
		return (throw_error("Error\nMemory allocation failed\n", miniRT, 1), 0);
	split_args = ft_split(line, ' ');
	if (ft_split_len(split_args) != 6)
		return (throw_error("Error\nInvalid cylinder format\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid cylinder format\n", miniRT, 1), 0);
	set_cord_vector(&(n_obj->cylinder)->cord_vector, &split_args_2);
	split_args_2 = ft_split(split_args[2], ',');
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid cylinder format\n", miniRT, 1), 0);
	set_norm_vector(&(n_obj->cylinder)->norm_vector, &split_args_2);
	if (!set_cylinder_dimen_hght_clr(n_obj, split_args))
		return (throw_error("Error\nInvalid cylinder dimension\n", NULL, 1), 0);
	return (n_obj->type = CYLINDER, n_obj->next = (*miniRT)->objects_head,
		(*miniRT)->objects_head = n_obj, 1);
}

int	parse_plane(char *line, t_miniRT **miniRT, int *id)

{
	t_node_object	*n_obj;
	char			**split_args;
	char			**split_args_2;

	n_obj = create_node_object(PLANE, id);
	if (!n_obj)
		return (throw_error("Error\nMemory allocation failed\n", miniRT, 1), 0);
	split_args = ft_split(line, ' ');
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid plane format\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid plane format\n", miniRT, 1), 0);
	set_cord_vector(&(n_obj->plane)->plane_vector, &split_args_2);
	split_args_2 = ft_split(split_args[2], ',');
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid plane format\n", miniRT, 1), 0);
	set_norm_vector(&(n_obj->plane)->norm_vector, &split_args_2);
	split_args_2 = ft_split(split_args[3], ',');
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid plane format\n", miniRT, 1), 0);
	return (n_obj->type = PLANE, n_obj->next = (*miniRT)->objects_head,
		(*miniRT)->objects_head = n_obj, set_color(&(n_obj->plane)->color,
			&split_args_2));
}

int	parse_sphere(char *line, t_miniRT **miniRT, int *id)
{
	t_node_object	*n_obj;
	t_sphere		*sphere;
	char			**split_args;
	char			**split_args_2;

	n_obj = create_node_object(SPHERE, id);
	if (!n_obj)
		return (throw_error("Error\nMemory allocation failed\n", miniRT, 1), 0);
	sphere = n_obj->sphere;
	split_args = ft_split(line, ' ');
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid sphere format\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid sphere format\n", miniRT, 1), 0);
	set_cord_vector(&sphere->cord_vector, &split_args_2);
	sphere->diameter = ft_atof(split_args[2]);
	if (sphere->diameter <= 0)
		return (throw_error("Error\nInvalid sphere diameter\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[3], ',');
	if (ft_split_len(split_args_2) != 3)
		return (throw_error("Error\nInvalid sphere format\n", miniRT, 1), 0);
	return (n_obj->type = SPHERE, n_obj->next = (*miniRT)->objects_head,
		(*miniRT)->objects_head = n_obj, set_color(&sphere->color,
			&split_args_2));
}
