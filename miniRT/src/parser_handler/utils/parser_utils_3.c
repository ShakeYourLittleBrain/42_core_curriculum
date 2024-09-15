/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:49:59 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/21 21:07:28 by skhastag         ###   ########.fr       */
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
		n_obj->sphere = (t_sphere *)ft_gc_malloc_check_and_add(get_gc(),
				sizeof(t_sphere));
		n_obj->type = SPHERE;
	}
	else if (type == PLANE)
	{
		n_obj->plane = (t_plane *)ft_gc_malloc_check_and_add(get_gc(),
				sizeof(t_plane));
		n_obj->type = PLANE;
	}
	else if (type == CYLINDER)
	{
		n_obj->cylinder = (t_cylinder *)ft_gc_malloc_check_and_add(get_gc(),
				sizeof(t_cylinder));
		n_obj->type = CYLINDER;
	}
	return (n_obj->id = *id, *id = *id + 1, ft_gc_add(get_gc(), n_obj), n_obj);
}
