/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/20 15:41:34 by nchennaf         ###   ########.fr       */
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
	printf("need_space, avant boucle : [%p]\n", *phis);
	in = malloc(sizeof(t_inputs));
	if (!in)
		return (errorminator(ERR_MEM));
	args_manager(in, argc, argv);
	while(i < n_phis)
	{
		(*phis)[i].in = in;
		printf("need_space, dans boucle : [%p]\n", (*phis)[i].in);
		i++;
	}
	return (EXIT_SUCCESS);
}
