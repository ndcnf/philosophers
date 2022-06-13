/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/13 13:35:22 by nchennaf         ###   ########.fr       */
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
	t_philo		phi; //needs more reflexion, see exam 03

	init_args(&args);
	init_sim(&phi); //not sure
	check_args(argc, argv, &args);

	return (0);
}
