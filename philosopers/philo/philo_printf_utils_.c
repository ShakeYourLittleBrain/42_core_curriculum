/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_printf_utils_.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:05:51 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/05 01:33:51 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_ph_i_d(t_philo_input_data input_data)
{
	printf("\n<--------t_philo_input_data------------>\n");
	printf("Number of philosophers: %d\n", input_data.number_of_philosophers);
	printf("Time to die: %zu\n", input_data.time_to_die);
	printf("Time to eat: %zu\n", input_data.time_to_eat);
	printf("Time to sleep: %zu\n", input_data.time_to_sleep);
	printf("Number of times each philosopher must eat: %d\n",
		input_data.number_of_times_each_philosopher_must_eat);
	printf("\n<-------------------------------------->\n");
}

void	p_p_data(t_philo_data data)
{
	printf("\n<-----------t_philo_data--------------->\n");
	printf("Philo ID: %d\n", data.philo_id);
	printf("Number of times eating: %d\n", data.num_eating);
	printf("Total time eaten: %d\n", data.total_num_time_eaten);
	printf("Latest meal: %zu\n", data.latest_meal);
	printf("Start time: %zu\n", data.init_time);
	printf("Left fork: %p\n", data.left_fork);
	printf("Right fork: %p\n", data.right_fork);
	p_ph_i_d(data.philo_init_data);
	p_g_m_data(data.global_mutex_data);
	printf("\n<----------t_philo_data end------------->\n");
}

void	p_g_m_data(t_global_mutex_data *data)
{
	printf("\n<----------t_global_mutex_data------------->\n");
	printf("Dead: %p\n", &data);
	printf("Is Dead pnt: %p\n", &data->is_dead);
	printf("Is Dead: %d\n", data->is_dead);
	printf("Is Dead Lock: %p\n", &data->is_dead_lock);
	printf("Is Eating Lock: %p\n", &data->is_eating_lock);
	printf("Is Write Lock: %p\n", &data->is_write_lock);
	printf("Philos: %p\n", data->philos);
	printf("\n<----------t_global_mutex_data end---------->\n");
}

void	p_p_data_2d(t_philo_data **data, int len)
{
	int				i;
	t_philo_data	*tem_p;

	i = -1;
	tem_p = *data;
	while (++i < len)
		p_p_data(*(tem_p + i));
}

void	info_philo(t_philo_data *ph, char *str)
{
	size_t	cal_time;

	pthread_mutex_lock(&ph->global_mutex_data->is_write_lock);
	cal_time = ft_get_time() - ph->init_time;
	if (!is_dead(ph))
	{
		if (DEBUG)
			printf("\033[0;39mPhilosoper:%5d Time:%5zu Msg: %5s\n",
				ph->philo_id, cal_time, str);
		else
			printf("\033[0;92m%zu %d %s\n", cal_time, ph->philo_id, str);
	}
	pthread_mutex_unlock(&ph->global_mutex_data->is_write_lock);
}
