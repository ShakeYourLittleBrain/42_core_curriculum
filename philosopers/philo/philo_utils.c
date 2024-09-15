/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 06:21:02 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/05 01:30:01 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_philos_forks(int num_of_philos, t_philo_data **philos,
		pthread_mutex_t **forks)
{
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------malloc_philos_forks() \
starts--------\033[0;39m\n");
	*philos = (t_philo_data *)malloc(sizeof(t_philo_data) * num_of_philos);
	if (!*philos)
	{
		print_error_exit("Malloc failed for philosopers\n", 1);
		return (0);
	}
	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_of_philos);
	if (!*forks)
	{
		print_error_exit("Malloc failed for philosopers\n", 1);
		return (0);
	}
	if (DEBUG)
		printf("\033[0;93mDEBUG :----------malloc_philos_forks() \
end--------\033[0;39m\n");
	return (1);
}

int	ft_usleep(size_t milis)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < milis)
		usleep(500);
	return (0);
}

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() function failed\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

char	mutex_destroy_free_all(t_philo_data **philos, pthread_mutex_t **forks,
		int num_of_philo)
{
	int				i;
	t_philo_data	*tem_p;
	pthread_mutex_t	*tem_f;

	i = -1;
	tem_p = *philos;
	tem_f = *forks;
	destroy_global_mutex(tem_p->global_mutex_data);
	while (++i < num_of_philo && (tem_f + i))
		pthread_mutex_destroy((tem_f + i));
	free(tem_f);
	free(tem_p);
	return (' ');
}

void	destroy_global_mutex(t_global_mutex_data *data)
{
	pthread_mutex_destroy(&data->is_dead_lock);
	pthread_mutex_destroy(&data->is_eating_lock);
	pthread_mutex_destroy(&data->is_write_lock);
}
