/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:52:02 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/27 13:55:44 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		eat_something(t_philos *phi)
{
		pthread_mutex_lock(&phi->in->fork[phi->id]);
		printf("this is MY fork\n");
		pthread_mutex_lock(&phi->in->fork[phi->neighbour]);
		printf("I borrow YOUR fork\n");
		printf("now I can eat\n");
		pthread_mutex_unlock(&phi->in->fork[phi->neighbour]);
		pthread_mutex_unlock(&phi->in->fork[phi->id]);

	//NOTION DU TEMPS A AJOUTER SINON OK



	// int	i;

	// i = 0;

	// while (pthread_mutex_lock(&phi->fork) && pthread_mutex_lock(&phi->fork))
	// {
	// 		printf("j'ai deux fourchettes, yeah\n");
	// 	pthread_mutex_unlock(&phi->fork);
	// }
	// pthread_mutex_unlock(&phi->neighbour->fork);

	// 	while (i < phi->in->time_to_eat)
	// 	{

	// 	}
	return (EXIT_SUCCESS);







}


