/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 05:28:54 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/16 09:15:57 by skhastag         ###   ########.fr       */
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
	if ((*miniRT)->amb_light_flag == 1)
		return (throw_error("Error\nAmbient light already defined\n", miniRT,
				1), 0);
	if (ft_split_len(split_args) != 3)
		return (throw_error("Error\nInvalid ambient light format\n", miniRT, 1),
			0);
	amb_light->brightness = ft_atof(split_args[1]);
	if (amb_light->brightness < 0 || amb_light->brightness > 1)
		return (throw_error("Error\nInvalid ambient light brightness\n", miniRT,
				1), 0);
	split_args_2 = ft_split(split_args[2], ',');
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid ambient light format\n", miniRT, 1),
			0);
	return (ft_free_2d((void **)split_args), (*miniRT)->amb_light_flag = 1,
		set_color(&amb_light->color, &split_args_2));
}

int	parse_camera(char *line, t_miniRT **miniRT)
{
	t_camera	*camera;
	char		**split_args;
	char		**split_args_2;

	camera = (*miniRT)->camera;
	if ((*miniRT)->camera_flag == 1)
		return (throw_error("Error\nCamera already defined\n", NULL, 1), 0);
	split_args = ft_split(line, ' ');
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid camera format\n", NULL, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid view point format\n", NULL, 1), 0);
	set_cord_vector(&camera->cord_vector, &split_args_2);
	split_args_2 = ft_split(split_args[2], ',');
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid norm vector format\n", NULL, 1), 0);
	if (set_norm_vector(&camera->norm_vector, &split_args_2))
		return (throw_error("Error\nInvalid norm vector values\n", NULL, 1), 0);
	camera->fov = ft_atof(split_args[3]);
	if (camera->fov < 0 || camera->fov > 180)
		return (throw_error("Error\nInvalid fov value\n", NULL, 1), 0);
	return (ft_free_2d((void **)split_args), (*miniRT)->camera_flag = 1, 1);
}

int	parse_light(char *line, t_miniRT **miniRT)
{
	t_light	*light;
	char	**split_args;
	char	**split_args_2;

	light = (*miniRT)->light;
	split_args = ft_split(line, ' ');
	if ((*miniRT)->light_flag == 1)
		return (throw_error("Error\nLight already defined\n", miniRT, 1), 0);
	if (ft_split_len(split_args) != 4)
		return (throw_error("Error\nInvalid light format\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[1], ',');
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid light format\n", miniRT, 1), 0);
	set_cord_vector(&light->cord_vector, &split_args_2);
	light->brightness = ft_atof(split_args[2]);
	if (light->brightness < 0 || light->brightness > 1)
		return (throw_error("Error\nInvalid light brightness\n", miniRT, 1), 0);
	split_args_2 = ft_split(split_args[3], ',');
	if (ft_split_len(split_args_2) != 3 || check_is_numeric(split_args_2) == 0)
		return (throw_error("Error\nInvalid light format\n", miniRT, 1), 0);
	return ((*miniRT)->light_flag = 1, set_color(&light->color, &split_args_2));
}

int	parse_line(char *line, t_miniRT **miniRT, int *id)
{
	if (ft_strtrim(line, " ")[0] == 'A' && !ft_isalpha(ft_strtrim(line,
				" ")[1]))
		return (parse_amb_light(line, miniRT));
	else if (ft_strtrim(line, " ")[0] == 'C' && !ft_isalpha(ft_strtrim(line,
				" ")[1]))
		return (parse_camera(line, miniRT));
	else if (ft_strtrim(line, " ")[0] == 'L' && !ft_isalpha(ft_strtrim(line,
				" ")[1]))
		return (parse_light(line, miniRT));
	else if (ft_strtrim(line, " ")[0] == 's' && ft_strtrim(line, " ")[1] == 'p')
		return (parse_sphere(line, miniRT, id));
	else if (ft_strtrim(line, " ")[0] == 'p' && ft_strtrim(line, " ")[1] == 'l')
		return (parse_plane(line, miniRT, id));
	else if (ft_strtrim(line, " ")[0] == 'c' && ft_strtrim(line, " ")[1] == 'y')
		return (parse_cylinder(line, miniRT, id));
	else if (line[0] == '\0' || line[0] == '#' || line[0] == '\n')
		return (1);
	else if (ft_isalpha(ft_strtrim(line, " ")[0]) != 0)
		return (throw_error("Error\nInvalid line format\n", miniRT, 1), 0);
	else
		return (throw_error("Error\nInvalid object\n", miniRT, 1), 0);
}
