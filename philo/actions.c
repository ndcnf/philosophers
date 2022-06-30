/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:02 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/30 14:59:51 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_something(t_philos *phi)
{
	pthread_mutex_lock(&phi->in->fork[phi->id]);
	if (phi->in->status == DEAD)
		return (EXIT_FAILURE);
	message(phi, S_FK);
	pthread_mutex_lock(&phi->in->fork[phi->neighbour]);
	if (phi->in->status == DEAD)
		return (EXIT_FAILURE);
	message(phi, S_FK);
	if (phi->in->status == DEAD)
		return (EXIT_FAILURE);
	message(phi, S_EAT);
	phi->last_meal = timelord() - phi->in->t_sim;
	phi->meals_nbr++;
	please_wait(phi, phi->in->t_to_eat);
	pthread_mutex_unlock(&phi->in->fork[phi->neighbour]);
	pthread_mutex_unlock(&phi->in->fork[phi->id]);
	return (EXIT_SUCCESS);
}

int	please_wait(t_philos *phi, size_t future_t)
{
	size_t	past_t;

	past_t = timelord();
	while (phi->in->status == ALIVE)
	{
		if ((timelord() - past_t) >= future_t)
			break ;
		usleep(100);
	}
	return (EXIT_SUCCESS);
}
