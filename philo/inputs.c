/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 19:06:47 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_manager(t_inputs *in, int argc, char *argv[])
{
	in->n_philos = ft_atoi(argv[1]);
	in->t_to_die = ft_atoi(argv[2]);
	in->t_to_eat = ft_atoi(argv[3]);
	in->t_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		in->n_meals = ft_atoi(argv[5]);
	else
		in->n_meals = FREE_BUFFET;
	// in->undertaker = ALIVE;
}

int		philo_starter_pack(t_philos **phis)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = (*phis)->in->n_philos;
	(*phis)->in->t_sim = timelord();
	while (i < nbr)
	{
		if (pthread_mutex_init(&(*phis)->in->fork[i], NULL))
			return (errorminator(ERR_THD));
		(*phis)[i].id = i;
		init_philo(&(*phis)[i]);
		if (pthread_create(&(*phis)[i].phi, NULL, the_routine, &(*phis)[i])) //AVANT (void *)&(*phis)[i] mais trop long. IDEM ?
			return (errorminator(ERR_THD));
		// if((*phis)[i].status == DEAD)
		// {
		// 	pthread_join((*phis)[i].phi, NULL);
		// 	printf("%*ld %d " "is JOINING a cult, again.\n", 7, timelord() - (*phis)->in->t_sim, i);
		// 	return(EXIT_FAILURE);
		// }
		i++;
	}
	if(pthread_create(&(*phis)->in->undertaker, NULL, surprise_ur_dead, *phis))
		return (errorminator(ERR_THD));

	i = 0;
	while (i < nbr)
	{
		pthread_join((*phis)[i].phi, NULL);
		// printf("[%d] joined a cult\n", i);
		i++;
	}
	pthread_join((*phis)->in->undertaker, NULL);
	return (EXIT_SUCCESS);
}

void	*the_routine(void *arg)
{
	t_philos	*phi;

	phi = (t_philos *)arg; //Est-ce que c'est un peu plus juste en castant le type attendu?
	// phi->in->t_sim = timelord();
	if (phi->id % 2)
		please_wait(phi, (phi->in->t_to_eat));
	if (phi->in->n_philos < 2)
	{
		printf("%*ld %d " S_FK, 7, timelord() - phi->in->t_sim, phi->id);
		please_wait(phi, phi->in->t_to_die + 1);
	//	printf("%*ld %d " S_RIP1, 7, timelord() - phi->in->t_sim, phi->id);
		return(NULL);
	}
	while ((phi->meals_nbr < phi->in->n_meals ||
			phi->in->n_meals == FREE_BUFFET) && phi->in->status == ALIVE)
	{
		// if (phi->last_meal > phi->in->t_to_eat)
		// {
		// 	// phi->in->undertaker = DEAD;
		// 	pthread_join(phi->phi, NULL); // alors ?
		// 	// printf("[%d] joined a NEW cult\n", phi->id);
		// 	return(NULL);
		// }
		if(eat_something(phi))
			return(NULL);
		if (phi->in->status == DEAD)
			return (NULL);
		printf("%*ld %d " S_SLP, 7, timelord() - phi->in->t_sim, phi->id);
		please_wait(phi, phi->in->t_to_sleep);
		if (phi->in->status == DEAD)
			return (NULL);
		printf("%*ld %d " S_THK, 7, timelord() - phi->in->t_sim, phi->id);
	}
	// printf("[%d] is free from the simulation\n", phi->id);
	return (NULL);
}

void	*surprise_ur_dead(void *arg)
{
	t_philos	*phi;
	size_t		ago;
	int			i;

	phi = (t_philos *)arg;
	while (phi->in->status == ALIVE && ((phi->meals_nbr < phi->in->n_meals) ||
			phi->in->n_meals == FREE_BUFFET))
	{
		i = 0;
		while (i < phi->in->n_philos)
		{
			ago = (timelord() - phi[i].in->t_sim) - phi->last_meal;
			// printf("AGO{%zu}\n", ago);
				// ago = timelord() - phi->last_meal;
			if (ago > (size_t)phi[i].in->t_to_die)
			{
				// printf("[%d] ago[%zu] sim[%ld]\n", phi[i].last_meal, ago, phi[i].in->t_sim);
				phi[i].in->status = DEAD;
				printf("%*ld %d " S_RIP, 7, timelord() - phi[i].in->t_sim, phi[i].id);
				return (NULL);
			}
			i++;
		}
	}
	// printf("%*ld %d " S_RIP, 7, timelord() - phi->in->t_sim, phi->id);
	return (NULL);
}
