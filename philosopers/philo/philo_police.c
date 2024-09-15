/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_police.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:05:14 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/31 11:35:31 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	report_finished_eat(t_philo_data *ph)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (ph->philo_init_data.number_of_times_each_philosopher_must_eat == -1)
		return (0);
	while (++i < ph->philo_init_data.number_of_philosophers)
	{
		pthread_mutex_lock(&(ph + i)->global_mutex_data->is_eating_lock);
		if ((ph + i)->total_num_time_eaten >= (ph
				+ i)->philo_init_data.number_of_times_each_philosopher_must_eat)
			flag++;
		pthread_mutex_unlock(&(ph + i)->global_mutex_data->is_eating_lock);
	}
	if (flag == ph->philo_init_data.number_of_philosophers)
	{
		pthread_mutex_lock(&ph->global_mutex_data->is_dead_lock);
		ph->global_mutex_data->is_dead = 1;
		pthread_mutex_unlock(&ph->global_mutex_data->is_dead_lock);
		return (1);
	}
	return (0);
}

int	philo_dead(t_philo_data *ph, size_t time_to_die)
{
	pthread_mutex_lock(&(ph)->global_mutex_data->is_eating_lock);
	if ((ft_get_time() - ph->latest_meal >= time_to_die) && ph->num_eating == 0)
		return (pthread_mutex_unlock(&(ph)->global_mutex_data->is_eating_lock),
			1);
	pthread_mutex_unlock(&(ph)->global_mutex_data->is_eating_lock);
	return (0);
}

int	report_dead(t_philo_data *ph)
{
	int	i;

	i = -1;
	while (++i < ph->philo_init_data.number_of_philosophers)
	{
		if (philo_dead((ph + i), (ph + i)->philo_init_data.time_to_die))
		{
			info_philo((ph + i), "\033[0;91mdied");
			pthread_mutex_lock(&ph->global_mutex_data->is_dead_lock);
			ph->global_mutex_data->is_dead = 1;
			pthread_mutex_unlock(&ph->global_mutex_data->is_dead_lock);
			return (1);
		}
	}
	return (0);
}

void	*patrolling(void *arg)
{
	t_philo_data	*ph;

	ph = (t_philo_data *)arg;
	while (!report_finished_eat(ph))
	{
		if (report_dead(ph))
			break ;
	}
	return (arg);
}
