/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/15 16:17:43 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philos	*phis;

	phis = NULL;
	check_args(argc, argv);
	need_space(phis, ft_atoi(argv[1]));
	// args_manager(&phis, argc, argv);

	// pthread_create(&phis.phi, NULL, philo_starter_pack, (void *)&phis);
	// while (1)
	// {
	// 	usleep(200);
	// 	printf("Polo !\n");
	// }
	// time_usec();

	return (EXIT_SUCCESS);
}
