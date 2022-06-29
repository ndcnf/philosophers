/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:02 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 19:47:35 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_something(t_philos *phi)
{
	pthread_mutex_lock(&phi->in->fork[phi->id]);
	if (phi->in->status == ALIVE)
		printf("%*ld %d " S_FK, 7, timelord() - phi->in->t_sim, phi->id);
	pthread_mutex_lock(&phi->in->fork[phi->neighbour]);
	printf("%*ld %d " S_FK, 7, timelord() - phi->in->t_sim, phi->id);
	printf("%*ld %d " S_EAT, 7, timelord() - phi->in->t_sim, phi->id);
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
