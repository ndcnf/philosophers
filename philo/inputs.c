/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/27 17:31:10 by nchennaf         ###   ########.fr       */
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
	else
		in->nbr_of_meals = FREE_BUFFET;
}

int		philo_starter_pack(t_philos **phis)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = (*phis)->in->number_of_philosophers;
	while (i < nbr)
	{
		if (pthread_mutex_init(&(*phis)->in->fork[i], NULL))
			return (errorminator(ERR_THD));
		(*phis)[i].id = i;
		init_philo(&(*phis)[i]);
		// if (i % 2)
		// 	please_wait();
		if (pthread_create(&(*phis)[i].phi, NULL, the_routine, &(*phis)[i])) //AVANT (void *)&(*phis)[i] mais trop long. IDEM ?
			return (errorminator(ERR_THD));
		i++;
	}

	i = 0;
	while (i < nbr)
	{
		pthread_join((*phis)[i].phi, NULL);
		printf("[%d] joined a cult\n", i);
		i++;
	}
	return (EXIT_SUCCESS);
}

// one philo after the other
////////////////////////////
void	*the_routine(void *arg)
{
	t_philos	*phi;
	int			i;

	i = 0;
	phi = (t_philos *)arg; //Est-ce que c'est un peu plus juste en castant le type attendu?

	while (phi->meals_nbr < phi->in->nbr_of_meals)
	{
		if (phi->id % 2)
			please_wait();
		eat_something(phi);
		printf("need some zzzz[%d]\n", phi->id);

		i++;
	}
	printf("[%d] broke the loop\n", phi->id);
	return (NULL);
}
