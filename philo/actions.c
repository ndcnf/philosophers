/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:02 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 13:18:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		eat_something(t_philos *phi)
{
	pthread_mutex_lock(&phi->in->fork[phi->id]);
	printf("%*ld %d " S_FK, 7, time_usec() - phi->in->t_sim_start, phi->id);
	if (phi->in->number_of_philosophers < 2)
	{
		printf("%*ld %d " S_ALONE, 7, time_usec() - phi->in->t_sim_start, phi->id);
		pthread_mutex_unlock(&phi->in->fork[phi->id]);
		return(EXIT_FAILURE);
	}
	pthread_mutex_lock(&phi->in->fork[phi->neighbour]);
	printf("%*ld %d " S_FK, 7, time_usec() - phi->in->t_sim_start, phi->id);
	printf("%*ld %d " S_EAT, 7, time_usec() - phi->in->t_sim_start, phi->id);
	if (phi->last_meal > phi->in->time_to_eat)
	{
		printf("[%d]I might be dead\n", phi->id);
		phi->status = DEAD;
		return(EXIT_FAILURE);
	}
	phi->meals_nbr++;
	phi->last_meal = 0;
	printf("[%d] ate %d time yet\n", phi->id, phi->meals_nbr);
	please_wait(phi, phi->in->time_to_eat);
	pthread_mutex_unlock(&phi->in->fork[phi->neighbour]);
	pthread_mutex_unlock(&phi->in->fork[phi->id]);
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
