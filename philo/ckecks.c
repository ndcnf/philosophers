/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckecks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:57:12 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/12 16:45:18 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	errorminator(char *s)
{
	ft_putstr(s);
	ft_putstr("\n");
	exit (EXIT_FAILURE);
}

int	check_args(int argc, char *argv[], t_inputs *args)
{
	int	i;

	i = 1;
	if (argc != 5 || argc != 6)
		errorminator(ERR_ARGS);
	//while (i <= argc)
		//checker les valeurs des arguments ici
}
