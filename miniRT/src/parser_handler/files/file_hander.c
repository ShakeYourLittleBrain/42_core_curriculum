/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_hander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:40:32 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/16 09:12:57 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	read_scene_file(char *filename, t_miniRT **miniRT)
{
	int		fd;
	char	*line;
	int		id;

	id = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_error_exit("Error\nFailed to open file\n", miniRT, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (parse_line(line, miniRT, &id) == 0)
			return (free(line), close(fd), 0);
		free(line);
	}
	if ((*miniRT)->camera_flag != 1)
		return (throw_error("Error\nCamera not defined\n", miniRT, 1), 0);
	else if ((*miniRT)->amb_light_flag != 1)
		return (throw_error("Error\nAmbient light not defined\n", miniRT, 1),
			0);
	else if ((*miniRT)->light_flag != 1)
		return (throw_error("Error\nLight not defined\n", miniRT, 1), 0);
	return (close(fd), 1);
}
