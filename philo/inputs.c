/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 15:40:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_manager(t_philos *phis, int argc, char *argv[])
{
	phis->in->number_of_philosophers = ft_atoi(argv[1]);
	phis->in->time_to_die = ft_atoi(argv[2]);
	phis->in->time_to_eat = ft_atoi(argv[3]);
	phis->in->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		phis->in->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

void	*philo_starter_pack(void *arg)
{
	// pthread_t	phi;
	(void)arg;
	while (1)
	{
		usleep(100);
		printf("Marco ?\n");
	}
	return (NULL);
}
