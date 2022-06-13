/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:14:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/13 10:12:01 by nchennaf         ###   ########.fr       */
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

	check_args(argc, argv, &args);
	args_manager(&args, argc, argv);
	printf("atoi[%d]\n", args.number_of_philosophers);


	return (0);
}
