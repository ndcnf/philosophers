/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/22 16:12:44 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	need_space(t_philos **phis, int argc, char *argv[])
{
	int			i;
	t_inputs	*in;
	int			n_phis;

	in = 0;
	i = 0;
	n_phis = ft_atoi(argv[1]);
	*phis = (t_philos *)malloc(sizeof(t_philos) * n_phis);
	if (!*phis)
		return (errorminator(ERR_MEM));
	in = malloc(sizeof(t_inputs));
	in->fork = malloc(sizeof(pthread_mutex_t) * n_phis);
	if (!in || !in->fork)
		return (errorminator(ERR_MEM));
	args_manager(in, argc, argv);
	while (i < n_phis)
	{
		(*phis)[i].in = in;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_philo(t_philos *phi)
{
	phi->last_meal = 0;
	phi->meals_nbr = 0;
	if (phi->id == (phi->in->number_of_philosophers) - 1)
		phi->neighbour = 0;
	else
		phi->neighbour = (phi->id + 1);
	phi->status = ALIVE;
	phi->action = NOTHING;
}

// int	hello_neighbour(t_philos *phi, t_philos *r_ngbr)
// {
// 	int	i;
// 	int	nbr;

// 	i = 0;
// 	nbr = phi->in->number_of_philosophers - 1;
// 	while (i <= nbr)
// 	if (phi->id == nbr)
// 	{
// 		phi->in->fork[]
// 	}
// 	else
// 		phi->neighbour = (phi->id + 1);
// }
