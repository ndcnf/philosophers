/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/14 17:21:14 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	philo_status(t_philo *phl)
{
	t_philo	*tempura;

	while (tempura != NULL)
	{
		printf("Philo num %d\n", tempura->id);
	}
}*/

int	main(int argc, char *argv[])
{
	t_inputs	args;
	t_philos	phis; //needs more reflexion, see exam 03
	t_sporks	fks;

	check_args(argc, argv);
	need_space(&args, &phis, &fks);
	init_args(&args);
	init_sim(&phis, &fks);
	args_manager(&args, argc, argv);


	fork_manager(&args, &fks);

	time_usec();

	return (EXIT_SUCCESS);
}
