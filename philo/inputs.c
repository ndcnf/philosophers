/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/07 09:32:42 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_manager(t_inputs *args, int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
	{
		args->number_of_philosophers = ft_atoi(argv[1]);
		args->time_to_die = ft_atoi(argv[2]);
		args->time_to_eat = ft_atoi(argv[3]);
		args->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
		{
			args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
			printf("je me suis permis de ne pas prendre %d en compte\n", args->number_of_times_each_philosopher_must_eat);
		}
	}
	else
	{
		printf("pas le bon nombre d'arguments\n");
		exit(EXIT_FAILURE);
	}
}
