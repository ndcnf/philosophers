/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 13:05:01 by nchennaf         ###   ########.fr       */
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
		if (pthread_create(&(*phis)[i].phi, NULL, the_routine, &(*phis)[i])) //AVANT (void *)&(*phis)[i] mais trop long. IDEM ?
			return (errorminator(ERR_THD));
		if((*phis)[i].status == DEAD)
		{
			pthread_join((*phis)[i].phi, NULL);
			return(EXIT_FAILURE);
		}
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

void	*the_routine(void *arg)
{
	t_philos	*phi;

	phi = (t_philos *)arg; //Est-ce que c'est un peu plus juste en castant le type attendu?
	phi->in->t_sim_start = time_usec();
	if (phi->id % 2)
		please_wait(phi, (phi->in->time_to_eat));
	while (phi->meals_nbr < phi->in->nbr_of_meals || phi->in->nbr_of_meals == FREE_BUFFET)
	{
		if(eat_something(phi))
			return(NULL);
		printf("%*ld %d " S_SLP, 7, time_usec() - phi->in->t_sim_start, phi->id);
		please_wait(phi, phi->in->time_to_sleep);
		printf("%*ld %d " S_THK, 7, time_usec() - phi->in->t_sim_start, phi->id);
	}
	printf("[%d] broke the loop\n", phi->id);
	return (NULL);
}
