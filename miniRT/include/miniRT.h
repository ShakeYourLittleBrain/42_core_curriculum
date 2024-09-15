/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohrahma <mohrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 03:54:04 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/10 03:56:42 by mohrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../library/MLX_42/include/MLX42/MLX42.h"
# include "../library/libft/libft.h"
# include <math.h>
# include <stdio.h>

# define DEBUG 0
# define WIDTH 800
# define HEIGHT 600
# define MATRIX_SIZE 4
# define NAME "miniRT"
# define NEAR_ZERO 1e-16
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define BBLACK "\033[1;30m"
# define BRED "\033[1;31m"
# define BGREEN "\033[1;32m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BMAGENTA "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"
# define RESET "\033[0m"
# define INSTRUCTIONS "\033[1;31m\t\t  __  __   _          _   ___   _____ \n \
\t\t |  \\/  | (_)  _ _   (_) | _ \\ |_   _| \n\
\t\t | |\\/| | | | | ' \\  | | |   /   | |  \n\
\t\t |_|  |_| |_| |_||_| |_| |_|_\\   |_|  \n\033[0m \
\n\
\033[1;33mC͟A͟M͟E͟R͟A͟ ͟C͟O͟N͟T͟R͟O͟L͟S͟:\n\033[0m\
Move Camera: Press C and use the arrow keys to move the camera position. \n\
                            \033[1;37m( C + ↑ ↓ → ← )\n\033[0m\
Move Camera Normal: Press C and use the ‘W’ ‘A’ ’S’ ‘D’ keys to move the camera position. \n\
                            \033[1;37m( C + W A S D )\n\033[0m\
\n\
\033[1;34mL͟I͟G͟H͟T͟ ͟C͟O͟N͟T͟R͟O͟L͟S͟:\n\033[0m\
Press L and use the arrow keys move the light source's position in the x and y axis. \n\
To move the light source's position in the z axis use the ‘A’ and ’S’ keys.\n\
                            \033[1;37m( L + ↑ ↓ → ← A S )\n\033[0m\
\n\
\033[1;32mO͟B͟J͟E͟C͟T͟ ͟C͟O͟N͟T͟R͟O͟L͟S͟:\n\033[0m\
Select Object: Press the number key (0-9) to select one of the first 10 objects in the scene. \n\
\n\
Rotate Object: Press R and use the arrow keys to rotate the selected object in the x and y direction.\n\
               To move the selected object in the z direction use the page up and page down keys. \n\
			\033[1;37m( Object Index + R + ↑ ↓ → ← PgUp PgDn )\n\033[0m\
\n\
Translate Object: Press T and use the arrow keys to move the selected object in the x and y direction. \n\
                  To move the selected object in the z direction use the page up and page down keys. \n\
			\033[1;37m( Object Index + T + ↑ ↓ → ← PgUp PgDn )\n\033[0m\
\n\n\
 "

typedef enum s_type
{
	SPHERE,
	PLANE,
	SQUARE,
	TRIANGLE,
	CYLINDER,
	LIGHT,
	CAMERA
}					t_type;

typedef struct s_vector
{
	float			x_axis;
	float			y_axis;
	float			z_axis;
	float			w_axis;
}					t_vector;

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct s_camera
{
	t_vector		cord_vector;
	t_vector		norm_vector;
	float			fov;
	float			ap_ratio;
	float			vp_height;
	float			vp_width;
}					t_camera;

typedef struct s_amb_light
{
	float			brightness;
	t_color			color;
}					t_amb_light;

typedef struct s_light
{
	t_vector		cord_vector;
	float			brightness;
	t_color			color;
}					t_light;

typedef struct s_sphere
{
	float			diameter;
	t_vector		cord_vector;
	t_color			color;
}					t_sphere;

typedef struct s_cylinder
{
	float			diameter;
	float			height;
	t_vector		cord_vector;
	t_vector		norm_vector;
	t_color			color;
}					t_cylinder;

typedef struct s_plane
{
	float			d;
	t_vector		norm_vector;
	t_vector		plane_vector;
	t_color			color;
}					t_plane;

typedef struct s_object
{
	int				id;
	t_type			type;
	t_sphere		*sphere;
	t_cylinder		*cylinder;
	t_plane			*plane;
	struct s_object	*next;
}					t_node_object;

