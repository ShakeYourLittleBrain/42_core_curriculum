/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 03:57:52 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/06 22:54:34 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

char	*ft_tolower_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) = *(str + i) + 32;
		i++;
	}
	return (str);
}

double	power_x(double val)
{
	return (val * val);
}

int	input_error_check(int argc, char *argv[])
{
	if (argv[1] && ft_strncmp(JULIA, ft_tolower_str(argv[1]), 5) == 0
		&& argc == 4)
		return (1);
	else if (argv[1] && ft_strncmp(MAND, ft_tolower_str(argv[1]), 10) == 0
		&& argc == 2)
		return (2);
	else if (argv[1] && ft_strncmp(TRICON, ft_tolower_str(argv[1]), 6) == 0
		&& argc == 2)
		return (3);
	ft_putendl_fd(ERR_STR, 2);
	exit(EXIT_FAILURE);
}
/*
void	print_fractol_man(const t_fractol *man)
{
	printf("t_fractol_man:\n");
	printf("mlx_instance: %p\n", (void *)man->mlx_instance);
	printf("image: %p\n", (void *)man->image);
	printf("horizontal_min: %lf\n", man->horizontal_min);
	printf("horizontal_max: %lf\n", man->horizontal_max);
	printf("vertical_min: %lf\n", man->vertical_min);
	printf("vertical_max: %lf\n", man->vertical_max);
	printf("real_z: %lf\n", man->real_z);
	printf("immg_z: %lf\n", man->immg_z);
	printf("real_c: %lf\n", man->real_c);
	printf("immg_c: %lf\n", man->immg_c);
	printf("real: %lf\n", man->real);
	printf("immg: %lf\n", man->immg);
	printf("iteration: %d\n", man->iteration);
	printf("clear: %d\n", man->clear);
	printf("x_pos: %d\n", man->x_pos);
	printf("y_pos: %d\n", man->y_pos);
}
*/
