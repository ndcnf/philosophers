/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 14:52:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	need_space(t_philos *phis)
{
	phis->in = malloc(sizeof(t_inputs));
	// phis = malloc(sizeof(t_philos) * phis->in->number_of_philosophers);
	// 	if (!phis)
	// 		errorminator(ERR_MEM);
}

void	init_args(t_philos *phis)
{
	// phis->in = malloc(sizeof(t_inputs));
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
