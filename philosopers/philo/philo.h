/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:52:51 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/05 01:28:29 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo_input	t_philo_input_data;
typedef struct s_global_mutex	t_global_mutex_data;
typedef struct s_philo_data		t_philo_data;

# define DEBUG 0

# define ERR \
	"\n  \033[53m\033[4m\033[7;7;5mFormat should be like this\033[0m\n\n \
|\033[0;91m\033[1m\033[53m\033[4m<./<name_program> \
\033[0;93m\033[1m\033[53m\033[4m<number_of_philosophers(positive int)> \
\033[38;5;214m\033[1m\033[53m\033[4m<time_to_die(positive int)> \
\033[0;95m\033[1m\033[53m\033[4m<time_to_eat(positive int)> \
\033[0;96m\033[1m\033[53m\033[4m<time_to_sleep(positive int)> \
\033[0;91m\033[1m\033[53m\033[4m[optional]<number_of_times_each_philosopher_must_eat(positive int)> \
\033[0;39m\033[0m|\n\n \
|\033[53m\033[4mEx: ./philo 10 500 200 200 [7]\033[0;39m|\n\n"

# define ERR_ARG_1 \
	"\n  \033[53m\033[4m\033[7;7;5mInvalid \
number_of_philosophers\033[0m\n"
# define ERR_ARG_2 "\n  \033[53m\033[4m\033[7;7;5mInvalid time_to_die\033[0m\n"
# define ERR_ARG_3 "\n  \033[53m\033[4m\033[7;7;5mInvalid time_to_eat\033[0m\n"
# define ERR_ARG_4 \
	"\n  \033[53m\033[4m\033[7;7;5mInvalid \
time_to_sleep\033[0m\n"
# define ERR_ARG_5 \
	"\n  \033[53m\033[4m\033[7;7;5mInvalid \
number_of_times_each_philosopher_must_eat\033[0m\n"

int								main(int argc, char *argv[]);
int								malloc_philos_forks(int num_of_philos,
									t_philo_data **philos,
									pthread_mutex_t **forks);
void							init_global_mutex_data(t_global_mutex_data *gmd,
									t_philo_data **philos);
void							init_philo_input_data(t_philo_input_data *pid,
									char *argv[]);
void							init_forks(pthread_mutex_t **forks,
									char *argv[]);
void							init_philos(t_philo_data **philos,
									t_global_mutex_data *gmd,
									pthread_mutex_t **forks,
									t_philo_input_data philo_input_data);
void							*ph_jobs(void *arg);
void							*patrolling(void *arg);
int								is_dead(t_philo_data *philo);
void							ph_eat(t_philo_data *ph);
void							ph_sleep(t_philo_data *ph);
void							ph_think(t_philo_data *ph);
int								report_dead(t_philo_data *ph);
int								philo_dead(t_philo_data *ph,
									size_t time_to_die);
int								report_finished_eat(t_philo_data *ph);

/*these are ft for input errors*/
void							print_error_exit(char *s, int flag);
int								check_input_data(int argc, char *argv[]);
char							*get_error_string(int i);

/*these are utils ft for error check*/
int								is_digit(char *str);
int								is_in_int_range(char *str);
int								is_integer(char *argv);
int								ft_check_sign(char *str, int *index);
int								ft_check_space(int ch);
long							ft_atol(char *str);
int								ft_check_digit(int ch);
size_t							ft_get_time(void);
int								ft_usleep(size_t milis);

void							init_program(t_philo_data **philos,
									pthread_mutex_t **forks, int nop);
char							mutex_destroy_free_all(t_philo_data **philos,
									pthread_mutex_t **forks, int num_of_philo);
void							destroy_global_mutex(t_global_mutex_data *data);

typedef struct s_philo_input
{
	int							number_of_philosophers;
	size_t						time_to_die;
	size_t						time_to_eat;
	size_t						time_to_sleep;
	int							number_of_times_each_philosopher_must_eat;
}								t_philo_input_data;

typedef struct s_global_mutex
{
	int							is_dead;
	pthread_mutex_t				is_dead_lock;
	pthread_mutex_t				is_eating_lock;
	pthread_mutex_t				is_write_lock;
	t_philo_data				*philos;
}								t_global_mutex_data;

typedef struct s_philo_data
{
	int							philo_id;
	int							num_eating;
	int							total_num_time_eaten;
	size_t						latest_meal;
	size_t						init_time;
	pthread_t					philo;
	t_philo_input_data			philo_init_data;
	t_global_mutex_data			*global_mutex_data;
	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;
}								t_philo_data;

// debug printing ft
void							p_ph_i_d(t_philo_input_data input_data);
void							p_p_data_2d(t_philo_data **data, int len);
void							p_p_data(t_philo_data data);
void							p_g_m_data(t_global_mutex_data *data);
void							info_philo(t_philo_data *ph, char *str);
#endif
