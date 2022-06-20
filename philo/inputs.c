/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/20 20:31:54 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_manager(t_inputs *in, int argc, char *argv[])
{
	in->number_of_philosophers = ft_atoi(argv[1]);
	in->time_to_die = ft_atoi(argv[2]);
	in->time_to_eat = ft_atoi(argv[3]);
	in->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		in->nbr_of_meals = ft_atoi(argv[5]);
}

void	philo_starter_pack(t_philos **phis)
{
	//t_philos *phi;
	int		nbr;
	int		i;

	i = 0;
	nbr = (*phis)->in->number_of_philosophers;
	while (i < nbr)
	{
		pthread_mutex_init(&(*phis)[i].fork, NULL);
		(*phis)[i].id = i;
		pthread_create(&(*phis)[i].phi, NULL, the_routine, (void *)&(*phis)[i]);

		// usleep(100);
		printf("Polo ?\n");

		i++;
	}
	// printf("starter pack : [%d]\n", i);
	pthread_join((*phis)[0].phi, NULL); // termine le thread avant de continuer
	//return (NULL);
}

void	*the_routine(void *arg)
{
	t_philos	*phi;
	int			i;

	i = 0;
	phi = arg;
	printf("HELLO\n");

	while (i < 3)
	{
		printf("id[%d], nbr[%d]\n", phi->id, phi->in->number_of_philosophers);
		printf("Marco ?\n");
		i++;
	}
	return (NULL);
}
