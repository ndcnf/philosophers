/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:02 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/27 18:54:35 by nchennaf         ###   ########.fr       */
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

	please_wait(phi, phi->in->time_to_eat);

	pthread_mutex_unlock(&phi->in->fork[phi->neighbour]);
	pthread_mutex_unlock(&phi->in->fork[phi->id]);

	//NOTION DU TEMPS A AJOUTER SINON OK




	// 	while (i < phi->in->time_to_eat)
	// 	{

	// 	}
	return (EXIT_SUCCESS);
}

int		please_wait(t_philos *phi, size_t future_t)
{
	(void)phi;
	size_t past_t;
	past_t = time_usec();

	while ((time_usec() - past_t) <= future_t)
	{
		usleep(100);
	}
	return (EXIT_SUCCESS);
}

// int		go_to_sleep(t_philos *phi)
// {

// }
