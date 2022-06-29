/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:02 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 13:30:44 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		eat_something(t_philos *phi)
{
	pthread_mutex_lock(&phi->in->fork[phi->id]);
	printf("%*ld %d " S_FK, 7, timelord() - phi->in->t_sim_go, phi->id);
	if (phi->in->n_philos < 2)
	{
		printf("%*ld %d " S_RIP1, 7, timelord() - phi->in->t_sim_go, phi->id);
		pthread_mutex_unlock(&phi->in->fork[phi->id]);
		return(EXIT_FAILURE);
	}
	pthread_mutex_lock(&phi->in->fork[phi->neighbour]);
	printf("%*ld %d " S_FK, 7, timelord() - phi->in->t_sim_go, phi->id);
	printf("%*ld %d " S_EAT, 7, timelord() - phi->in->t_sim_go, phi->id);
	if (phi->last_meal > phi->in->t_to_eat)
	{
		printf("[%d]I might be dead\n", phi->id);
		phi->status = DEAD;
		return(EXIT_FAILURE);
	}
	phi->meals_nbr++;
	phi->last_meal = 0;
	printf("[%d] ate %d time yet\n", phi->id, phi->meals_nbr);
	please_wait(phi, phi->in->t_to_eat);
	pthread_mutex_unlock(&phi->in->fork[phi->neighbour]);
	pthread_mutex_unlock(&phi->in->fork[phi->id]);
	return (EXIT_SUCCESS);
}

int		please_wait(t_philos *phi, size_t future_t)
{
	(void)phi;
	size_t past_t;
	past_t = timelord();

	while ((timelord() - past_t) <= future_t)
	{
		usleep(100);
	}
	return (EXIT_SUCCESS);
}
