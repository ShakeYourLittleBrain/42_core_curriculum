/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 05:47:14 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/06 21:08:45 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../library/MLX_42/include/MLX42/MLX42.h"
# include "../library/libft/libft.h"
# include <limits.h>
# include <math.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1580
# define HEIGHT 1280
# define MAX_ITR 100

# define MAND "mandelbrot"
# define H_MIN_M -2.3
# define H_MAX_M 1.2
# define V_MIN_M -1.5
# define V_MAX_M 1.5

# define TRICON "tricon"
# define H_MIN_T -2.8
# define H_MAX_T 2.2
# define V_MIN_T -2.5
# define V_MAX_T 2.5

# define JULIA "julia"
# define H_MIN_J -1.5
# define H_MAX_J 1.5
# define V_MIN_J -1.5
# define V_MAX_J 1.5

# define ZERO 0
# define MOVE_RATIO 0.01
# define MAN_TRI_VAL_LIMIT 10

# define ERR_STR \
	"\n\033[53m\033[4mFormat should be like this\033[0m\n\n \
		|\033[1m\033[53m\033[4m<./<name_program>> <fractal's name>\033[0m|\n\n \
			Ex: ./fractol mandelbrot\n\n \
		|\033[1m\033[53m\033[4m<./<name_program>> <fractal's name> <x(real)> <y(imaginary)>i\033[0m|\n\n \
			Ex_1: ./fractol julia 0.45 -0.1428\n \
			Ex_2: ./fractol julia 0.285 0.013\n \
			Ex_3: ./fractol julia -0.835 -0.2321\n\n\
		|\033[1m\033[53m\033[4m<./<name_program>> <fractal's name>|\033[0m\n\n \
			Ex: ./fractol tricon\n"

typedef struct s_fractol
{
	mlx_t		*mlx_instance;
	mlx_image_t	*image;
	double		horizontal_min;
	double		horizontal_max;
	double		vertical_min;
	double		vertical_max;
	double		real_z;
	double		immg_z;
	double		real_c;
	double		immg_c;
	double		real;
	double		immg;
	int			iteration;
	int			clear;
	int32_t		x_pos;
	int32_t		y_pos;
	int			title;
}				t_fractol;

int				main(int argc, char *argv[]);
int				input_error_check(int argc, char *argv[]);
char			*ft_tolower_str(char *str);
void			init_julia_fractol_mlx_data(char *argv[],
					t_fractol *frtl_data_julia);
void			init_fractol_jul_fin(t_fractol *frtl_data_julia);
void			init_mand_fractol_mlx_data(t_fractol *frtl_data_mand);
void			init_fractol_mand_fin(t_fractol *frtl_data_mand);
void			mand_init(t_fractol *f_m, double horiz, double vert);
void			draw_mand(void *param);
void			mand_values(t_fractol *f_m);
int				psychedelic_color(int iteration);
void			my_scrollhook(double xdelta, double ydelta, void *param);
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			infinite_scroll(t_fractol *frtl, double zoom_factor,
					double x_pos, double y_pos);
void			key_press_up_down(mlx_key_data_t keydata, t_fractol *frtl);
void			key_press_left_right(mlx_key_data_t keydata, t_fractol *frtl);
void			draw_julia(void *param);
void			julia_values(t_fractol *frt_jul);
double			power_x(double val);
void			my_resizefunc(int32_t width, int32_t height, void *param);
void			init_fractol_tric_data(t_fractol *frtl_data_tric);
void			init_fractol_tric_fin(t_fractol *frtl_data_tric);
void			draw_tric(void *param);
void			tric_init(t_fractol *f_t, double horiz, double vert);
void			tric_values(t_fractol *f_t);

#endif

/*
void			print_fractol_man(const t_fractol *man);
*/
