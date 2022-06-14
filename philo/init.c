/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/14 10:57:37 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	need_space(t_inputs *args, t_philo *phi, t_spork *fk)
{
	args = malloc(sizeof(t_inputs));
		if (!args)
			errorminator(ERR_MEM);
	phi = malloc(sizeof(t_philo));
		if (!phi)
			errorminator(ERR_MEM);
	fk = malloc(sizeof(t_spork));
		if (!fk)
			errorminator(ERR_MEM);
}

void	init_args(t_inputs *args)
{
	args->number_of_philosophers = INIT;
	args->time_to_die = INIT;
	args->time_to_eat = INIT;
	args->time_to_sleep = INIT;
	args->number_of_times_each_philosopher_must_eat = INIT;
}

void	init_sim(t_philo *phi, t_spork *fk)
{
	phi->id = INIT;
	phi->meals_nbr = INIT;
	phi->status = INIT;
	fk->id = INIT;
	fk->status = INIT;
	// phi->fork->status = INIT;
	// phi->fork->id = INIT;
}