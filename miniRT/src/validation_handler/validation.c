/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:03:09 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/11 02:03:07 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	input_validation(int argc, char *argv[])
{
	if (argc != 2)
		return (throw_error("Error\nInvalid number of arguments\n", NULL, 1),
			exit(EXIT_FAILURE));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3))
		return (throw_error("Error\nInvalid file extension\n", NULL, 1),
			exit(EXIT_FAILURE));
}