typedef struct s_mat_4
{
	float			mat[4][4];
}					t_mat_4;

typedef struct s_miniRT
{
	mlx_t			*mlx_instance;
	mlx_image_t		*image;
	t_camera		*camera;
	t_amb_light		*amb_light;
	t_plane			*plane;
	t_light			*light;
	t_node_object	*objects_head;
	t_mat_4			*m_cofactor;
	t_mat_4			*m_indentifier;
	int				camera_flag;
	int				amb_light_flag;
	int				plane_flag;
	int				light_flag;
}					t_miniRT;

typedef struct s_ray
{
	t_vector		cord_vector;
	t_vector		direction;
}					t_ray;

typedef struct s_dto
{
	t_vector		front_view;
	t_vector		right_view;
	t_vector		up_view;
	t_vector		ray_point;
	t_vector		viewport_point;
}					t_dto;

typedef struct s_cylnd_dto
{
	float			a;
	float			b;
	float			c;
	t_plane			plane_top;
	t_plane			plane_bottom;
	float			*min_distance;
	t_cylinder		cyld;
	float			temp;
	float			point_1;
	float			point_2;
	int				hit_valid;
}					t_cylnd_dto;

// validation_handler
void				input_validation(int argc, char *argv[]);

// init_prep_scene
void				init_minirt(t_miniRT **miniRT);
int					init_minirt_mlx(t_miniRT **miniRT);
void				prep_scene(t_miniRT **miniRT, char *filename);
void				init_minirt_matrix_id(t_mat_4 **m_indentifier);
void				init_minirt_matrix_co(t_mat_4 **m_cofactor);

// parser_handler
int					parse_line(char *line, t_miniRT **miniRT, int *id);
int					read_scene_file(char *filename, t_miniRT **miniRT);
int					parse_amb_light(char *line, t_miniRT **miniRT);
int					parse_camera(char *line, t_miniRT **miniRT);
void				set_cord_vector(t_vector *vector, char ***split_args_2);
int					set_norm_vector(t_vector *vector, char ***split_args_2);
int					set_color(t_color *color, char ***split_args_2);
int					parse_sphere(char *line, t_miniRT **miniRT, int *id);
void				check_and_normalize_vector(t_vector *vector);
t_node_object		*create_node_object(t_type type, int *id);
int					set_cylinder_dimen_hght_clr(t_node_object *n_obj,
						char **split_args);
int					parse_cylinder(char *line, t_miniRT **miniRT, int *id);
int					parse_plane(char *line, t_miniRT **miniRT, int *id);
int					parse_light(char *line, t_miniRT **miniRT);
int					check_is_numeric(char **split_args_2);

// parser_utils
int					ft_split_len(char **split_args);
void				ft_free_2d(void **array);
void				ft_print_2d(void **array);

// error_handler + leaks_handler
void				destroy_and_free_minirt(t_miniRT **miniRT);
void				throw_error(char *error_message, t_miniRT **miniRT,
						int flag);
void				throw_error_exit(char *error_message, t_miniRT **miniRT,
						int flag);

/*---VectorArithmatics---*/
t_vector			vector_addition(t_vector a, t_vector b);
t_vector			vector_subtraction(t_vector a, t_vector b);
t_vector			negating_vector(t_vector a);
t_vector			vector_multiplication(t_vector a, float multiple);
t_vector			vector_division(t_vector a, float divisor);
float				vector_magnitude(t_vector a);
t_vector			vector_normalisation(t_vector a);
float				dot_product(t_vector a, t_vector b);
t_vector			cross_product(t_vector a, t_vector b);

/*---MatrixArithmatics---*/
void				print_matrix(float **matrix, int row, int column);
void				free_matrix(float **matrix, int size);
float				**create_matrix(int row, int column);
float				**invert_matrix(float **a);
float				**matrix_cofactor(float **a, int i, int j);
float				**matrix_devision_1m(float **a, float devisor);
float				**transpose_matrix(float **a);
float				**matrix_multiplication_1m(float **a, float multiple);
float				**matrix_multiplication(float **a, float **b);
float				determinant_3(float **a);
float				**submatrix(float **a, int *point, int size, int l);
float				determinant_4(float **a);

