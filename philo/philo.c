/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 18:47:52 by nchennaf         ###   ########.fr       */
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
		printf("I just did something cool here [%d]\n", i);
		//DO SOMETHING COOL
		pthread_mutex_unlock(&phis->fork);
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philos	*phis;

	phis = NULL;
	check_args(argc, argv);
	need_space(phis, ft_atoi(argv[1]));
	int	i;

	i = 0;
	printf("[%p]\n", (void *)&phis);
	while (i < ft_atoi(argv[1]))
	{
		printf("[%p]\n", (void *)&phis[i].in);
		i++;
	}
	// args_manager(&phis, argc, argv); //RESOUDRE CE PROBLEME

	////////////TEST DU MUTEX/////////////////////////////////////////////////////
	// pthread_mutex_init(&phis->fork, NULL); //TESTER

	////////////TEST DE CREATION DE THREAD////////////////////////////////////////
	// pthread_create(&phis.phi, NULL, philo_starter_pack, (void *)&phis);
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
