/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:57:12 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/13 11:21:50 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errorminator(char *s)
{
	ft_putstr(ERROR);
	ft_putstr(s);
	exit (EXIT_FAILURE);
}

void	check_args(int argc, char *argv[], t_inputs *args)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		errorminator(ERR_ARGS);
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
	args_manager(args, argc, argv);
}