/*---SettingObjects---*/
void				type_handler(t_miniRT *mini_rt);
void				set_sphere(t_miniRT *mini_rt);
void				set_plane(t_miniRT *mini_rt);
void				set_cylinder(t_miniRT *mini_rt);

/*---RayTracing---*/
void				prep_window(t_miniRT **miniRT);
void				key_hook(mlx_key_data_t keydata, void *param);
void				scene_processor_engine(t_miniRT **miniRT, int flag);
void				init_cam_settings(t_miniRT **miniRT);
void				prep_row_pixel(t_miniRT **miniRT, int row, int col);
t_ray				create_ray(t_miniRT **miniRT, int row, int col);
t_vector			get_viewport_point(t_camera *camera, int row, int col,
						mlx_image_t *image);
t_vector			create_vector(float x, float y, float z, float w);
t_node_object		*intersect_plane(t_ray *ray, t_node_object *plane,
						float *min_distance);
t_node_object		*intersect_sphere(t_ray *ray, t_node_object *sphere,
						float *min_distance);
t_node_object		*get_intersected_object(t_ray *ray, t_miniRT **miniRT,
						float *distance);
t_node_object		*intersected_obj(t_ray *ray, t_node_object *object,
						float *min_distance);
unsigned int		trace_ray(t_ray *ray, t_miniRT **miniRT);
void				prep_row_pixel(t_miniRT **miniRT, int row, int col);
t_vector			c_v(t_vector vector);
t_vector			create_vector(float x, float y, float z, float w);
t_vector			get_viewport_point(t_camera *camera, int row, int col,
						mlx_image_t *image);
t_vector			vector_normalize(t_vector a);
t_ray				create_ray(t_miniRT **miniRT, int row, int col);
int					hit_distance(float point_1, float point_2,
						float *min_distance);
float				discriminant(t_ray *ray, t_sphere *sphere, float *b,
						float *c);
int					eq_quadratic(float b, float *point_1, float *point_2,
						float discrim);
int					valid_hit(t_ray *ray, t_cylnd_dto *dto, int flag);
int					hit_cyld_body(t_ray *ray, t_cylnd_dto *dto);
int					intersect_disk_radius(t_ray *ray, t_cylnd_dto *dto,
						int flag);
void				check_hit(t_ray *ray, t_cylnd_dto *dto);
int					solve_quadratic_cyld(t_cylnd_dto *dto);
void				main_cal_hit_check(t_ray *ray, t_cylnd_dto *dto);
t_node_object		*intersect_cylinder(t_ray *ray, t_node_object *cylnd,
						float *min_distance);

/*---PrintHelper---*/
void				print_sphere(t_sphere *sphere);
void				print_plane(t_plane *plane);
void				print_cylinder(t_cylinder *cylinder);
void				print_objects(t_node_object *objects_head);
void				print_camera(t_camera *camera);
void				print_light(t_light *light);
void				print_ray(t_ray *ray);
void				print_progress_bar(int progress, int total);

/*---PixelColour---*/
unsigned int		pixel_colour(t_node_object *objects, t_ray *ray,
						t_miniRT **miniRT, float distance);
void				map_2d_ptr_to_1d_ptr(t_gc **gc, void **array);
t_vector			ft_intersection_normal(t_node_object *objects,
						t_vector intersection_point);
t_color				create_color(float r, float g, float b);
t_color				ft_object_colour(t_node_object *objects);
t_color				ft_light(t_miniRT **miniRT, t_vector intersection_point,
						t_vector intersection_normal, t_color object_color);
t_color				ft_shadow(t_miniRT **miniRT, t_vector intersection_point,
						t_vector intersection_normal, t_color light);

/*-- event handlers*/
void				ft_camera_hook(void *param);
void				ft_light_hook(void *param);
void				ft_object_hook(void *param);
void				translate_plane(t_node_object *temp, void *param);
void				rotate_plane(t_node_object *temp, void *param);
void				translate_cylinder(t_node_object *temp, void *param);
void				rotate_cylinder(t_node_object *temp, void *param);
void				translate_sphere(t_node_object *temp, void *param);
void				move_object_hook(t_node_object *temp, void *param);
t_node_object		*find_object_by_id(t_node_object *head, int id);

#endif
