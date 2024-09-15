/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:26:57 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/11 01:54:47 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	type_handler(t_miniRT *mini_rt)
{
	t_miniRT	*temp;

	temp = mini_rt;
	while (temp->objects_head != NULL)
	{
		if (temp->objects_head->type == SPHERE)
			set_sphere(temp);
		else if (temp->objects_head->type == PLANE)
		{
			set_plane(temp);
			return ;
		}
		else if (temp->objects_head->type == CYLINDER)
			set_cylinder(temp);
		temp->objects_head = temp->objects_head->next;
	}
}

		// else if (temp->objects_head->type == SQUARE)
		// 	set_square(temp->objects_head);
		// else if (temp->objects_head->type == TRIANGLE)
		// 	set_triangle(temp->objects_head);