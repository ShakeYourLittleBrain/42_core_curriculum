/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:31:20 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/11 01:57:01 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	throw_error(char *error_message, t_miniRT **miniRT, int flag)
{
	(void)miniRT;
	if (flag)
		printf("%s", error_message);
}

void	throw_error_exit(char *error_message, t_miniRT **miniRT, int flag)
{
	destroy_and_free_minirt(miniRT);
	if (flag)
		printf("%s", error_message);
	exit(EXIT_FAILURE);
}
