/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 16:17:20 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	need_space(t_philos *phis, int n_phis)
{
	int	i;

	i = 0;
	phis = malloc(sizeof(t_philos) * n_phis);
	if (!phis)
		errorminator(ERR_MEM);
	while(i < n_phis)
	{
		phis[i].in = malloc(sizeof(t_inputs));
		if (!phis[i].in)
			errorminator(ERR_MEM);
		init_args(&phis[i]);
		i++;
	}
}

void	init_args(t_philos *phis)
{
	phis->in->number_of_philosophers = INIT;
	phis->in->time_to_die = INIT;
	phis->in->time_to_eat = INIT;
	phis->in->time_to_sleep = INIT;
	phis->in->number_of_times_each_philosopher_must_eat = INIT;
	phis->id = INIT;
	phis->meals_nbr = INIT;
	phis->status = INIT;
	phis->last_meal = INIT;
}
