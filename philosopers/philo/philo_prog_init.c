/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_prog_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:29:38 by skhastag          #+#    #+#             */
/*   Updated: 2024/05/17 01:29:22 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_program(t_philo_data **philos, pthread_mutex_t **forks, int nop)
{
	pthread_t	police;
	int			i;

	i = -1;
	if (pthread_create(&police, NULL, &patrolling, *philos) != 0)
		printf("Creation of police thread failed%c\n",
			mutex_destroy_free_all(philos, forks, nop));
	while (++i < nop)
	{
		if (pthread_create(&(*philos + i)->philo, NULL, &ph_jobs, (*philos
					+ i)) != 0)
			printf("Creation of philo(%d) thread failed%c\n", (*philos
					+ i)->philo_id, mutex_destroy_free_all(philos, forks, nop));
	}
	if (pthread_join(police, NULL) != 0)
		printf("Join of police thread failed%c\n",
			mutex_destroy_free_all(philos, forks, nop));
	i = -1;
	while (++i < nop)
	{
		if (pthread_join((*philos + i)->philo, NULL) != 0)
			printf("Join of philo(%d) thread failed%c\n", (*philos
					+ i)->philo_id, mutex_destroy_free_all(philos, forks, nop));
	}
}
