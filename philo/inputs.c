/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:50:51 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/21 15:20:26 by nchennaf         ###   ########.fr       */
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

int		philo_starter_pack(t_philos **phis)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = (*phis)->in->number_of_philosophers;
	while (i < nbr)
	{
		if (pthread_mutex_init(&(*phis)[i].fork, NULL))
			return (errorminator(ERR_THD));
		(*phis)[i].id = i;
		if (pthread_create(&(*phis)[i].phi, NULL, the_routine, &(*phis)[i])) //AVANT (void *)&(*phis)[i] mais trop long. IDEM ?
			return (errorminator(ERR_THD));
		// usleep(100);
		printf("philo_starter_pack, DANS boucle\n\n\n");
		i++;
	}
	//pthread_join((*phis)[i].phi, NULL); // termine le thread avant de continuer -- CORRIGER
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
	printf("ROUTINE, phi id[%d], AVANT boucle\n\n\n", phi->id);

	while (i < 3) // le '3' n'est que pour TESTER, cette valeur n'a AUCUN SENS
	{
		printf("id[%d], their fork[%p]\n", phi->id, &phi->fork);
		printf("ROUTINE, DANS boucle\n");
		i++;
	}
	printf("ROUTINE this one's done, NEXT---------------------------\n\n\n");
	return (NULL);
}
