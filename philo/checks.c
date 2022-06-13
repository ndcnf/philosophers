/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:57:12 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/13 10:04:59 by nchennaf         ###   ########.fr       */
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
	(void)argv;
	(void)args;
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		errorminator(ERR_ARGS);
	//while (i <= argc)
		//checker les valeurs des arguments ici
}
