/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_ft_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:05:50 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/14 22:30:57 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo_input_data(t_philo_input_data *pid, char *argv[])
{
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_philo_input_data() \
starts--------\033[0;39m\n");
	pid->number_of_philosophers = ft_atol(argv[1]);
	pid->time_to_die = ft_atol(argv[2]);
	pid->time_to_eat = ft_atol(argv[3]);
	pid->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		pid->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	else
		pid->number_of_times_each_philosopher_must_eat = -1;
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_philo_input_data() \
end--------\033[0;39m\n");
}

void	init_global_mutex_data(t_global_mutex_data *gmd, t_philo_data **philos)
{
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_global_mutex_data() \
starts--------\033[0;39m\n");
	gmd->is_dead = 0;
	gmd->philos = *philos;
	pthread_mutex_init(&gmd->is_dead_lock, NULL);
	pthread_mutex_init(&gmd->is_eating_lock, NULL);
	pthread_mutex_init(&gmd->is_write_lock, NULL);
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_global_mutex_data() \
end--------\033[0;39m\n");
}

void	init_forks(pthread_mutex_t **forks, char *argv[])
{
	int				i;
	pthread_mutex_t	*temp_forks;

	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_forks() \
starts--------\033[0;39m\n");
	i = -1;
	temp_forks = *forks;
	while (++i < ft_atol(argv[1]))
		pthread_mutex_init((temp_forks + i), NULL);
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_forks() \
end--------\033[0;39m\n");
}

void	init_philos(t_philo_data **philos, t_global_mutex_data *gmd,
		pthread_mutex_t **forks, t_philo_input_data pdt)
{
	int	i;

	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_philos() \
starts--------\033[0;39m\n");
	i = -1;
	while (++i < pdt.number_of_philosophers)
	{
		(*philos + i)->philo_id = i + 1;
		(*philos + i)->num_eating = 0;
		(*philos + i)->total_num_time_eaten = 0;
		(*philos + i)->latest_meal = ft_get_time();
		(*philos + i)->init_time = ft_get_time();
		(*philos + i)->global_mutex_data = gmd;
		(*philos + i)->philo_init_data = pdt;
		(*philos + i)->left_fork = (*forks + i);
		if (!i)
			(*philos + i)->right_fork = (*forks + (pdt.number_of_philosophers
						- 1));
		else
			(*philos + i)->right_fork = (*forks + (i - 1));
	}
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------init_philos() \
end--------\033[0;39m\n");
}
