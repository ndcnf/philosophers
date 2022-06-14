/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:57:12 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/14 10:40:31 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errorminator(char *s)
{
	ft_putstr(ERROR);
	ft_putstr(s);
	exit (EXIT_FAILURE);
}

void	check_args(int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
		errorminator(ERR_ARGS);
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]))
			errorminator(ERR_TYPE);
		else if (ft_atoi(argv[i]) > INT_MAX)
			errorminator(ERR_TYPE);
		else if (ft_atoi(argv[i]) < 0)
			errorminator(ERR_TYPE);
		i++;
	}
}
