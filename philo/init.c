/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/20 13:56:49 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	need_space(t_philos **phis, int argc, char *argv[])
{
	int			i;
	t_inputs	*tempura;
	int			n_phis;

	tempura = 0;
	i = 0;
	n_phis = ft_atoi(argv[1]);
	*phis = (t_philos *)malloc(sizeof(t_philos) * n_phis);
	if (!*phis)
		return (errorminator(ERR_MEM));
	printf("need_space, avant boucle : [%p]\n", *phis);
	tempura = malloc(sizeof(t_inputs));
	if (!tempura)
		return (errorminator(ERR_MEM));
	args_manager((phis, argc, argv); //REGLER CE PROBLEME D'APPEL DE FONCTION
	while(i < n_phis)
	{
		(*phis)[i].in = tempura;
		printf("need_space, dans boucle : [%p]\n", (*phis)[i].in);
		i++;
	}
	return (EXIT_SUCCESS);
}
