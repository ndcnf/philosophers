/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 19:30:17 by nchennaf         ###   ########.fr       */
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
	printf("The simulation is complete. Return to your life now.\n");
	free_minds(&phis);
	return (EXIT_SUCCESS);
}
