/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:49:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/16 09:26:38 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_node_object	*create_node_object(t_type type, int *id)
{
	t_node_object	*n_obj;

	n_obj = ft_calloc(1, sizeof(t_node_object));
	n_obj->next = NULL;
	if (!n_obj)
		return (NULL);
	if (type == SPHERE)
	{
		n_obj->sphere = (t_sphere *)malloc(sizeof(t_sphere));
		if (!n_obj->sphere)
			return (NULL);
	}
	else if (type == PLANE)
	{
		n_obj->plane = (t_plane *)malloc(sizeof(t_plane));
		if (!n_obj->plane)
			return (NULL);
	}
	else if (type == CYLINDER)
	{
		n_obj->cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
		if (!n_obj->cylinder)
			return (NULL);
	}
	return (n_obj->id = *id,*id = *id + 1, n_obj);
}
