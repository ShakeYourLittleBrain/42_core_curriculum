/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 05:28:54 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/21 21:16:44 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	parse_amb_light(char *line, t_miniRT **miniRT)
{
	t_amb_light	*amb_light;
	char		**split_args;
	char		**split_args_2;

	amb_light = (*miniRT)->amb_light;
	split_args = ft_split(line, ' ');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args);
	if ((*miniRT)->amb_light_flag == 1)
		return (throw_error("Error\nAmbient light already defined\n", NULL, 1),
			0);
	if (ft_split_len(split_args) != 3)
		return (throw_error("Error\nInvalid ambient light format\n", NULL, 1),
			0);
	amb_light->brightness = ft_atof(split_args[1]);
	if (amb_light->brightness < 0 || amb_light->brightness > 1)
		return (throw_error("Error\nInvalid ambient light brightness\n", NULL,
				1), 0);
	split_args_2 = ft_split(split_args[2], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid ambient light format\n", NULL, 1),
			0);
	return ((*miniRT)->amb_light_flag = 1, set_color(&amb_light->color,
			&split_args_2));
}

int	parse_camera(char *line, t_miniRT **miniRT)
{
	char	**split_args;
	char	**split_args_2;

	if ((*miniRT)->camera_flag == 1)
		return (throw_error("Error\nCamera already defined\n", NULL, 1), 0);
	split_args = ft_split(line, ' ');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args);
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid camera format\n", NULL, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid view point format\n", NULL, 1), 0);
	set_cord_vector(&(*miniRT)->camera->cord_vector, &split_args_2);
	split_args_2 = ft_split(split_args[2], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid norm vector format\n", NULL, 1), 0);
	if (set_norm_vector(&(*miniRT)->camera->norm_vector, &split_args_2))
		return (throw_error("Error\nInvalid norm vector values\n", NULL, 1), 0);
	(*miniRT)->camera->fov = ft_atof(split_args[3]);
	if ((*miniRT)->camera->fov < 0 || (*miniRT)->camera->fov > 180)
		return (throw_error("Error\nInvalid fov value\n", NULL, 1), 0);
	return ((*miniRT)->camera_flag = 1, 1);
}

int	parse_light(char *line, t_miniRT **miniRT)
{
	t_light	*light;
	char	**split_args;
	char	**split_args_2;

	light = (*miniRT)->light;
	split_args = ft_split(line, ' ');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args);
	if ((*miniRT)->light_flag == 1)
		return (throw_error("Error\nLight already defined\n", NULL, 1), 0);
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid light format\n", NULL, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid light format\n", NULL, 1), 0);
	set_cord_vector(&light->cord_vector, &split_args_2);
	light->brightness = ft_atof(split_args[2]);
	if (light->brightness < 0 || light->brightness > 1)
		return (throw_error("Error\nInvalid light brightness\n", NULL, 1), 0);
	split_args_2 = ft_split(split_args[3], ',');
	map_2d_ptr_to_1d_ptr(get_gc(), (void **)split_args_2);
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid light format\n", NULL, 1), 0);
	return ((*miniRT)->light_flag = 1, set_color(&light->color, &split_args_2));
}

int	parse_line(char *line, t_miniRT **miniRT, int *id)
{
	char	*temp;

	temp = ft_strtrim(line, " ");
	ft_gc_add(get_gc(), temp);
	if (temp[0] == 'A' && !ft_isalpha(temp[1]))
		return (parse_amb_light(line, miniRT));
	else if (temp[0] == 'C' && !ft_isalpha(temp[1]))
		return (parse_camera(line, miniRT));
	else if (temp[0] == 'L' && !ft_isalpha(temp[1]))
		return (parse_light(line, miniRT));
	else if (temp[0] == 's' && temp[1] == 'p')
		return (parse_sphere(line, miniRT, id));
	else if (temp[0] == 'p' && temp[1] == 'l')
		return (parse_plane(line, miniRT, id));
	else if (temp[0] == 'c' && temp[1] == 'y')
		return (parse_cylinder(line, miniRT, id));
	else if (line[0] == '\0' || line[0] == '#' || line[0] == '\n')
		return (1);
	else if (ft_isalpha(temp[0]) != 0)
		return (throw_error("Error\nInvalid line format\n", NULL, 1), 0);
	else
		return (throw_error("Error\nInvalid object\n", NULL, 1), 0);
}
