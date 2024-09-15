/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:47:46 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/16 23:25:05 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	set_color(t_color *color, char ***split_args_2)
{
	color->red = ft_atoi((*split_args_2)[0]);
	color->green = ft_atoi((*split_args_2)[1]);
	color->blue = ft_atoi((*split_args_2)[2]);
	if (color->red < 0 || color->red > 255 || color->blue < 0
		|| color->blue > 255 || color->green < 0 || color->green > 255)
	{
		throw_error("Error\nInvalid color\n", NULL, 1);
		return (0);
	}
	ft_free_2d((void **)*split_args_2);
	return (1);
}

void	set_cord_vector(t_vector *vector, char ***split_args_2)
{
	vector->x_axis = ft_atof((*split_args_2)[0]);
	vector->y_axis = ft_atof((*split_args_2)[1]);
	vector->z_axis = ft_atof((*split_args_2)[2]);
	vector->w_axis = 0.f;
	ft_free_2d((void **)*split_args_2);
}

void	check_and_normalize_vector(t_vector *vector)
{
	float	length;

	length = sqrt(pow(vector->x_axis, 2) + pow(vector->y_axis, 2)
			+ pow(vector->z_axis, 2));
	vector->x_axis /= length;
	vector->y_axis /= length;
	vector->z_axis /= length;
}

int	set_norm_vector(t_vector *vector, char ***split_args_2)
{
	(vector)->x_axis = ft_atof((*split_args_2)[0]);
	(vector)->y_axis = ft_atof((*split_args_2)[1]);
	(vector)->z_axis = ft_atof((*split_args_2)[2]);
	ft_free_2d((void **)*split_args_2);
	if ((vector)->x_axis < -1 || (vector)->x_axis > 1)
		return (1);
	if ((vector)->y_axis < -1 || (vector)->y_axis > 1)
		return (1);
	if ((vector)->z_axis < -1 || (vector)->z_axis > 1)
		return (1);
	check_and_normalize_vector(vector);
	return (0);
}

int	set_cylinder_dimen_hght_clr(t_node_object *n_obj, char **split_args)
{
	char	**split_args_2;

	(n_obj->cylinder)->diameter = ft_atof(split_args[3]);
	(n_obj->cylinder)->height = ft_atof(split_args[4]);
	if ((n_obj->cylinder)->diameter <= 0 || (n_obj->cylinder)->height <= 0)
		return (0);
	split_args_2 = ft_split(split_args[5], ',');
	if (ft_split_len(split_args_2) != 3)
		return (0);
	return (set_color(&(n_obj->cylinder)->color, &split_args_2));
}
