/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 05:17:48 by skhastag          #+#    #+#             */
/*   Updated: 2024/06/05 01:29:20 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo_input_data	philo_in_d;
	t_global_mutex_data	global_mx_d;
	t_philo_data		*philos;
	pthread_mutex_t		*forks;

	philos = NULL;
	forks = NULL;
	if (DEBUG)
		printf("\033[0;93mDEBUG :main() program starts\033[0;39m\n");
	if (!check_input_data(argc, argv))
		return (EXIT_FAILURE);
	init_philo_input_data(&philo_in_d, argv);
	if (!malloc_philos_forks(philo_in_d.number_of_philosophers, &philos,
			&forks))
		return (EXIT_FAILURE);
	init_global_mutex_data(&global_mx_d, &philos);
	init_forks(&forks, argv);
	init_philos(&philos, &global_mx_d, &forks, philo_in_d);
	init_program(&philos, &forks, philo_in_d.number_of_philosophers);
	(void)mutex_destroy_free_all(&philos, &forks,
		philo_in_d.number_of_philosophers);
	if (DEBUG)
		printf("\033[0;93mDEBUG :main() program ends\033[0;39m\n");
	return (EXIT_SUCCESS);
}
