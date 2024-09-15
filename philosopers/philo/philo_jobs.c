/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:38:27 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/19 23:26:49 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo_data *philo)
{
	pthread_mutex_lock(&philo->global_mutex_data->is_dead_lock);
	if (philo->global_mutex_data->is_dead)
		return (pthread_mutex_unlock(&philo->global_mutex_data->is_dead_lock),
			1);
	pthread_mutex_unlock(&philo->global_mutex_data->is_dead_lock);
	return (0);
}

void	*ph_jobs(void *arg)
{
	t_philo_data	*philo;

	philo = (t_philo_data *)arg;
	if (!(philo->philo_id % 2))
	{
		ph_think(philo);
		ft_usleep(1);
	}
	while (!is_dead(philo))
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (arg);
}

void	ph_eat(t_philo_data *ph)
{
	pthread_mutex_lock(ph->right_fork);
	info_philo(ph, "has taken a fork");
	if (ph->philo_init_data.number_of_philosophers == 1)
		return (ft_usleep(ph->philo_init_data.time_to_die),
			pthread_mutex_unlock(ph->left_fork), (void)"");
	pthread_mutex_lock(ph->left_fork);
	info_philo(ph, "has taken a fork");
	ph->num_eating = 1;
	info_philo(ph, "is eating");
	pthread_mutex_lock(&ph->global_mutex_data->is_eating_lock);
	ph->latest_meal = ft_get_time();
	ph->total_num_time_eaten++;
	pthread_mutex_unlock(&ph->global_mutex_data->is_eating_lock);
	ft_usleep(ph->philo_init_data.time_to_eat);
	ph->num_eating = 0;
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}

void	ph_sleep(t_philo_data *ph)
{
	info_philo(ph, "is sleeping");
	ft_usleep(ph->philo_init_data.time_to_sleep);
}

void	ph_think(t_philo_data *ph)
{
	info_philo(ph, "is thinking");
}
