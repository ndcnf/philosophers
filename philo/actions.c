/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:02 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/27 17:33:41 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		eat_something(t_philos *phi)
{
	pthread_mutex_lock(&phi->in->fork[phi->id]);
	printf("this is MY fork [%d]\n", phi->id);
	pthread_mutex_lock(&phi->in->fork[phi->neighbour]);
	printf("I borrow YOUR fork [%d]\n", phi->neighbour);
	printf("now I[%d] can eat\n", phi->id);
	phi->meals_nbr++;
	printf("I[%d] ate %d time yet\n", phi->id, phi->meals_nbr);

	if (phi->id % 2)
		please_wait();

	pthread_mutex_unlock(&phi->in->fork[phi->neighbour]);
	pthread_mutex_unlock(&phi->in->fork[phi->id]);

	//NOTION DU TEMPS A AJOUTER SINON OK




	// 	while (i < phi->in->time_to_eat)
	// 	{

	// 	}
	return (EXIT_SUCCESS);
}

int		please_wait()
{
	int wait;
	// wait = phi->in->time_to_eat;
	wait = 100;
	// while (wait)
	// {
	// 	wait = (wait / 5);
	// 	printf("WAIT [%d]!\n", wait);
		usleep(wait);
	// }
	return (EXIT_SUCCESS);
}

// int		go_to_sleep(t_philos *phi)
// {

// }
