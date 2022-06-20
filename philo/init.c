/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:33:16 by nchennaf          #+#    #+#             */
/*   Updated: 2022/06/20 11:53:12 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	need_space(t_philos **phis, int n_phis)
{
	int	i;

	i = 0;
	*phis = (t_philos *)malloc(sizeof(t_philos) * n_phis);
	if (!phis)
		return (errorminator(ERR_MEM));
	//*phis->in
	printf("need_space, avant boucle : [%p]\n", &phis);
	while(i < n_phis)
	{
		phis[i]->in = malloc(sizeof(t_inputs));
		if (!phis[i]->in)
			errorminator(ERR_MEM);
		printf("need_space, dans boucle : [%p]\n", &phis[i]->in);
		i++;
	}
	return (EXIT_SUCCESS);
}
