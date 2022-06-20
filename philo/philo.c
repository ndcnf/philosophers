/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/20 19:03:01 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

////////////TEST DU MUTEX/////////////////////////////////////////////////////
void	*routine_du_mutex(t_philos *phis)
{
	int	i;

	i = 0;
	while (i < 100000)
	{
		pthread_mutex_lock(&phis->fork);
		//DO SOMETHING COOL
		printf("I just did something cool here [%d]\n", i);
		pthread_mutex_unlock(&phis->fork);
		i++;
	}
	return (NULL);
}
//////////////////////////////////////////////////////////////////////////////

int	main(int argc, char *argv[])
{
	t_philos	*phis;
	int			i;
	int			n_phis; //peut-etre en trop, a voir

	phis = NULL;
	n_phis = 0;
	i = 0;
	if (check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//n_phis = ft_atoi(argv[1]); // utile peut-etre, mais pas ici
	if (need_space(&phis, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo_starter_pack(&phis);

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
