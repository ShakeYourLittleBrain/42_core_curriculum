/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 08:23:52 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/06 21:08:36 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	psychedelic_color(int iteration)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(sin(0.1 * iteration) * 127 + 128);
	green = (int)(sin(0.2 * iteration + M_PI / 2) * 127 + 128);
	blue = (int)(cos(0.3 * iteration + M_PI) * 127 + 128);
	red += (int)(sin(0.15 * iteration) * 64);
	green += (int)(cos(0.25 * iteration) * 64);
	blue += (int)(sin(0.35 * iteration) * 64);
	if (red < 0)
		red = 0;
	else if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	else if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	else if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}
