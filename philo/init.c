/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 11:47:07 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	need_space(t_philos *phis)
{
	phis = malloc(sizeof(t_philos) * phis->in->number_of_philosophers);
		if (!phis)
			errorminator(ERR_MEM);
	// phis = malloc(sizeof(t_philo));
	// 	if (!phis)
	// 		errorminator(ERR_MEM);
}

void	init_args(t_inputs *args)
{
	args->number_of_philosophers = INIT;
	args->time_to_die = INIT;
	args->time_to_eat = INIT;
	args->time_to_sleep = INIT;
	args->number_of_times_each_philosopher_must_eat = INIT;
}

void	init_sim(t_philos *phis)
{
	phis->id = INIT;
	phis->meals_nbr = INIT;
	phis->status = INIT;
	phis->last_meal = INIT;
}
