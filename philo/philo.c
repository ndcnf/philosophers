/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/27 17:38:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

////////////TEST DU MUTEX/////////////////////////////////////////////////////
// void	*routine_du_mutex(t_philos *phis)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 100000)
// 	{
// 		pthread_mutex_lock(&in->fork[i]);
// 		//DO SOMETHING COOL
// 		printf("I just did something cool here [%d]\n", i);
// 		pthread_mutex_unlock(&in->fork[i]);
// 		i++;
// 	}
// 	return (NULL);
// }
//////////////////////////////////////////////////////////////////////////////

int	main(int argc, char *argv[])
{
	t_philos	*phis;
	int			i;

	phis = NULL;
	i = 0;
	if (check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (need_space(&phis, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (philo_starter_pack(&phis) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	//VERIFIER ETAT DES PHILOS
	while (i < phis->in->number_of_philosophers)
	{
		printf("%d ate %d MEALS\n", phis[i].id, phis[i].meals_nbr);
		i++;
	}

// ////////////TEST DU MUTEX/////////////////////////////////////////////////////
// 	pthread_mutex_init(&phis->fork, NULL); //TESTER
// 	routine_du_mutex(phis);

////////////TEST DE CREATION DE THREAD////////////////////////////////////////
	// pthread_create(&phis.phi, NULL, the_routine, (void *)&phis);
	// while (1)
	// {
	// 	usleep(200);
	// 	printf("Polo !\n");
	// }

////////////TEST DU MUTEX/////////////////////////////////////////////////////
	// pthread_mutex_destroy(&phis->fork);

////////////TEST DU TEMPS/////////////////////////////////////////////////////
	// time_usec();

	return (EXIT_SUCCESS);
}
