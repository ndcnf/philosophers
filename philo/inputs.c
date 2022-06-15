/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 16:49:25 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_manager(t_philos *phis, int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		printf("[%p]\n", (void *)&phis[i].in);
		phis[i].in->number_of_philosophers = ft_atoi(argv[1]);
		phis[i].in->time_to_die = ft_atoi(argv[2]);
		phis[i].in->time_to_eat = ft_atoi(argv[3]);
		phis[i].in->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			phis[i].in->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		i++;
	}
}

void	*philo_starter_pack(void *arg)
{
	// pthread_t	phi;
	t_philos *phis;

	phis = arg;
	while (1)
	{
		printf("id[%d]\n", phis->in->number_of_philosophers);
		usleep(100);
		printf("Marco ?\n");
	}
	return (NULL);
}
