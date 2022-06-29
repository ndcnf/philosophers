/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:57:12 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/29 19:43:58 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	errorminator(char *s)
{
	ft_putstr(ERROR);
	ft_putstr(s);
	return (EXIT_FAILURE);
}

int	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
		return (errorminator(ERR_ARGS));
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]))
			return (errorminator(ERR_TYPE));
		else if (ft_atoi(argv[i]) > INT_MAX)
			return (errorminator(ERR_TYPE));
		else if (ft_atoi(argv[i]) < 0)
			return (errorminator(ERR_TYPE));
		i++;
	}
	return (EXIT_SUCCESS);
}

void	free_minds(t_philos **phis)
{
	int	i;

	i = 0;

	while (i < (*phis)->in->n_philos)
	{
		pthread_mutex_destroy((*phis)[i].in->fork);
		i++;
	}
	free((*phis)->in->fork);
	free((*phis)->in);
	free(*phis);
}
