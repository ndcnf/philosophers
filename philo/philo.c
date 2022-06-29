/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 13:24:15 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philos	*phis;
	int			i;

	phis = NULL;
	i = 0;
	if (check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (need_space(&phis, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (philo_starter_pack(&phis) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	// //VERIFIER ETAT DES PHILOS
	// while (i < phis->in->n_philos)
	// {
	// 	time_usec();
	// 	please_wait(&phis[i], 1000);
	// 	printf("%d ate %d MEALS\n", phis[i].id, phis[i].meals_nbr);
	// 	i++;
	// }

////////////TEST DU MUTEX/////////////////////////////////////////////////////
	// pthread_mutex_destroy(&phis->fork);

	return (EXIT_SUCCESS);
}
